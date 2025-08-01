#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

using namespace fixbug;

/*
    UserService 原来是个本地服务, 提供了两个进程内的本地方法. Login 和GetFriendLists
 */

class UserService : public UserServiceRpc // rpc 服务发布方
{
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "Login doing local service " << std::endl;
        std::cout << "name = " << name << " pwd = " << pwd << std::endl;
        return true;
    }

    // 重写基类 UserServiceRpc 的虚函数, 框架可以直接调用.
    // 1. caller => Login(LoginRequest) => muduo => callee
    // 2. Login(LoginRequst) => callee => 重写的 Login方法

    virtual void Login(::google::protobuf::RpcController *controller,
                       const ::fixbug::LoginRequest *request,
                       ::fixbug::LoginResponse *response,
                       ::google::protobuf::Closure *done)
    {
        // 读请求
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 业务
        bool ret = Login(name, pwd);
<<<<<<< HEAD
        response->set_success(ret);
        // 写响应
        fixbug::ResultCode *code = response->mutable_reuslt();
        code->set_errcode(1);
        code->set_errmsg("hello");
=======

        // 写响应
        fixbug::ResultCode *code = response->mutable_reuslt();
        code->set_errcode(0);
        code->set_errmsg("");
>>>>>>> 8170434c6362341f843761445e7c35deeb0c709c

        // 回传客户端
        done->Run();
    }
};

int main(int argc, char **argv)
{
    // 框架初始化
    MprpcApplication::Init(argc, argv);

    // provider 是一个 rpc 网络服务对象, 把 UserService 对象发布到 rpc 节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());

    // 启动一个 rpc 服务发布节点 Run后, 线程进入阻塞状态, 等待远程的 rpc 调用请求
    provider.Run();
    return 0;
}