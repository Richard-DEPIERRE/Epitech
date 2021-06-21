#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include <thread>
#include <vector>
#include "include/Thread_pool.hpp"

class quit_worker_exception : public std::exception {};

void print_function(int i)
{
    std::cout << "Number : " << std::to_string(i) << std::endl;
}

int main()
{
    Thread_pool _pool(5);
    for (int i = 0; i < 42; i++)
    {
        _pool._fpool.push(Thread_pool::print_function, i);
    }
    _pool._fpool.shutdown();
    for (unsigned int i = 0; i < _pool._thread_pool.size(); i++)
    {
        _pool._thread_pool.at(i).join();
    }
}