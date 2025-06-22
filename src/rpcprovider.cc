#include "rpcprovider.h"
#include "mprpcapplication.h"
#include "rpcheader.pb.h"
#include "logger.h"
/*
 service_name => service 描述
                          =》 service* 记录服务对象
                         method_name => method 方法对象
*/
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiceInfo service_info;

    // 获取服务的描述信息
    const google::protobuf::ServiceDescriptor *pd = service->GetDescriptor();

    // 获取服务的名字
    std::string service_name = pd->name();

    // 获取服务对象 service的方法数量
    int methodCnt = pd->method_count();

    LOG_INFO("service_name: %s", service_name.c_str());
    for (int i = 0; i < methodCnt; ++i)
    {
        // 获取了服务对象指定下标的服务方法的描述
        const google::protobuf::MethodDescriptor *pmd = pd->method(i);
        std::string method_name = pmd->name();
        LOG_INFO("method_name: %s", method_name.c_str());
        service_info.m_methodMap.insert({method_name, pmd});
    }
    service_info.m_service = service;
    m_serviceMap.insert({service_name, service_info});
}

void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress addr(ip, port);

    // 创建 TcpServer对象
    muduo::net::TcpServer srv(&m_eventLoop, addr, "RpcProvider");

    // 绑定连接回调和消息读写回调方法  分离网络代码和业务代码
    srv.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    srv.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1,
                                     std::placeholders::_2, std::placeholders::_3));
    // 设置muduo库的线程数量
    srv.setThreadNum(4);

    std::cout << "RpcProvider start service at ip : " << ip << "port: " << port << std::endl;
    srv.start();
    m_eventLoop.loop();
}

void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        // 断开与 rpc_client的连接
        conn->shutdown();
    }
}

/*
    在框架内部, RpcProvider 和 RpcConsummer 协商通信的protobuf数据类型
    service_name method_name args
    定义proto的message类型,进行数据头的序列化和反序列化
                            service_name method_name args_size
    header_size + header_str + args_str
*/

void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp)
{
    // 网络接收的远程 rpc请求调用字符流  Login args
    // 从客户端连接读取数据
    std::string recv_buf = buffer->retrieveAllAsString();

    // 读取前四个字节
    uint32_t header_size = 0;
    if (recv_buf.size() < 4)
    {
        std::cout << "Invalid rpc request, buffer size too small!" << std::endl;
        return;
    }
    recv_buf.copy((char *)&header_size, 4, 0);

    // 根据header_size读取数据头的原始字符流,反序列化数据,得到 rpc请求详细信息
    if (recv_buf.size() < 4 + header_size)
    {
        std::cout << "Invalid rpc request, header size mismatch!" << std::endl;
        return;
    }
    std::string rpc_header_str = recv_buf.substr(4, header_size);

    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;

    // 判断能否序反列化成 RpcHeader 结构
    if (rpcHeader.ParseFromString(rpc_header_str))
    {
        // 数据头反序列化成功
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else
    {
        // 失败
        std::cout << "rpc_header_str: " << rpc_header_str << "parse error!" << std::endl;
        return;
    }
    // 获取 rpc 方法参数的字符流数据
    std::string args_str = recv_buf.substr(4 + header_size, args_size);

    // 打印调试信息
    std::cout << "============================================" << std::endl;
    LOG_INFO("header_size: %d", header_size);
    LOG_INFO("rpc_header_str: %s", rpc_header_str.c_str());
    LOG_INFO("service_name: %s", service_name.c_str());
    LOG_INFO("method_name: %s", method_name.c_str());
    std::cout << "============================================" << std::endl;

    //  获取 service对象和method对象
    auto it = m_serviceMap.find(service_name);
    if (it == m_serviceMap.end())
    {
        std::cout << "service_name: " << service_name << " is not exists!" << std::endl;
        return;
    }

    auto methodIt = it->second.m_methodMap.find(method_name);
    if (methodIt == it->second.m_methodMap.end())
    {
        std::cout << service_name << " : " << method_name << "is not exists" << std::endl;
        return;
    }
    google::protobuf::Service *service = it->second.m_service;           // 获取service对象
    const google::protobuf::MethodDescriptor *method = methodIt->second; // 获取method对象

    // 生成 rpc方法调用的请求 request 和响应 response 参数
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args_str))
    {
        std::cout << "request parse error!" << std::endl;
        return;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();

    // 为 CallMethod 提供 Closure的回调函数
    google::protobuf::Closure *done =
        google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr &, google::protobuf::Message *>(this, &RpcProvider::SendRpcResponse, conn, response);

    // 在框架上根据远端 rpc 请求, 调用当前 rpc节点上发布方法
    // new UserService().Login(controller, request, response, done)

    service->CallMethod(method, nullptr, request, response, done);
}

// Closure 的回调函数, 用户序列化 rpc 响应和网络发送
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn, google::protobuf::Message *response)
{
    std::string response_str;
    if (response->SerializeToString(&response_str)) // 序列化响应
    {
        // 序列化成功后,通过网络把 rpc 方法执行的结果发送回rpc的调用方
        conn->send(response_str);
        conn->shutdown(); // 模拟 http的短连接服务, 又服务端主动断开
    }
    else
    {
        std::cout << "serilize response_str error!" << std::endl;
    }
    conn->shutdown(); // 模拟 http的短连接服务, 又服务端主动断开
}