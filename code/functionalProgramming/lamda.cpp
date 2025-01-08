#include <iostream>
#include <functional>

int main()
{
    auto add = [](int a, int b)
    {
        return a + b;
    };

    std::cout << "Sum: " << add(5, 6) << std::endl;

    std::function<int(int, int)> addFun = add;

    std::cout << "Sum (from std::functional): " << addFun(10, 15) << std::endl;

    return 0;
}