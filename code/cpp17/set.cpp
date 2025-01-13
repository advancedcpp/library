
#include <iostream>
#include <set>

int main()
{
    std::set<int> s = {10, 20, 30, 40, 50};

    int search_element = 30;
    if (s.find(search_element) != s.end())
    {
        std::cout << search_element << " is in the set." << std::endl;
    }
    else
    {
        std::cout << search_element << " is not in the set." << std::endl;
    }
    search_element = 60;
    if (s.find(search_element) != s.end())
    {
        std::cout << search_element << " is in the set." << std::endl;
    }
    else
    {
        std::cout << search_element << " is not in the set." << std::endl;
    }
    return 0;
}