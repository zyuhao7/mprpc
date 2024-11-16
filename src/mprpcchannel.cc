#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
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
        std::cout << "serialize request error!" << std::endl;
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
        std::cout << "serialize rpc header error!" << std::endl;
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
    std::cout << "rpc_header_size: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;

    std::cout << "=====================================" << std::endl;

    // 使用 tcp 编程, 完成 rpc 方法的远程调用.
    int clientfd = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == clientfd)
    {
        std::cout << "create socket error ! errno : " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    
}