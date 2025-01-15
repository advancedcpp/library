C++17 introduced several new features and improvements to the language, enhancing the Standard Library and making it easier to write efficient and expressive code. Below is an example of a simple algorithm using C++17 features.

### Example: Using `std::ranges` and `std::for_each` (C++17)

C++17 doesn't directly include `std::ranges`, but `std::ranges` and the modern algorithms were standardized in C++20. However, C++17 did enhance the standard library with useful features that can be used in algorithms. Here is an example of a basic algorithm using modern C++ features in C++17.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Example of using std::for_each with a lambda
    std::for_each(numbers.begin(), numbers.end(), [](int &num) {
        num *= 2; // Double each element
    });

    std::cout << "Doubled numbers: ";
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example of using std::sort
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::cout << "Sorted numbers in descending order: ";
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation of the Code:
1. **Lambda Expressions**: The code uses a lambda function to double each element in the vector.
2. **`std::for_each`**: This algorithm applies the lambda to each element in the container.
3. **`std::sort` with a Custom Comparator**: The vector is sorted in descending order using the `std::greater<int>` comparator.
4. **Range-based for loop**: It is used to print out the elements of the vector.

### Key C++17 Features in this Code:
- **Lambda Expressions**: Introduced in C++11, but they are extensively used in C++17.
- **`std::for_each` Algorithm**: Applies a function to each element in a range.
- **`std::sort` with a Custom Comparator**: Sorting in descending order.

### Conclusion:
This example showcases how you can use algorithms in C++17 to manipulate data in a concise and expressive way. While C++20 introduced more powerful algorithms (such as `std::ranges`), C++17 still offers significant capabilities for working with algorithms and containers efficiently.