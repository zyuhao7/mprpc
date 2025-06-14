#pragma once
#include "google/protobuf/service.h"

// 框架提供专门发布 rpc 服务的网络对象类
class RpcProvider
{
public:
    // 框架提供给发布方使用, 可以发布 rpc 方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    // 启动 rpc 服务节点
    void Run();

private:
};