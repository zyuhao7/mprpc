#include <iostream>
#include <string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout << "do GetFriendList! user id: " << userid << std::endl;
        std::vector<std::string> friends;
        friends.push_back("jacklove");
        friends.push_back("Kanavi");
        friends.push_back("Tarzan");
        return friends;
    }

    void Register(::google::protobuf::RpcController *controller,
                  const ::fixbug::GetFriendListsRequest *request,
                  ::fixbug::GetFriendListsResponse *response,
                  ::google::protobuf::Closure *done)
    {
        // 读请求
        uint32_t id = request->id();
        // 执行服务端方法
        std::vector<std::string> friends = GetFriendsList(id);
        response->mutable_reuslt()->set_errcode(0);
        response->mutable_reuslt()->set_errmsg("");
        // 写响应
        for (std::string &name : friends)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char **argv)
{
    // 框架初始化
    MprpcApplication::Init(argc, argv);

    // provider 是一个 rpc 网络服务对象, 把 UserService 对象发布到 rpc 节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    // 启动一个 rpc 服务发布节点 Run后, 线程进入阻塞状态, 等待远程的 rpc 调用请求
    provider.Run();
    return 0;
}