#include <iostream>
#include <vector>
#include <algorithm>

// Functor to multiply elements by 2
class MultiplyByTwo {
public:
    int operator()(int x) const {
        return x * 2;
    }
};

int main() {
    // Sample vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Create functor object
    MultiplyByTwo multiply;
    
    // Perform custom map operation using the functor
    std::transform(vec.begin(), vec.end(), vec.begin(), multiply);

    // Print the result
    for (int val : vec) {
        std::cout << val << " ";
    }
    
    return 0;
}
