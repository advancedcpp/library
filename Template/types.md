Templates in **C++** are one of the most powerful features of the language, enabling generic programming, type safety, and code reusability. Mastering templates will help you write more flexible, reusable, and maintainable code. Below is an in-depth look at **C++ templates**, with advanced usage and concepts.

### **1. Basic Template Syntax**

Templates allow you to write code that works with any data type, defined generically. The basic syntax for defining a template is:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

In this example, `T` is a **type parameter**, and the function `add()` will work with any data type, such as `int`, `float`, `double`, etc.

### **2. Template Function**

Template functions enable generic functions that can operate on any data type.

```cpp
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    int result1 = multiply(5, 6);     // Works with integers
    double result2 = multiply(3.5, 4.2); // Works with floating-point numbers
}
```

### **3. Template Classes**

Template classes allow the creation of classes that operate on any data type. This makes code more flexible and reusable.

```cpp
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);  // Box for integers
    Box<double> doubleBox(3.14);  // Box for doubles
    std::cout << intBox.getValue() << std::endl;  // Output: 10
    std::cout << doubleBox.getValue() << std::endl;  // Output: 3.14
}
```

### **4. Template Specialization**

Template specialization allows you to provide a custom implementation of a template for a specific data type. This is useful when you need different behavior for particular types.

#### **Full Specialization:**

```cpp
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << value << std::endl;
    }
};

// Specializing for char
template <>
class Printer<char> {
public:
    void print(char value) {
        std::cout << "Character: " << value << std::endl;
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(100);  // Output: 100

    Printer<char> charPrinter;
    charPrinter.print('A'); // Output: Character: A
}
```

#### **Partial Specialization:**

You can specialize part of the template (like for pointer types, reference types, etc.).

```cpp
template <typename T>
class Wrapper {
public:
    T value;
    Wrapper(T val) : value(val) {}
};

// Specialization for pointer types
template <typename T>
class Wrapper<T*> {
public:
    T* value;
    Wrapper(T* val) : value(val) {}
    void print() {
        std::cout << "Pointer: " << *value << std::endl;
    }
};

int main() {
    int x = 10;
    Wrapper<int> w1(x);
    std::cout << w1.value << std::endl;  // Output: 10

    Wrapper<int*> w2(&x);
    w2.print();  // Output: Pointer: 10
}
```

### **5. Variadic Templates**

C++11 introduced variadic templates, allowing you to define templates that accept a variable number of arguments.

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}

int main() {
    print(1, 2, 3);             // Output: 123
    print("Hello", "World");    // Output: HelloWorld
}
```

#### Explanation:
- `Args... args` represents a parameter pack.
- `(std::cout << ... << args)` is a fold expression that expands all arguments and prints them.

### **6. Template Metaprogramming**

Template metaprogramming (TMP) is a technique where you use templates to perform computations at compile-time rather than runtime. This can lead to highly efficient code by reducing the amount of computation done at runtime.

#### **Example: Compile-Time Factorial Calculation**

```cpp
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    std::cout << Factorial<5>::value << std::endl;  // Output: 120
}
```

In this example, the `Factorial` template calculates the factorial of a number at compile-time, eliminating the need for a runtime computation.

### **7. SFINAE (Substitution Failure Is Not An Error)**

SFINAE is a technique in template programming that allows for conditional compilation based on the properties of types. It enables function overloading or template specialization based on certain traits or conditions.

```cpp
#include <iostream>
#include <type_traits>

// SFINAE-based function: Only available for integral types
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
square(T x) {
    return x * x;
}

int main() {
    std::cout << square(5) << std::endl;       // Output: 25 (Works for integers)
    // std::cout << square(3.5) << std::endl;  // Error: Will not compile for non-integral types
}
```

- `std::is_integral<T>::value` checks if `T` is an integral type.
- `std::enable_if` is used to conditionally enable the `square()` function only for integral types.

### **8. Type Traits**

Type traits allow you to query or modify types during compilation. Commonly used type traits include:
- `std::is_integral<T>` – checks if `T` is an integral type.
- `std::is_floating_point<T>` – checks if `T` is a floating-point type.
- `std::is_same<T, U>` – checks if `T` and `U` are the same type.

```cpp
#include <iostream>
#include <type_traits>

template <typename T>
void checkType(T value) {
    if (std::is_integral<T>::value) {
        std::cout << "Integral type" << std::endl;
    } else if (std::is_floating_point<T>::value) {
        std::cout << "Floating-point type" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    checkType(10);   // Output: Integral type
    checkType(3.14); // Output: Floating-point type
}
```

### **9. CRTP (Curiously Recurring Template Pattern)**

The **CRTP** is a technique where a class inherits from a template instantiation of itself. It allows you to statically polymorph behavior, optimizing performance by resolving at compile-time.

```cpp
template <typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Derived implementation!" << std::endl;
    }
};

int main() {
    Derived d;
    d.interface();  // Output: Derived implementation!
}
```

The **CRTP** pattern is often used to implement static polymorphism in cases where dynamic polymorphism (i.e., virtual functions) would be too costly.

### **10. Template and Lambda Expressions**

You can combine templates with **lambda expressions** for more powerful abstractions, particularly in algorithms or when implementing callbacks.

```cpp
template <typename Func>
void applyToFive(Func func) {
    std::cout << func(5) << std::endl;
}

int main() {
    applyToFive([](int x) { return x * x; });  // Output: 25
    applyToFive([](int x) { return x + 10; }); // Output: 15
}
```

### **Conclusion**

Mastering C++ templates and their advanced features is crucial for developing highly efficient and reusable code. Here's a summary of key points:
- **Template Functions and Classes**: Write generic code for multiple types.
- **Template Specialization**: Customize behavior for specific types.
- **Variadic Templates**: Work with functions accepting a variable number of arguments.
- **Template Metaprogramming**: Perform compile-time calculations to optimize code.
- **SFINAE**: Enable conditional compilation based on type properties.
- **Type Traits**: Query and modify types at compile-time.
- **CRTP**: Implement static polymorphism.
- **Lambdas and Templates**: Combine for powerful abstractions.

By understanding and applying these advanced template techniques, you can write more efficient, modular, and flexible C++ code.