#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::vector<int> vec = {10, 20, 10, 30, 40, 20, 50};

    std::set<int> unique_elements(vec.begin(), vec.end());

    std::cout << "Unique elements: ";

    for (int ele : unique_elements)
    {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    return 0;
}