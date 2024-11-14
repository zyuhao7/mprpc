#pragma once
#include <memory>
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>

// 框架提供的专门服务发布 rpc 服务的网络对象类
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
    // 新的socket 连接回调.
    void OnConnection(const muduo::net::TcpConnectionPtr &);
    // 已建立连接的读写事件回调.
    void OnMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *buf,
                   muduo::Timestamp);
};