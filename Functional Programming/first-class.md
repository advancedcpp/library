In C++, **first-class functions** refer to the ability of functions to be treated as **first-class citizens**. This means that functions can be:

- Assigned to variables.
- Passed as arguments to other functions.
- Returned from functions.
- Stored in data structures like arrays, lists, or maps.

While C++ does not directly have a `function` type like higher-level languages (e.g., JavaScript or Python), you can achieve the same functionality using **function pointers**, **lambdas**, and **std::function**. Let’s explore these in detail.

### 1. **Function Pointers**

Function pointers are a way to store the address of a function, allowing you to treat it as a variable.

#### Example with Function Pointers:

```cpp
#include <iostream>

// A simple function that adds two integers
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare a function pointer for a function that takes two integers and returns an integer
    int (*func_ptr)(int, int);

    // Assign the address of the 'add' function to func_ptr
    func_ptr = add;

    // Call the function using the function pointer
    std::cout << "Sum: " << func_ptr(3, 4) << std::endl; // Output: Sum: 7

    return 0;
}
```

In this example:
- We declare a function pointer `func_ptr` that points to a function taking two integers and returning an integer.
- We assign the address of the `add` function to `func_ptr`.
- We call the function using the pointer.

### 2. **Lambda Expressions**

C++11 introduced **lambda expressions**, which are anonymous functions that can be defined inline. They are often used as function objects or first-class citizens in modern C++.

#### Example with Lambdas:

```cpp
#include <iostream>
#include <functional>

int main() {
    // Define a lambda function that adds two integers
    auto add = [](int a, int b) {
        return a + b;
    };

    // Call the lambda function
    std::cout << "Sum: " << add(5, 6) << std::endl; // Output: Sum: 11

    // Store the lambda in a std::function variable
    std::function<int(int, int)> addFunc = add;
    std::cout << "Sum (from std::function): " << addFunc(10, 15) << std::endl; // Output: Sum (from std::function): 25

    return 0;
}
```

In this example:
- A lambda function `add` is defined and called directly.
- The lambda is assigned to a `std::function` variable, making it possible to store it like any other function.

### 3. **`std::function` for First-Class Functions**

`std::function` is a part of the **C++ Standard Library** (since C++11) and provides a type-safe wrapper for functions, function pointers, and callable objects (like lambdas). It allows functions to be treated as first-class objects.

#### Example with `std::function`:

```cpp
#include <iostream>
#include <functional>

// A simple function that multiplies two integers
int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Create a std::function variable that can hold any function taking two ints and returning an int
    std::function<int(int, int)> func;

    // Assign the 'multiply' function to the std::function variable
    func = multiply;

    // Call the function via std::function
    std::cout << "Product: " << func(4, 5) << std::endl; // Output: Product: 20

    // Assign a lambda to the same std::function variable
    func = [](int a, int b) { return a - b; };
    std::cout << "Difference: " << func(10, 3) << std::endl; // Output: Difference: 7

    return 0;
}
```

In this example:
- The `std::function<int(int, int)>` is used to hold a function or a callable object (like a lambda).
- We first assign the `multiply` function to the `std::function` variable.
- We then assign a lambda to the same variable, showcasing how `std::function` allows you to store different kinds of callable entities.

### 4. **Passing Functions as Arguments**

A key feature of first-class functions is the ability to pass functions as arguments to other functions.

#### Example of Passing Functions as Arguments:

```cpp
#include <iostream>
#include <functional>

// Function that takes another function as an argument
void applyFunction(std::function<int(int, int)> func, int a, int b) {
    std::cout << "Result: " << func(a, b) << std::endl;
}

int main() {
    // Pass a lambda function directly to another function
    applyFunction([](int a, int b) { return a * b; }, 6, 7); // Output: Result: 42

    // Pass a regular function via std::function
    std::function<int(int, int)> addFunc = [](int a, int b) { return a + b; };
    applyFunction(addFunc, 4, 5); // Output: Result: 9

    return 0;
}
```

In this example:
- We define a function `applyFunction` that takes a `std::function` as an argument.
- We pass both a lambda and a regular function to `applyFunction` to compute the result.

### Key Points:
- **Function pointers** allow you to store and invoke functions directly.
- **Lambda expressions** provide concise and flexible anonymous functions.
- **`std::function`** is a versatile tool that allows functions, lambdas, and function pointers to be used interchangeably in a type-safe manner.
- Functions in C++ can be passed as arguments, returned from functions, and stored in variables, making them first-class citizens.

### Conclusion

While C++ doesn't natively support first-class functions in the same way as languages like JavaScript or Python, it provides powerful mechanisms through **function pointers**, **lambdas**, and **`std::function`** to simulate and leverage first-class functions. These tools allow you to treat functions as first-class citizens, enabling more flexible, modular, and reusable code patterns.