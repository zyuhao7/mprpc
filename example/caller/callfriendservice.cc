#include <iostream>
#include "mprpcapplication.h"
#include "mprpcchannel.h"
#include "friend.pb.h"
#include "mprpccontroller.h"
int main(int argc, char **argv)
{
    // 程序启动, 若需要调用 mprpc框架的 rpc服务, 初始化框架.
    MprpcApplication::Init(argc, argv);

    // 调用远程发布的 rpc 方法 Register
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
    fixbug::GetFriendListsRequest req;
    req.set_id(1);

    fixbug::GetFriendListsResponse resp;
    // 同步 rpc 调用过程 MprpcChannel::callmethod
    MprpcController controller;
    stub.Register(&controller, &req, &resp, nullptr);

    // 一次 rpc 调用完成, 读响应
    if (resp.reuslt().errcode() == 0)
    {
        std::cout << "rpc GerFriendsList  response  success!" << std::endl;
        for (int i = 0; i < resp.friends_size(); ++i)
        {
            std::cout << "idx : " << i + 1 << " name: " << resp.friends(i) << std::endl;
        }
    }
    else
    {
        std::cout << "rpc GerFriendsList response error : " << resp.reuslt().errmsg() << std::endl;
    }
    return 0;
}