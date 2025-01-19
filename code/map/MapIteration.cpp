#include <iostream>
#include <map>

// Custom function to increment value by 1
int incrementValue(int x) {
    return x + 1;
}

int main() {
    // Sample map
    std::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
    
    // Apply custom operation on values using std::map iterator
    for (auto& pair : myMap) {
        pair.second = incrementValue(pair.second); // Modify the value
    }

    // Print the modified map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
