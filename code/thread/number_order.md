In C++, you can achieve similar functionality using `std::mutex` and `std::condition_variable` for synchronization between threads. Here's how you can implement printing numbers from 1 to 20 using two threads in C++, ensuring the numbers are printed in order (alternating between the threads).

### C++ Implementation:

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;                // Mutex to protect shared data
std::condition_variable cv;     // Condition variable for synchronization
int counter = 1;                // Shared counter variable

// Thread 1: Prints odd numbers (1, 3, 5, ..., 19)
void printOddNumbers() {
    for (int i = 1; i <= 20; i += 2) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        
        // Wait until it's thread 1's turn to print the current odd number
        cv.wait(lock, [i] { return counter == i; });

        // Print the current number for thread 1 (odd numbers)
        std::cout << "Thread 1: " << i << std::endl;
        counter++; // Increment the counter to signal thread 2
        cv.notify_one(); // Notify thread 2 to proceed
    }
}

// Thread 2: Prints even numbers (2, 4, 6, ..., 20)
void printEvenNumbers() {
    for (int i = 2; i <= 20; i += 2) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        
        // Wait until it's thread 2's turn to print the current even number
        cv.wait(lock, [i] { return counter == i; });

        // Print the current number for thread 2 (even numbers)
        std::cout << "Thread 2: " << i << std::endl;
        counter++; // Increment the counter to signal thread 1
        cv.notify_one(); // Notify thread 1 to proceed
    }
}

int main() {
    // Create two threads: one for printing odd numbers and one for printing even numbers
    std::thread t1(printOddNumbers);
    std::thread t2(printEvenNumbers);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}
```

### Explanation of the Code:

1. **Shared Resources**:
   - `counter`: A shared variable that keeps track of the current number that should be printed.
   - `mtx`: A `std::mutex` used to synchronize access to `counter` between the two threads.
   - `cv`: A `std::condition_variable` used to allow threads to wait for their turn to print.

2. **Thread Functions**:
   - **`printOddNumbers()`**: This thread prints odd numbers (1, 3, 5, ..., 19). It waits for the `counter` to match the number it needs to print.
   - **`printEvenNumbers()`**: This thread prints even numbers (2, 4, 6, ..., 20). It also waits for the `counter` to match the number it needs to print.

3. **Synchronization**:
   - Each thread locks the `mutex` using `std::unique_lock<std::mutex> lock(mtx)`, ensuring that only one thread at a time can modify or read the `counter`.
   - The `cv.wait(lock, condition)` function is used to make each thread wait until it is its turn. The `condition` checks if `counter` is equal to the number the thread should print. If not, the thread waits.
   - After printing its number, each thread increments the `counter` and calls `cv.notify_one()` to notify the other thread to proceed.

4. **Thread Joining**:
   - The `t1.join()` and `t2.join()` calls ensure that the main thread waits for both threads to finish their execution before exiting.

### How It Works:

1. **Thread 1** starts, locks the mutex, and waits for `counter == 1`. When it is its turn, it prints "Thread 1: 1", increments `counter`, and signals **Thread 2**.
2. **Thread 2** waits until `counter == 2`, prints "Thread 2: 2", increments `counter`, and signals **Thread 1**.
3. This alternation continues, and the two threads print odd and even numbers until the entire range from 1 to 20 is printed.

### Output:

```
Thread 1: 1
Thread 2: 2
Thread 1: 3
Thread 2: 4
Thread 1: 5
Thread 2: 6
Thread 1: 7
Thread 2: 8
Thread 1: 9
Thread 2: 10
Thread 1: 11
Thread 2: 12
Thread 1: 13
Thread 2: 14
Thread 1: 15
Thread 2: 16
Thread 1: 17
Thread 2: 18
Thread 1: 19
Thread 2: 20
```

### Key Concepts:
- **`std::mutex`**: Ensures that the shared `counter` is accessed by only one thread at a time.
- **`std::condition_variable`**: Allows threads to wait until it's their turn to print. It helps synchronize the printing order.
- **`std::unique_lock`**: Used to lock and unlock the mutex. It provides a more flexible lock than `std::lock_guard`, especially when combined with condition variables.

This C++ implementation ensures that the numbers are printed in order, with **Thread 1** printing the odd numbers and **Thread 2** printing the even numbers.