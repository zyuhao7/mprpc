#pragma once
#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>

// 异步写日志的日志队列
template <typename T>
class LockQueue
{
public:
    // mutiThread compete
    void Push(const T &val)
    {
        std::lock_guard<std::mutex> lk(_mtx);
        _q.push(val);
        _cv.notify_one(); // 通知读取日志队列线程可以读日志了.
    }

    T Pop()
    {
        std::unique_lock<std::mutex> lk(_mtx);
        while (_q.empty())
        {
            // 日志队列为空, 阻塞等待
            _cv.wait(lk);
        }
        auto t = _q.front();
        _q.pop();
        return t;
    }

private:
    std::queue<T> _q;
    std::mutex _mtx;
    std::condition_variable _cv;
};