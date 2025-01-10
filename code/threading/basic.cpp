#include <iostream>
#include <thread>

void print_hello()
{
    std::cout << "Hello from thread!";
}

int main()
{
    std::thread t(print_hello);
    t.join();
    return 0;
}