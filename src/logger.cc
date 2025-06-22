#include "logger.h"
#include <time.h>
#include <cstdio>
#include <iostream>
#include <thread>

Logger &Logger::GetInstance()
{
    static Logger log;
    return log;
}

Logger::Logger()
{
    // 写日志线程
    std::thread writeTask([&]()
                          {
        while(1)
        {
            time_t now = time(nullptr);
            tm* nowtm = localtime(&now);
            char file_name[128];
            sprintf(file_name,"%d-%d-%d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

            FILE* fp = fopen(file_name, "a+");
            if(nullptr == fp)
            {
                 std::cout << "logger file : " << file_name << "open error!" << std::endl;
                exit(EXIT_FAILURE);
            }
            std::string msg = lkQueue.Pop();
            char time_buf[128] = {0};
            sprintf(time_buf,"%d:%d:%d => [%s]",
            nowtm->tm_hour,
            nowtm->tm_min,
            nowtm->tm_sec,
            (Level == INFO ? "INFO" : "ERROR"));
            msg.insert(0, time_buf);
            msg.append("\n");
            fputs(msg.c_str(), fp);
            fclose(fp);
        } });

    // 分离写日志线程.
    writeTask.detach();
}

void Logger::SetLogLevel(LogLevel level)
{
    Level = level;
}

void Logger::Log(std::string msg)
{
    lkQueue.Push(msg);
}
