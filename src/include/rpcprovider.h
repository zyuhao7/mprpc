#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>
#include <functional>
#include <string>
#include <google/protobuf/descriptor.h>
#include <unordered_map>

// 框架提供的专门 发布 rpc 服务的网络对象类
class RpcProvider
{
public:
    // 框架提供给发布方使用, 可以发布 rpc 方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    // 启动 rpc 服务节点
    void Run();

private:
    // 组合 EventLoop
    muduo::net::EventLoop m_eventLoop;

    // service  服务类型信息
    struct ServiceInfo
    {
        google::protobuf::Service *m_service; // 保存服务对象.
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> m_methodMap;
    };

    // 存储注册成功的服务对象和其服务方法的所有信息.
    std::unordered_map<std::string, ServiceInfo> m_serviceMap;

    // 新的socket 连接回调.
    void OnConnection(const muduo::net::TcpConnectionPtr &);
    // 已建立连接的读写事件回调.
    void OnMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);
    // Closure 的回调操作, 用于序列化 rpc 的响应和网络发送
    void sendRpcResponse(const muduo::net::TcpConnectionPtr &, google::protobuf::Message *);
};