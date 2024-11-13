#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

using namespace fixbug;

/*
    UserService 原来是个本地服务, 提供了两个进程内的本地方法. Login 和
    GetFriendLists
 */

class UserService : public UserServiceRpc // rpc 服务发布方.
{
public:
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "doing local service Login" << std::endl;
        std::cout << "name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }

    // 重写基类 UserServiceRpc 的虚函数, 框架直接调用.
    //  1. caller  ==> Login(LoginRequest) => muduo => callee
    //  2. callee  ==> Login(LoginRequest) => 重写的Login 方法.

    void Login(::google::protobuf::RpcController *controller,
               const ::fixbug::LoginRequest *request,
               ::fixbug::LoginResponse *response,
               ::google::protobuf::Closure *done)
    {
        // 框架给业务提供了请求参数 LoginRequest, 业务获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 本地业务处理.
        bool login_result = Login(name, pwd);

        // 把响应写入 response
        fixbug::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");

        response->set_success(login_result);

        // 执行回调函数, 执行响应对象的序列化和网络发送(框架实现)
        done->Run();
    }
};

int main(int argc, char **argv)
{
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // provider 是一个 rpc 网络服务网对象, 把 UserService 对象发布到rpc 节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());

    // 启动一个 rpc 服务发布节点 Run以后, 进程进入阻塞状态, 等待远程的 rpc 调用请求
    provider.Run();

    return 0;
}