In C++17, **`std::vector`** is a dynamic array-like container from the Standard Template Library (STL). It is part of the `<vector>` header and provides various operations to manage sequences of elements. Vectors are particularly useful when you need an array that can dynamically grow or shrink in size.

### Key Features of `std::vector`:
1. **Dynamic Size**: The size of a `std::vector` can change dynamically as elements are added or removed.
2. **Contiguous Storage**: Elements are stored in contiguous memory locations, which makes vector very efficient for accessing elements by index.
3. **Efficient Insertions/Deletions**: Insertions and deletions at the end of the vector are efficient (amortized constant time), but insertions and deletions at arbitrary positions are less efficient (linear time).

### Common Operations on `std::vector`:
- **Initialization**
- **Adding Elements**
- **Accessing Elements**
- **Iterating Over Elements**
- **Modifying Elements**
- **Removing Elements**
- **Resizing and Reserving Space**
- **Checking Size and Capacity**

Below are examples of various operations on `std::vector` in C++17:

### 1. **Initialization and Declaration**
You can initialize a vector in multiple ways:

```cpp
#include <iostream>
#include <vector>

int main() {
    // Default constructor (empty vector)
    std::vector<int> vec1;

    // Constructor with a size and a default value
    std::vector<int> vec2(5, 10); // 5 elements, each initialized to 10

    // Initializer list (C++11 onwards)
    std::vector<int> vec3 = {1, 2, 3, 4, 5};

    // Display the vectors
    std::cout << "vec1 size: " << vec1.size() << std::endl;
    std::cout << "vec2 elements: ";
    for (int i : vec2) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "vec3 elements: ";
    for (int i : vec3) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

### Output:

```
vec1 size: 0
vec2 elements: 10 10 10 10 10 
vec3 elements: 1 2 3 4 5 
```

### 2. **Adding Elements**
You can add elements to a vector using:
- **`push_back()`**: Adds an element to the end of the vector.
- **`emplace_back()`**: Constructs an element in place at the end (more efficient than `push_back` for complex types).

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};

    // Add an element at the end
    vec.push_back(4);
    vec.push_back(5);

    // Add an element using emplace_back (direct construction)
    vec.emplace_back(6);

    // Display the vector
    std::cout << "Elements after adding: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

### Output:

```
Elements after adding: 1 2 3 4 5 6 
```

### 3. **Accessing Elements**
You can access elements using:
- **`operator[]`**: Accesses elements by index (does not check bounds).
- **`at()`**: Accesses elements by index with bounds checking.
- **`front()`**: Returns the first element.
- **`back()`**: Returns the last element.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Access using operator[]
    std::cout << "Second element: " << vec[1] << std::endl;

    // Access using at()
    std::cout << "Fourth element using at(): " << vec.at(3) << std::endl;

    // Access front and back elements
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    return 0;
}
```

### Output:

```
Second element: 20
Fourth element using at(): 40
First element: 10
Last element: 50
```

### 4. **Iterating Over Elements**
You can iterate over a vector using different methods:

- **Range-based for loop** (C++11 and above).
- **Iterator**: Using `begin()` and `end()` iterators.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Range-based for loop
    std::cout << "Elements using range-based for loop: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    // Using iterators
    std::cout << "Elements using iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Output:

```
Elements using range-based for loop: 1 2 3 4 5 
Elements using iterators: 1 2 3 4 5 
```

### 5. **Removing Elements**
You can remove elements using:
- **`pop_back()`**: Removes the last element.
- **`erase()`**: Removes one or more elements by position or value.
- **`clear()`**: Removes all elements.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Remove the last element
    vec.pop_back();

    // Remove the first element (by position)
    vec.erase(vec.begin());

    // Remove all elements
    vec.clear();

    // Display the vector
    std::cout << "Vector size after operations: " << vec.size() << std::endl;

    return 0;
}
```

### Output:

```
Vector size after operations: 0
```

### 6. **Resizing and Reserving Space**
- **`resize()`**: Changes the size of the vector.
- **`reserve()`**: Reserves space for at least `n` elements to avoid reallocations when adding elements.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};

    // Resize the vector to 5 elements, new elements initialized to 0
    vec.resize(5);

    // Reserve space for at least 10 elements
    vec.reserve(10);

    // Display the vector
    std::cout << "Vector after resizing: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

### Output:

```
Vector after resizing: 1 2 3 0 0 
```

### 7. **Size and Capacity**
- **`size()`**: Returns the number of elements in the vector.
- **`capacity()`**: Returns the total number of elements that the vector can store without reallocating.
- **`empty()`**: Returns `true` if the vector is empty.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

### Output:

```
Size: 3
Capacity: 3
Is empty: No
```

### Conclusion:
- **`std::vector`** provides dynamic resizing, efficient random access, and fast append operations (`push_back`).
- It's ideal for situations where you need a resizable array-like structure.
- Various operations like adding, accessing, removing, resizing, and checking size/capacity are simple and efficient in `std::vector`.