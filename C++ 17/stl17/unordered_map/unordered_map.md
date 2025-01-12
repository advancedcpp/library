In C++17, **`std::unordered_map`** is a part of the Standard Template Library (STL) that is used to store key-value pairs where the order of the elements is not maintained. It is called "unordered" because it does not guarantee any specific order of the elements—unlike `std::map`, which keeps elements sorted by keys. The underlying data structure for `std::unordered_map` is a **hash table**, and it provides average **constant time complexity** (O(1)) for insertions, lookups, and deletions.

### Key Features of `std::unordered_map`:

- **Unordered**: Elements are not stored in any particular order.
- **Hashing**: It uses a hash function to map the key to a bucket, making lookups faster on average.
- **Average constant-time complexity**: The average complexity for search, insertion, and deletion operations is O(1), though in some rare cases (e.g., many hash collisions), it can degrade to O(n).
- **Unique Keys**: Like `std::map`, keys in `std::unordered_map` must be unique. If you try to insert a duplicate key, the value for that key will be updated.

### Syntax:

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> unordered_map;

    // Inserting key-value pairs
    unordered_map[1] = "Apple";
    unordered_map[2] = "Banana";
    unordered_map[3] = "Cherry";

    // Iterating through the unordered_map
    for (const auto& pair : unordered_map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Accessing an element by key
    std::cout << "Value for key 2: " << unordered_map[2] << std::endl;

    // Checking if a key exists
    if (unordered_map.find(3) != unordered_map.end()) {
        std::cout << "Key 3 found, Value: " << unordered_map[3] << std::endl;
    }

    // Removing an element by key
    unordered_map.erase(2);

    std::cout << "After removal, size of unordered_map: " << unordered_map.size() << std::endl;

    return 0;
}
```

### Important Operations with `std::unordered_map`:

1. **Insert Elements**:
   You can insert elements using the subscript operator (`[]`) or the `insert` method.
   ```cpp
   unordered_map[1] = "Apple";  // Insert using subscript operator (or update value if key exists)
   unordered_map.insert({2, "Banana"});  // Insert using insert() method
   ```

2. **Find an Element**:
   The `find` function is used to check if an element exists in the `unordered_map`. It returns an iterator to the element if found, or `unordered_map::end()` if not.
   ```cpp
   auto it = unordered_map.find(1);
   if (it != unordered_map.end()) {
       std::cout << "Key 1 found with value: " << it->second << std::endl;
   }
   ```

3. **Erase an Element**:
   You can remove an element by key using the `erase` function.
   ```cpp
   unordered_map.erase(1);  // Removes the element with key 1
   ```

4. **Check if Key Exists**:
   You can use the `count` function to check if a specific key exists.
   ```cpp
   if (unordered_map.count(2) > 0) {
       std::cout << "Key 2 exists!" << std::endl;
   }
   ```

5. **Get the Size of `unordered_map`**:
   You can use the `size()` function to get the number of elements in the `unordered_map`.
   ```cpp
   std::cout << "Size of unordered_map: " << unordered_map.size() << std::endl;
   ```

---

### C++17 Features in `std::unordered_map`:

C++17 introduced a few features that make working with `std::unordered_map` more convenient and efficient:

#### 1. **`insert_or_assign`** (C++17):
This function inserts a new key-value pair if the key doesn't already exist or updates the value if the key already exists.

```cpp
unordered_map.insert_or_assign(1, "Mango");  // Insert or update value for key 1
```

- **Performance**: This is a more efficient way to handle updates and insertions for a key compared to using `operator[]`, which would create a new element if the key doesn't exist.

#### 2. **`try_emplace`** (C++17):
This function attempts to insert a new element only if the key does not already exist. If the key already exists, it doesn't overwrite the existing element.

```cpp
unordered_map.try_emplace(2, "Orange");  // Will not overwrite existing key 2
```

- **Performance**: This is especially useful if you want to avoid unnecessary copy or move operations and ensure that the element is only inserted if the key does not exist.

#### 3. **Structured Bindings** (C++17):
You can use structured bindings to easily access both keys and values during iteration.

```cpp
for (const auto& [key, value] : unordered_map) {
    std::cout << "Key: " << key << ", Value: " << value << std::endl;
}
```

This syntax makes it easier to work with elements in the container without needing to explicitly use `first` and `second`.

---

### Example: C++17 `unordered_map` with New Features

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> unordered_map;

    // Inserting elements
    unordered_map[1] = "Apple";
    unordered_map[2] = "Banana";
    unordered_map.insert({3, "Cherry"});

    // Insert or update using insert_or_assign
    unordered_map.insert_or_assign(2, "Grapes");  // Updates value for key 2

    // Using try_emplace (only inserts if key doesn't exist)
    unordered_map.try_emplace(4, "Dragonfruit");

    // Structured binding (C++17)
    for (const auto& [key, value] : unordered_map) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    // Finding and erasing an element
    auto it = unordered_map.find(3);
    if (it != unordered_map.end()) {
        std::cout << "Found: " << it->second << std::endl;
    }
    unordered_map.erase(2);  // Removes key 2

    std::cout << "Size after removal: " << unordered_map.size() << std::endl;

    return 0;
}
```

### Output:
```plaintext
Key: 1, Value: Apple
Key: 2, Value: Grapes
Key: 3, Value: Cherry
Key: 4, Value: Dragonfruit
Found: Cherry
Size after removal: 3
```

---

### Differences Between `std::map` and `std::unordered_map`:

| Feature                     | `std::map`                      | `std::unordered_map`               |
|-----------------------------|---------------------------------|------------------------------------|
| **Order**                   | Elements are sorted by key      | No specific order (unordered)      |
| **Underlying Structure**    | Red-Black Tree (balanced BST)   | Hash Table                        |
| **Complexity (Search/Insert)** | O(log n)                       | O(1) on average                    |
| **Key Uniqueness**          | Keys are unique, no duplicates  | Keys are unique, no duplicates     |
| **Performance**             | Slower due to sorting          | Faster (average O(1) for operations) |
| **Custom Comparator**       | Yes, supports custom comparators | No direct support for custom comparator (hashing function can be customized) |

---

### Conclusion:

`std::unordered_map` is a highly efficient container when you don't need the order of elements and want average constant-time performance for key lookups, insertions, and deletions. It is ideal for cases where you need to perform fast lookups and do not require the elements to be ordered. With features introduced in C++17 like `insert_or_assign`, `try_emplace`, and structured bindings, `std::unordered_map` is a powerful and flexible tool for handling key-value pairs in modern C++.