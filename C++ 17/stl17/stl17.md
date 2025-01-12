In C++17, the **Standard Template Library (STL)** provides a wide range of **containers** that allow you to store and manage data. These containers are categorized based on their behavior and data structures. Below is an overview of the **C++17 STL containers**, including the improvements and new features introduced in C++17.

### Types of Containers in C++17:

C++ containers are broadly categorized into the following types:

1. **Sequence Containers**
2. **Associative Containers**
3. **Unordered Containers**
4. **Container Adapters**

### 1. Sequence Containers
Sequence containers store elements in a linear sequence, where the order of the elements is important. Common sequence containers include:

- **`std::vector`**: A dynamic array that provides random access and supports efficient insertion and removal at the end.
  
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  vec.push_back(5);
  ```

- **`std::deque`**: A double-ended queue that supports fast insertion and deletion at both ends but provides slower random access than `std::vector`.

  ```cpp
  std::deque<int> deq = {1, 2, 3};
  deq.push_front(0);  // Add to front
  deq.push_back(4);   // Add to back
  ```

- **`std::list`**: A doubly linked list that allows fast insertion and deletion from anywhere in the list, but random access is slower.

  ```cpp
  std::list<int> lst = {1, 2, 3};
  lst.push_back(4);  // Add to back
  lst.push_front(0); // Add to front
  ```

- **`std::array`** (since C++11): A fixed-size array. Its size is known at compile-time, and it provides bounds-checked access.

  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  ```

### 2. Associative Containers
Associative containers store elements in key-value pairs, and they automatically sort the elements based on the keys (or a custom comparator).

- **`std::set`**: Stores unique elements in a sorted order.
  
  ```cpp
  std::set<int> s = {1, 2, 3, 4};
  s.insert(5);
  ```

- **`std::map`**: Stores key-value pairs with unique keys, sorted by the keys.

  ```cpp
  std::map<int, std::string> m;
  m[1] = "one";
  m[2] = "two";
  ```

- **`std::multiset`**: Similar to `std::set`, but allows duplicate values.

  ```cpp
  std::multiset<int> ms = {1, 1, 2, 2, 3};
  ms.insert(2);
  ```

- **`std::multimap`**: Stores key-value pairs, but allows duplicate keys.

  ```cpp
  std::multimap<int, std::string> mm;
  mm.insert({1, "one"});
  mm.insert({1, "uno"});
  ```

### 3. Unordered Containers (Introduced in C++11)
Unordered containers use hash tables and do not maintain any specific order for their elements. They provide faster average-time complexity for searching, insertion, and deletion.

- **`std::unordered_set`**: Stores unique elements without any specific order.
  
  ```cpp
  std::unordered_set<int> us = {1, 2, 3, 4};
  us.insert(5);
  ```

- **`std::unordered_map`**: Stores key-value pairs, where keys are unique, and the elements are not ordered.
  
  ```cpp
  std::unordered_map<int, std::string> um;
  um[1] = "one";
  um[2] = "two";
  ```

- **`std::unordered_multiset`**: Similar to `std::unordered_set` but allows duplicate elements.

  ```cpp
  std::unordered_multiset<int> ums = {1, 1, 2, 3};
  ums.insert(2);
  ```

- **`std::unordered_multimap`**: Stores key-value pairs, but allows duplicate keys.

  ```cpp
  std::unordered_multimap<int, std::string> umm;
  umm.insert({1, "one"});
  umm.insert({1, "uno"});
  ```

### 4. Container Adapters
Container adapters are wrappers around other containers that provide specialized interfaces. The adapter does not change the underlying container's characteristics, but it does provide a different interface for interacting with the data.

- **`std::stack`**: A LIFO (Last-In-First-Out) stack, typically implemented using `std::deque` or `std::vector`.

  ```cpp
  std::stack<int> stk;
  stk.push(1);
  stk.push(2);
  int top = stk.top(); // top is 2
  stk.pop();
  ```

- **`std::queue`**: A FIFO (First-In-First-Out) queue, typically implemented using `std::deque`.

  ```cpp
  std::queue<int> q;
  q.push(1);
  q.push(2);
  int front = q.front();  // front is 1
  q.pop();
  ```

- **`std::priority_queue`**: A container adapter that provides priority-based access to elements, typically implemented using a heap.

  ```cpp
  std::priority_queue<int> pq;
  pq.push(10);
  pq.push(20);
  pq.push(15);
  int top = pq.top();  // top is 20 (max heap by default)
  pq.pop();
  ```

---

### New Features and Improvements in C++17

C++17 did not introduce any new container types, but it did bring some important improvements to the STL containers:

1. **`std::unordered_map::insert_or_assign`** (C++17): 
   - This function inserts a key-value pair if the key does not exist or updates the value if the key already exists.

   ```cpp
   std::unordered_map<int, std::string> um;
   um.insert_or_assign(1, "one");
   um.insert_or_assign(1, "uno");  // Updates the value for key 1
   ```

2. **`std::unordered_map::try_emplace`** (C++17): 
   - This function attempts to insert an element only if the key does not already exist. It avoids unnecessary copy or move operations.

   ```cpp
   std::unordered_map<int, std::string> um;
   um.try_emplace(2, "two");  // Only inserts if key 2 doesn't exist
   ```

3. **`std::map::insert_or_assign`** (C++17): 
   - Similar to `std::unordered_map::insert_or_assign`, this allows you to insert a key-value pair or update the value if the key exists.

   ```cpp
   std::map<int, std::string> m;
   m.insert_or_assign(1, "one");
   m.insert_or_assign(1, "uno");  // Updates value for key 1
   ```

4. **Structured Bindings** (C++17):
   - Structured bindings allow easy access to the key-value pairs in containers like `std::map` or `std::unordered_map`.

   ```cpp
   std::unordered_map<int, std::string> um = {{1, "one"}, {2, "two"}};
   for (const auto& [key, value] : um) {
       std::cout << "Key: " << key << ", Value: " << value << std::endl;
   }
   ```

---

### Summary of STL Containers in C++17

| **Container Type**      | **Description**                                    | **Example**                                      |
|-------------------------|----------------------------------------------------|--------------------------------------------------|
| **`std::vector`**        | Dynamic array with fast random access.             | `std::vector<int> v = {1, 2, 3};`                |
| **`std::deque`**         | Double-ended queue with fast insertion/removal at both ends. | `std::deque<int> d = {1, 2, 3};`                |
| **`std::list`**          | Doubly linked list with fast insertions/removals.  | `std::list<int> l = {1, 2, 3};`                  |
| **`std::array`**         | Fixed-size array.                                  | `std::array<int, 5> arr = {1, 2, 3, 4, 5};`      |
| **`std::set`**           | Ordered collection of unique elements.             | `std::set<int> s = {1, 2, 3};`                   |
| **`std::map`**           | Ordered key-value pairs.                           | `std::map<int, std::string> m = {{1, "a"}};`      |
| **`std::unordered_set`** | Unordered collection of unique elements.           | `std::unordered_set<int> us = {1, 2, 3};`        |
| **`std::unordered_map`** | Unordered key-value pairs.                         | `std::unordered_map<int, std::string> um = {{1, "a"}};` |
| **`std::stack`**         | LIFO (Last-In-First-Out) container.                | `std::stack<int> stk;`                           |
| **`std::queue`**         | FIFO (First-In-First-Out) container.               | `std::queue<int> q;`                             |
| **`std::priority_queue`**| Priority-based queue with heap.                    | `std::priority_queue<int> pq;`                   |

The C++17 STL containers provide powerful abstractions for managing and manipulating data, making it easier to implement efficient algorithms and data structures in C++.