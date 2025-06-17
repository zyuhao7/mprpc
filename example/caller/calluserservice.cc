#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
int main(int argc, char **argv)
{
    // 程序启动, 若需要调用 mprpc框架的 rpc服务, 初始化框架.
    MprpcApplication::Init(argc, argv);

    // 调用远程发布的 rpc 方法 Login
    // fixbug::UserServiceRpc_Stub stub;
    return 0;
}