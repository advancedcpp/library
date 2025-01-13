In C++17, the **priority queue** is part of the Standard Template Library (STL) and is implemented using a **heap** structure. A priority queue is a container adapter that provides constant-time access to the largest (by default) or smallest element, depending on the underlying comparison.

### Key Characteristics of a Priority Queue:
1. **Ordering**: The elements are stored in such a way that the largest or smallest element (depending on the comparison) is always at the top of the queue.
2. **Efficiency**: Insertion of an element is done in logarithmic time, and removal of the top element is also logarithmic.
3. **Container Adapter**: The priority queue is not a standalone container but an adapter that works on other underlying containers like `vector`, `deque`, or `list`.

### **Basic Operations of a Priority Queue in C++17**
A priority queue provides the following core operations:
- **push()**: Inserts an element into the queue.
- **pop()**: Removes the element from the top of the queue.
- **top()**: Returns the top element without removing it.
- **empty()**: Checks if the queue is empty.
- **size()**: Returns the number of elements in the queue.

### **Syntax and Basic Usage**

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater and std::less

int main() {
    // Create a priority queue of integers (max-heap by default)
    std::priority_queue<int> pq;

    // Inserting elements
    pq.push(10);
    pq.push(20);
    pq.push(5);
    
    // Accessing the top element
    std::cout << "Top element: " << pq.top() << std::endl; // Output: 20
    
    // Removing the top element
    pq.pop();
    
    std::cout << "Top element after pop: " << pq.top() << std::endl; // Output: 10
    
    // Checking if the queue is empty
    std::cout << "Is the queue empty? " << (pq.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

**Output**:
```
Top element: 20
Top element after pop: 10
Is the queue empty? No
```

### **Custom Comparison Function**
By default, the `priority_queue` in C++ works as a **max-heap**, meaning the largest element is at the top. However, you can modify the behavior of the priority queue to use a **min-heap** (smallest element at the top) or a custom comparison function.

#### Example: Min-Heap (Using `std::greater`)
To create a min-heap, you can use `std::greater<T>` as the comparison function. Here's how to do it:

```cpp
#include <iostream>
#include <queue>
#include <functional> // for std::greater

int main() {
    // Create a priority queue of integers (min-heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // Inserting elements
    pq.push(10);
    pq.push(20);
    pq.push(5);

    // Accessing the top element (smallest element)
    std::cout << "Top element (min-heap): " << pq.top() << std::endl; // Output: 5
    
    // Removing the top element
    pq.pop();
    
    std::cout << "Top element after pop (min-heap): " << pq.top() << std::endl; // Output: 10
    
    // Checking if the queue is empty
    std::cout << "Is the queue empty? " << (pq.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

**Output**:
```
Top element (min-heap): 5
Top element after pop (min-heap): 10
Is the queue empty? No
```

### **Priority Queue with Custom Objects**
You can also use a priority queue to store custom objects by providing a custom comparator (either as a functor, lambda, or function pointer). For example, consider a priority queue of `struct` or `class` objects.

#### Example: Priority Queue with Custom Object

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct Person {
    std::string name;
    int age;
    
    // Custom comparator for ordering by age (greater age first)
    bool operator<(const Person& other) const {
        return age < other.age;  // Higher age should come first
    }
};

int main() {
    // Create a priority queue of Person objects (max-heap by age)
    std::priority_queue<Person> pq;

    // Inserting Person objects
    pq.push({"John", 30});
    pq.push({"Alice", 25});
    pq.push({"Bob", 35});

    // Accessing the top element (Person with max age)
    std::cout << "Top person: " << pq.top().name << " (" << pq.top().age << " years old)" << std::endl;

    // Removing the top element
    pq.pop();

    std::cout << "Top person after pop: " << pq.top().name << " (" << pq.top().age << " years old)" << std::endl;

    return 0;
}
```

**Output**:
```
Top person: Bob (35 years old)
Top person after pop: John (30 years old)
```

### **Using Lambda for Custom Comparison**
You can also use a lambda function for custom comparison in a priority queue.

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
    // Create a priority queue with a custom comparison lambda (min-heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // Inserting elements
    pq.push(10);
    pq.push(20);
    pq.push(5);

    // Accessing the top element
    std::cout << "Top element: " << pq.top() << std::endl; // Output: 5

    // Removing the top element
    pq.pop();
    
    std::cout << "Top element after pop: " << pq.top() << std::endl; // Output: 10

    return 0;
}
```

### **Important Notes:**
1. **Underlying Container**: By default, `std::priority_queue` uses a `std::vector` as the underlying container, but this can be changed by specifying a different container type (like `std::deque`).
   
   ```cpp
   std::priority_queue<int, std::deque<int>> pq;
   ```

2. **Comparison Function**: The `std::priority_queue` takes a comparison function or a functor. If no custom comparator is provided, it uses `std::less<T>` by default, which makes it a max-heap (largest element at the top). For a min-heap, `std::greater<T>` should be used.
   
3. **Custom Objects**: When using a priority queue with custom objects, make sure that the objects can be compared using the less-than operator (`operator<`) or provide a custom comparator.

### **Summary of Priority Queue in C++17:**
- A **priority queue** provides an efficient way to access the maximum or minimum element.
- It can be implemented with **max-heap** (default) or **min-heap** behavior by using custom comparators.
- **Push**, **pop**, and **top** operations are available for managing elements.
- You can use custom objects with a priority queue by defining comparison logic.

The `std::priority_queue` is a flexible and efficient data structure for problems that require ordering based on priority, such as **task scheduling**, **event simulation**, **graph algorithms**, and more.