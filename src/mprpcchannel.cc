#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include "mprpcapplication.h"
#include "mprpccontroller.h"

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <error.h>
/*
    header_size  + service_name  method_name ars_size + args
*/
void mprpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller,
                              const google::protobuf::Message *request,
                              google::protobuf::Message *response,
                              google::protobuf::Closure *done)
{
    std::cout << "mprpcChannel::CallMethod" << std::endl;
    const google::protobuf::ServiceDescriptor *sd = method->service();
    std::string service_name = sd->name();
    std::string method_name = method->name();

    // 获取参数的序列化字符串长度 args_size
    std::string args_str;
    uint32_t args_size = 0;
    if (request->SerializeToString(&args_str))
    {
        args_size = args_str.size();
    }
    else
    {
        controller->SetFailed("serialize request error!");
        return;
    }

    // 定义 rpc 的请求 header
    mprpc::RcpHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_size(args_size);

    std::string rpc_header_str;
    uint32_t header_size = 0;

    if (rpcHeader.SerializeToString(&rpc_header_str))
    {
        header_size = rpc_header_str.size();
    }
    else
    {
        controller->SetFailed("serialize rpc header error!");
        return;
    }
    // 组织待发送的 rpc 请求的字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0, std::string((char *)&header_size, 4)); // header_size
    send_rpc_str += rpc_header_str;                               // rpcheader
    send_rpc_str += args_str;                                     // args

    // 打印调试信息.
    std::cout << "=====================================" << std::endl;

    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;

    std::cout << "=====================================" << std::endl;

    // 使用 tcp 编程, 完成 rpc 方法的远程调用.
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == clientfd)
    {
        char errtxt[512] = {0};
        sprintf(errtxt, "create socket error ! errno : %d", errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 读取配置文件 rpcserver 的信息
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    // 连接 rpc 服务节点
    if (-1 == connect(clientfd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "connect error! errno : %d", errno);
        controller->SetFailed(errtxt);
        return;
    }

    // 发送 rpc 请求
    if (-1 == send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "send  error! errno : %d", errno);
        controller->SetFailed(errtxt);
        return;
    }

    // 接收 rpc 请求的参数
    char recv_buf[1024] = {0};
    int recv_size = 0;
    recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size == -1)
    {
        // 发生错误
        perror("recv error");
        close(clientfd);
        return;
    }
    else if (recv_size == 0)
    {
        // 对端关闭连接
        std::cout << "Peer has closed the connection." << std::endl;
        close(clientfd); // 关闭本端连接
        return;
    }
    else
    {
        // 正常接收数据
        std::cout << "Received " << recv_size << " bytes: "
                  << std::string(recv_buf, recv_size) << std::endl;
    }
    

// 反序列化 rpc 调用的响应数据
if (!response->ParseFromArray(recv_buf, recv_size))
{
    close(clientfd);
    char errtxt[512] = {0};
    sprintf(errtxt, "parse error! response_str:%s", recv_buf);
    controller->SetFailed(errtxt);
    return;
}
close(clientfd);
}