C++ is primarily an object-oriented language, but it also supports functional programming features. While C++ may not be as inherently functional as languages like Haskell or Scala, it provides a wide range of features that allow you to write functional code in a C++-style, such as higher-order functions, lambdas, immutability, and more.

Here's a breakdown of key functional programming concepts and how they can be applied in C++:

### 1. **First-Class Functions**
In functional programming, functions are first-class citizens, meaning you can pass them as arguments, return them from other functions, and assign them to variables. In C++, this can be achieved using function pointers, functors, or lambda expressions.

#### Example: Function Pointer
```cpp
#include <iostream>

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    void (*func_ptr)() = greet;  // Function pointer
    func_ptr();  // Calling the function via pointer
    return 0;
}
```

#### Example: Lambda Expression
```cpp
#include <iostream>

int main() {
    auto greet = []() { std::cout << "Hello, World!" << std::endl; };
    greet();  // Calling the lambda function
    return 0;
}
```

### 2. **Higher-Order Functions**
A higher-order function is a function that either takes one or more functions as arguments, returns a function, or both. In C++, this can be done using function pointers, lambdas, or `std::function` (a standard library class template for storing and invoking any callable type).

#### Example: Higher-Order Function using `std::function`
```cpp
#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int apply(std::function<int(int, int)> func, int x, int y) {
    return func(x, y);
}

int main() {
    int result = apply(add, 5, 3);  // Passing the add function to apply
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

### 3. **Immutability**
Immutability is a core principle in functional programming. In C++, you can achieve immutability by using `const` variables or passing data by constant reference.

#### Example: Immutable Variable
```cpp
#include <iostream>

int main() {
    const int x = 10;  // x cannot be modified after initialization
    // x = 20;  // Error: x is a constant
    std::cout << "x = " << x << std::endl;
    return 0;
}
```

### 4. **Pure Functions**
Pure functions are those that do not have side effects and always produce the same output for the same input. This is an important aspect of functional programming. In C++, you can write pure functions like any other function, ensuring no state is modified outside the function and the output depends only on the input.

#### Example: Pure Function
```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;  // No side effects, always returns the same result for the same inputs
}

int main() {
    std::cout << "add(2, 3) = " << add(2, 3) << std::endl;
    return 0;
}
```

### 5. **Recursion**
Functional programming often uses recursion instead of loops for iterative computations. While C++ is not known for tail recursion optimization, you can still implement recursive functions.

#### Example: Recursive Function
```cpp
#include <iostream>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;
    return 0;
}
```

### 6. **Lazy Evaluation**
Lazy evaluation is a concept where expressions are not evaluated until their values are actually needed. While C++ does not have built-in lazy evaluation like Haskell, you can simulate this behavior using `std::function` or lambdas.

#### Example: Lazy Evaluation with `std::function`
```cpp
#include <iostream>
#include <functional>

int main() {
    int x = 5;
    std::function<int()> lazyEval = [&]() { return x * x; };
    
    // The value of x * x is not calculated until we call the lambda
    std::cout << "Lazy evaluation result: " << lazyEval() << std::endl;
    
    return 0;
}
```

### 7. **Functional Data Structures**
Functional programming emphasizes immutability, so functional data structures like lists, sets, or maps can be used. While C++ standard library containers (e.g., `std::vector`, `std::map`) are mutable by default, you can simulate immutable structures or use immutable wrapper classes.

#### Example: Immutable `std::vector`
```cpp
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> numbers = {1, 2, 3, 4, 5};  // Immutable vector
    // numbers.push_back(6);  // Error: Cannot modify a const vector

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 8. **Monads (Simulated)**
While C++ does not have built-in support for Monads like Haskell, you can simulate monadic behavior through containers and techniques like function chaining. The `std::optional`, `std::future`, or even `std::vector` can be considered monadic in certain use cases.

#### Example: Using `std::optional` to simulate monadic behavior
```cpp
#include <iostream>
#include <optional>

std::optional<int> safeDivide(int a, int b) {
    if (b == 0) return std::nullopt;  // Return empty optional on division by zero
    return a / b;
}

int main() {
    auto result = safeDivide(10, 2);
    if (result) {
        std::cout << "Result: " << *result << std::endl;
    } else {
        std::cout << "Error: Division by zero" << std::endl;
    }
    return 0;
}
```

### 9. **Function Composition**
Function composition is the process of combining two or more functions to create a new function. In C++, you can create function composition manually or by using lambda functions.

#### Example: Function Composition
```cpp
#include <iostream>
#include <functional>

int add1(int x) {
    return x + 1;
}

int multiplyBy2(int x) {
    return x * 2;
}

int compose(std::function<int(int)> f, std::function<int(int)> g, int x) {
    return f(g(x));  // Composing functions f and g
}

int main() {
    int result = compose(add1, multiplyBy2, 3);  // Result of (add1(multiplyBy2(3)))
    std::cout << "Composed Result: " << result << std::endl;
    return 0;
}
```

### 10. **Filter, Map, and Reduce**
Functional programming languages often include higher-order functions like `map`, `filter`, and `reduce` that allow you to manipulate collections declaratively. You can implement similar functionality in C++ using algorithms and lambdas.

#### Example: `map` function using `std::transform`
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int square(int x) {
    return x * x;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squaredNumbers(numbers.size());
    
    std::transform(numbers.begin(), numbers.end(), squaredNumbers.begin(), square);
    
    for (int num : squaredNumbers) {
        std::cout << num << " ";  // Output: 1 4 9 16 25
    }
    std::cout << std::endl;

    return 0;
}
```

#### Example: `filter` function using `std::copy_if`
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool isEven(int x) {
    return x % 2 == 0;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> evenNumbers;
    
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), isEven);
    
    for (int num : evenNumbers) {
        std::cout << num << " ";  // Output: 2 4
    }
    std::cout << std::endl;

    return 0;
}
```

### Conclusion

C++ is a multi-paradigm language, and while it’s not purely functional, it has many features that allow you to implement functional programming techniques. Here's a summary of functional programming concepts in C++:

- **First-class functions**: Using function pointers, lambdas, and `std::function`.
- **Higher-order functions**: Functions that accept other functions as arguments or return them.
- **Immutability**: Using `const` variables and constant references.
- **Pure functions**: Functions that do not have side effects.
- **Recursion**: Using recursive functions instead of loops.
- **Lazy evaluation**: Using `std::function` and lambdas to delay computation.
- **Monads**: Simulating monadic behavior using `std::optional`, `std::future`, etc.
- **Function composition**: Combining functions to create more complex behavior.
- **Filter, map, reduce**: Using standard algorithms (`std::transform`, `std::copy_if`, etc.) to process collections in a functional way.

These techniques allow C++ developers to write more declarative, modular, and reusable code in a functional style.