#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int counter = 1;

void printOddNumber()
{
    for (int i = 1; i <= 20; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [i]
                { return counter == i; });

        std::cout << "Thread 1: " << i << std::endl;

        counter++;
        cv.notify_one();
    }
}

void printEvenNumbers()
{
    for (int i = 2; i <= 20; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [i]
                { return counter == i; });

        std::cout << "Thread 2: " << i << std::endl;

        counter++;
        cv.notify_one();
    }
}

int main()
{
    std::thread t1(printOddNumber);
    std::thread t2(printEvenNumbers);
    t1.join();
    t2.join();

    return 0;
}