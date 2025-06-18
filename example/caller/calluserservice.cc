#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"
int main(int argc, char **argv)
{
    // 程序启动, 若需要调用 mprpc框架的 rpc服务, 初始化框架.
    MprpcApplication::Init(argc, argv);

    // 调用远程发布的 rpc 方法 Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    fixbug::LoginRequest req;
    req.set_name("myh");
    req.set_pwd("123456");

    fixbug::LoginResponse resp;
    // 同步 rpc 调用过程 MprpcChannel::callmethod
    stub.Login(nullptr, &req, &resp, nullptr);

    // 一次 rpc 调用完成, 读响应
    if (resp.reuslt().errcode() == 0)
    {
        std::cout << "rpc login response :" << resp.success() << std::endl;
    }
    else
    {
        std::cout << "rpc login response error : " << resp.reuslt().errmsg() << std::endl;
    }
    return 0;
}