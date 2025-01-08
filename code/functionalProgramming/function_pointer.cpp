#include <iostream>

using namespace std;

int add(int a, int b)
{

    return a + b;
}

int main()
{
    int (*func_ptr)(int, int);

    func_ptr = add;
    cout <<"Functional pointer: "<< func_ptr(3, 4);
}