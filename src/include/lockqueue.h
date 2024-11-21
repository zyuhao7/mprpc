#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

// 异步写日志的日志队列
template <typename T>
class LockQueue
{
public:
    // 多个 worker 线程都会写入 m_q
    void Push(const T &data)
    {
        std::lock_guard<std::mutex> lock(m_mtx);
        m_q.push(data);
        m_cv.notify_one(); // 通知读取日志队列的, 有日记了.
    }

    T Pop()
    {
        std::unique_ptr<std::mutex> lock(m_mtx);
        while (m_q.empty())
        {
            // 日志队列为空, 线程进入 wait
            m_cv.wait(lock);
        }
        T data = m_q.front();
        m_q.pop();
        return data;
    }

private:
    std::queue<T> m_q;
    std::mutex m_mtx;
    std::condition_variable m_cv;
};