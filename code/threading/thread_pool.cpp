#include <iostream>
#include <vector>
#include <thread>
#include <functional>

class ThreadPool
{
public:
    ThreadPool(size_t numThread)
    {
        for (size_t i = 0; i < numThread; i++)
        {
            workers.emplace_back(&ThreadPool::worker, this);
        }
    }
    void worker()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Worker thread is working!" << std::endl;
        }
    }

private:
    std::vector<std::thread> workers;
};

int main()
{
    ThreadPool pool(4);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}