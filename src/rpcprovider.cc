#include "rpcprovider.h"
#include "mprpcapplication.h"

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

    std::cout << "service_name: " << service_name << std::endl;

    for (int i = 0; i < methodCnt; ++i)
    {
        // 获取了服务对象指定下标的服务方法的描述
        const google::protobuf::MethodDescriptor *pmd = pd->method(i);
        std::string method_name = pmd->name();
        std::cout << "method_name: " << method_name << std::endl;
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

void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &)
{
}

void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp)
{
}