#pragma once
#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>

//  zookeeper 客户端类
class ZKClient
{
public:
    ZKClient();
    ~ZKClient();
    // zkclient 启动连接 zkServer
    void Start();
    // 在 zkServer上指定的 path 创建 znode 节点
    void Create(const char *path, const char *data, int datalen, int state = 0);
    // 根据参数指定的 znode节点路径, 获取 znode 节点的值
    std::string GetData(const char *path);

private:
    // zk 客户端句柄
    zhandle_t *_zhandle;
};