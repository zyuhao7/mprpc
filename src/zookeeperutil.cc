#include "zookeeperutil.h"
#include "mprpcapplication.h"
#include <semaphore.h>
#include <string>

// 全局的 watcher观察器 zkServer 给 zkClient的通知
void global_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    if (type == ZOO_SESSION_EVENT) // 回调的消息类型是和会话相关的消息类型
    {
        if (state == ZOO_CONNECTED_STATE) //  zkServer 给 zkClient 存在连接
        {
            sem_t *sem = (sem_t *)zoo_get_context(zh);
            sem_post(sem);
        }
    }
};

ZKClient::ZKClient()
    : _zhandle(nullptr)
{
}

ZKClient::~ZKClient()
{
    if (_zhandle != nullptr)
    {
        zookeeper_close(_zhandle); // 关闭句柄, 释放资源
    }
}

// 连接 zkServer
void ZKClient::Start()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("zookeeperip");
    std::string port = MprpcApplication::GetInstance().GetConfig().Load("zookeeperport");
    std::string conn = ip + ":" + port;
    /*
        zookeeper的 API 提供三个线程
        调用 API线程
        网络IO线程  pthread_create poll
        watcher回调线程 pthread_create
    */
    _zhandle = zookeeper_init(conn.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (nullptr == _zhandle)
    {
        std::cout << "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(_zhandle, &sem);
    sem_wait(&sem);
    std::cout << "zookeeper_init success! " << std::endl;
};

void ZKClient::Create(const char *path, const char *data, int datalen, int state)
{
    char path_buf[128];
    int bufLen = sizeof(path_buf);
    int flag;

    // 1. 判断 path表示的 znode节点是否存在.
    flag = zoo_exists(_zhandle, path, 0, nullptr);
    // 2. 节点不存在.
    if (ZNONODE == flag)
    {
        // 3. 创建指定 path的 znode节点
        flag = zoo_create(_zhandle, path, data, datalen,
                          &ZOO_OPEN_ACL_UNSAFE, state, path_buf, bufLen);
        // 4.创建成功
        if (flag == ZOK)
        {
            std::cout << "znode create success! path: " << path << std::endl;
        }
        else
        {
            std::cout << "flag: " << flag << std::endl;
            std::cout << "znode create error! path: " << path << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

std::string ZKClient::GetData(const char *path)
{
    char buf[64];
    int bufLen = sizeof(buf);
    int flag = zoo_get(_zhandle, path, 0, buf, &bufLen, nullptr);
    if (flag != ZOK)
    {
        std::cout << "get znode error! path: " << path << std::endl;
        return "";
    }
    return buf;
};