#include <iostream>

namespace Lib1
{
    void print()
    {
        std::cout << "Library 1 print function!." << std::endl;
    }
}
namespace Lib2
{
    void print()
    {
        std::cout << "Library 1 print function!." << std::endl;
    }
}

namespace Company
{
    namespace HR
    {
        void hireEmployee()
        {
            std::cout << "Hiring an employee!" << std::endl;
        }
    }
}
namespace HR = Company::HR;
int main()
{
    Lib1::print();
    HR::hireEmployee();
    Lib2::print();
    return 0;
}