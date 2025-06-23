# 分布式集群网络通信框架 - rpc 通信原理

## 技术栈

* 集群和分布式概念与原理
* RPC 远程过程调用原理及其实现
*  protobuf 序列化与反序列化
* ZooKeeper分布式一致性协调服务应用于编程
* muduo 网络库编程
* conf 配置文件读取
* 异步日志
* CMake 构建项目集成编译环境

## 集群和分布式

**集群:** 每一台服务器独立运行一个工程的所有模块。

**分布式：** 一个工程拆分了很多模块，每一个模块独立部署运行在一个服务器主机上，所有服务器协同工 作共同提供服务，每一台服务器称作分布式的一个节点，根据节点的并发要求，对一个节点可以再做节点模块集群部署。



## RPC通信原理

**RPC**（Remote Procedure Call Protocol）远程过程调用协议。

![image](/pic/image.png)

**黄色部分：** 设计 rpc 方法参数的打包和解析，也就是数据的序列化和反序列化，使用protobuf

**绿色部分** ：网络部分，包括寻找rpc服务主机，发起rpc调用请求和响应rpc调用结果，使用muduo网络库和zookeeper服务配置中心



## 环境配置

### 项目代码工程目录

 **bin：** 可执行文件 

 **build：** 项目编译文件

 **lib：** 项目库文件  

 **src：** 源文件 

 **test：** 测试代码

 **example：** 框架代码使用范例

 **CMakeLists.txt：** 顶层的cmake文件 

 **README.md：** 项目自述文件  

 **autobuild.sh：** 一键编译脚本

### muduo网络库编程示例

### CMake构建项目集成编译环境

### 网络 I/O 模型介绍

**accept + read/write**： 不是并发服务器

**accept + fork  -  process-per-connection** : 适合并发连接数不大，计算任务工作量大于 fork开销

**accept + thread  -  thread-per-connection** : 比方案2开销小一点，但是并发造成线程堆积过多

**muduo的设计： reactors in threads  -  one loop per thread** : 方案的特点是 one loop per thread, 有一个 main reactor(I/O)负载 accept 连接，然后把连接分发到某个 sub reactor(Woker), 该连接的所有操作那个 sub reactor 所在的线程中完成，多个连接可能被分配到多个线程中，充分利用CPU

**reactors in process  -  one loop per process**: Nginx网络器的网络模块设计，基于进程设计，采用多个Reactors充当 I/O 进程和工作进程，通过一把 accept锁，完美解决了多个 Reactors的"敬群现象"



## mprpc 框架设计

![mprpc](/pic/mprpc.png)



## Zookeeper 分布式协调服务

### 1. Zookeeper 概述：

Zookeeper 是一个**分布式协调服务**，由 Apache 开源，用于解决分布式系统中的**一致性、配置管理、命名服务、分布式锁**等问题。它的核心设计目标是：

- **高可用性**（HA）
- **强一致性**（CP 系统）
- **简单的树形数据模型**（类似文件系统）

 **核心特性**：

| 特性           | 说明                             |
| :------------- | :------------------------------- |
| **顺序一致性** | 所有请求按顺序执行               |
| **原子性**     | 操作要么成功要么失败，无中间状态 |
| **单一视图**   | 所有客户端看到的数据一致         |
| **高可用**     | 集群中多数节点存活即可服务       |
| **实时性**     | 客户端最终能看到最新数据         |

### 2. Zookeeper 数据模型

Zookeeper 采用**树形命名空间（ZNode）**存储数据，类似文件系统：

```text
/ (根节点)
├── /service
│   ├── /service/api (存储服务地址)
│   └── /service/db
└── /config
    └── /config/database (存储数据库配置)
```

 **ZNode 类型**:

| 类型                       | 说明                       |
| :------------------------- | :------------------------- |
| **持久节点（PERSISTENT）** | 永久存在，需手动删除       |
| **临时节点（EPHEMERAL）**  | 客户端会话结束自动删除     |
| **顺序节点（SEQUENTIAL）** | 节点名自动追加单调递增序号 |

### 3. Zookeeper 核心功能

#### （1) 分布式锁

```java
// 加锁（创建临时顺序节点）
String lockPath = zk.create("/lock/seq-", EPHEMERAL_SEQUENTIAL);
List<String> children = zk.getChildren("/lock", false);
if (isLowestSeqNode(children, lockPath)) {
    // 获取锁
} else {
    // 监听前一个节点
}

// 解锁（删除节点）
zk.delete(lockPath);
```

#### (2) 服务注册与发现

```java
// 服务注册（临时节点）
zk.create("/services/service1", "192.168.1.1:8080".getBytes(), EPHEMERAL);

// 服务发现（监听节点变化）
List<String> services = zk.getChildren("/services", event -> {
    System.out.println("服务列表变化: " + event.getPath());
});
```

#### (3) 配置中心

```java
// 写入配置
zk.setData("/config/db_url", "jdbc:mysql://localhost:3306".getBytes(), -1);

// 监听配置变化
byte[] data = zk.getData("/config/db_url", event -> {
    System.out.println("配置已更新");
}, null);
```

###  4. ZooKeeper 常用命令

| 命令                | 说明         |
| :------------------ | :----------- |
| `create /path data` | 创建节点     |
| `get /path`         | 获取节点数据 |
| `set /path newData` | 更新节点     |
| `delete /path`      | 删除节点     |
| `ls /path`          | 列出子节点   |
| `stat /path`        | 查看节点状态 |
