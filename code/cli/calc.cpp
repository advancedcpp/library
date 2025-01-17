#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
double calculate(double num1, double num2, const std::string &op)
{
    if (op == "+")
    {
        return num1 + num2;
    }
    else if (op == "-")
    {
        return num1 - num2;
    }
    else if (op == "*")
    {
        return num1 * num2;
    }
    else if (op == "/")
    {
        if (num2 == 0)
        {
            throw std::invalid_argument("Error: Division by zero is not allowed.");
        }
        return num1 / num2;
    }
    else
    {
        throw std::invalid_argument("Error: Invalid operator.Support are +, -, *, /");
    }
}
int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        std::cerr << "Usage: calculator <num1> <operator> <num2>\n";
    }

    try
    {
        double num1 = std::stod(argv[1]);
        std::string op = argv[2];
        double num2 = std::stod(argv[3]);
        double result = calculate(num1, num2, op);
        std::cout << "Result: " << result << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}