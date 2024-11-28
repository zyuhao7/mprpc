#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

int main(int argc, char **argv)
{
    // 整个程序启动以后, 想使用 mprpc 框架来使服务调用, 一定需要调用框架的初始化函数.
    MprpcApplication::Init(argc, argv);

    // 演示调用远程过程发布的 Login 方法
    fixbug::UserServiceRpc_Stub stub(new mprpcChannel());
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    fixbug::LoginResponse response;
    // 发起 rpc 方法的调用 同步的 prc 调用过程, mprpcChannel::callMethod
    stub.Login(nullptr, &request, &response, nullptr); // RpcChannel->RcpChannel::callMethod 集中做所有 rpc 方法调用的参数序列化和网络发送
    // 一次 rpc 调用之后, 读取调用结果
    if (0 == response.result().errcode())
    {
        std::cout << "rpc login response success : " << response.success() << std::endl;
    }
    else
    {
        std::cout << "rpc login response error : " << response.result().errmsg() << std::endl;
    }

    // 演示调用远程发布的 prc 方法 register
    fixbug::RegisterRequest req;
    req.set_id(2000);
    req.set_name("mprpc");
    req.set_pwd("66");
    fixbug::RegisterResponse rsp;

    // 以同步的方式发起 rpc 调用请求, 等待响应结果
    stub.Register(nullptr, &req, &rsp, nullptr);

    if (0 == rsp.result().errcode())
    {
        std::cout << "rpc Register response success : " << response.success() << std::endl;
    }
    else
    {
        std::cout << "rpc Register response error : " << response.result().errmsg() << std::endl;
    }
    return 0;
}