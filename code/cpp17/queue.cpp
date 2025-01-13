#include <queue>
#include <iostream>

void print_data(std::queue<int> p)
{
    if (p.empty())
    {
        std::cout << "Queue is empty!." << std::endl;
    }
    else
    {
        std::cout << "Queue is not empty!." << std::endl;
    }

    while (!p.empty())
    {
        std::cout << p.front() << "=>";
        p.pop();
    }
    std::cout << "\n";
}

int main()
{
    std::queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    // pop
    q.pop();
    print_data(q);
    return 0;
}