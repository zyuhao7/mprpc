#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

int main(int argc, char **argv)
{
    // 整个程序启动以后, 想使用 mprpc 框架来使用服务调用, 一定需要调用框架的初始化函数.
    MprpcApplication::Init(argc, argv);

    // 演示调用远程过程发布的 Login 方法
    fixbug::UserServiceRpc_Stub stub(new mprpcChannel());
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    fixbug::LoginResponse response;
    // 发起 rpc 方法的调用 同步的 prc 调用过程, mprpcChannel::callMethod
    stub.Login(nullptr, &request, &response, nullptr); // RpcChannel->RcpChannel::callMethod 集中做所有 rpc 方法调用的参数序列化和网络发送

    // 一次 rpc 调用之后, 读取调用的结构
    if (0 == response.result().errcode())
    {
        std::cout << "rpc login response: " << response.success() << std::endl;
    }
    else
    {
        std::cout << "rpc login response error : " << response.result().errmsg() << std::endl;
    }
    return 0;
}