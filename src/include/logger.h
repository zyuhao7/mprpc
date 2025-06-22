#pragma once
#include "lockqueue.h"
#include <string>

// 定义日志宏, LOG_INFO("xxx %d %s", 20, "abcs")
#define LOG_INFO(logmsgformat, ...)                     \
    do                                                  \
    {                                                   \
        Logger &logger = Logger::GetInstance();         \
        logger.SetLogLevel(INFO);                       \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

#define LOG_ERROR(logmsgformat, ...)                    \
    do                                                  \
    {                                                   \
        Logger &logger = Logger::GetInstance();         \
        logger.SetLogLevel(ERR);                        \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

// 定义日志级别
enum LogLevel
{
    INFO,
    ERR,
};

// mprpc 框架提供的日志系统
class Logger
{
public:
    // 获取单例日志
    static Logger &GetInstance();
    // 设置日志级别
    void SetLogLevel(LogLevel level);
    // 写日志
    void Log(std::string);

private:
    LogLevel Level;
    LockQueue<std::string> lkQueue;
    Logger();
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
};