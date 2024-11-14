#include "rpcprovider.h"
#include "mprpcapplication.h"
#include <functional>
#include <string>
// 框架提供给发布方使用可以发布 rpc 方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service) {

};

// 启动 rpc 服务节点
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress addr(ip, port);

    // 创建 TcpServer 对象
    muduo::net::TcpServer server(&m_eventLoop, addr, "RpcProvider");

    // 绑定连接回调和消息读写回调 (分离网络代码和业务逻辑)
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置 muduo库的线程数量
    server.setThreadNum(4);
    std::cout << "RpcProvider start service at ip: " << ip << " port: " << port << std::endl;
    // 启动网络服务
    server.start();
    m_eventLoop.loop(); // 启动 epoll wait 等待事件到来
};

// 新的socket 连接回调.

void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{
}

// 已建立连接的读写事件回调.
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *buf,
                            muduo::Timestamp)
{
}