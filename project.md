Certainly! Let's look at some **real-world examples** where **C++ Standard Template Library (STL)** can be used effectively. These examples will show you how STL containers and algorithms are utilized in practical applications, like building an inventory management system, processing events in a real-time system, and handling user data.

### 1. **Inventory Management System (Using `std::map`, `std::vector`, and `std::set`)**

In an inventory management system, we want to store product information, update stock levels, and allow searching by product ID. We'll use `std::map` to store products with their IDs and stock counts, and `std::set` to track available product categories.

#### Example Code:
```cpp
#include <iostream>
#include <map>
#include <set>
#include <string>

class Inventory {
public:
    // A map to store product ID and stock count
    std::map<int, std::string> products;
    std::map<int, int> stock;

    // A set to store categories (unique categories)
    std::set<std::string> categories;

    // Add a product to the inventory
    void addProduct(int id, const std::string& name, int stockCount, const std::string& category) {
        products[id] = name;
        stock[id] = stockCount;
        categories.insert(category);
    }

    // Update stock of a product
    void updateStock(int id, int newStock) {
        if (stock.find(id) != stock.end()) {
            stock[id] = newStock;
            std::cout << "Stock updated for product " << products[id] << std::endl;
        } else {
            std::cout << "Product not found!" << std::endl;
        }
    }

    // Search for a product by ID
    void searchProduct(int id) {
        if (products.find(id) != products.end()) {
            std::cout << "Product ID: " << id << ", Name: " << products[id]
                      << ", Stock: " << stock[id] << std::endl;
        } else {
            std::cout << "Product not found!" << std::endl;
        }
    }

    // Display all categories
    void displayCategories() {
        std::cout << "Available Categories: ";
        for (const auto& category : categories) {
            std::cout << category << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Inventory inv;

    // Add products to the inventory
    inv.addProduct(101, "Laptop", 50, "Electronics");
    inv.addProduct(102, "Phone", 200, "Electronics");
    inv.addProduct(103, "Shoes", 30, "Footwear");

    // Update stock for a product
    inv.updateStock(101, 45);

    // Search for a product
    inv.searchProduct(102);

    // Display available categories
    inv.displayCategories();

    return 0;
}
```

#### Explanation:
- **`std::map<int, std::string>`** is used to map product IDs to product names.
- **`std::map<int, int>`** is used to store the stock count of each product.
- **`std::set<std::string>`** is used to keep track of the unique categories, ensuring no duplicates.
- The system allows for adding new products, updating stock, searching products by ID, and displaying all available categories.

### 2. **Real-Time Event Processing (Using `std::queue` and `std::unordered_map`)**

In a real-time system, you might need to process events in the order they are received, e.g., user logins, interactions with a website, etc. We can use **`std::queue`** to manage the event processing order and **`std::unordered_map`** to store event data with user IDs.

#### Example Code:
```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

class EventProcessor {
public:
    // A queue to store incoming events (FIFO order)
    std::queue<std::string> eventQueue;

    // A map to store processed events associated with user IDs
    std::unordered_map<int, std::string> processedEvents;

    // Add an event to the queue
    void addEvent(const std::string& event, int userId) {
        eventQueue.push(event);
        std::cout << "Added event for user " << userId << ": " << event << std::endl;
    }

    // Process the next event in the queue
    void processEvent() {
        if (!eventQueue.empty()) {
            std::string event = eventQueue.front();
            eventQueue.pop();
            // Simulate processing the event
            std::cout << "Processing event: " << event << std::endl;
        } else {
            std::cout << "No events to process." << std::endl;
        }
    }

    // Store processed event for a specific user ID
    void storeProcessedEvent(int userId, const std::string& event) {
        processedEvents[userId] = event;
    }

    // Retrieve processed event for a user
    void getProcessedEvent(int userId) {
        if (processedEvents.find(userId) != processedEvents.end()) {
            std::cout << "Processed event for user " << userId << ": " << processedEvents[userId] << std::endl;
        } else {
            std::cout << "No processed events for user " << userId << std::endl;
        }
    }
};

int main() {
    EventProcessor processor;

    // Add some events to the queue
    processor.addEvent("Login", 101);
    processor.addEvent("Purchase", 102);
    processor.addEvent("Logout", 101);

    // Process events
    processor.processEvent();
    processor.processEvent();
    
    // Store processed event for user 101
    processor.storeProcessedEvent(101, "Login");
    
    // Retrieve processed event for user 101
    processor.getProcessedEvent(101);

    return 0;
}
```

#### Explanation:
- **`std::queue<std::string>`** is used to store events and ensure they are processed in the order they were added.
- **`std::unordered_map<int, std::string>`** stores processed events associated with user IDs, allowing for quick lookup by user ID.
- The system adds events to the queue, processes them, stores the processed events, and allows retrieval of specific events based on user IDs.

### 3. **User Profile Management System (Using `std::map`, `std::vector`, and `std::unordered_set`)**

In a user profile management system, we may want to store user information and their preferences (like subscribed topics). We will use **`std::map`** for storing user details by ID, **`std::unordered_set`** for unique preferences, and **`std::vector`** for storing a list of actions performed by the user.

#### Example Code:
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <string>

class UserProfile {
public:
    // A map to store user information by user ID
    std::map<int, std::string> userDetails;

    // A map to store user preferences (set to avoid duplicates)
    std::map<int, std::unordered_set<std::string>> userPreferences;

    // A map to store a list of actions taken by a user
    std::map<int, std::vector<std::string>> userActions;

    // Add a user to the system
    void addUser(int userId, const std::string& name) {
        userDetails[userId] = name;
        std::cout << "User added: " << name << " (ID: " << userId << ")" << std::endl;
    }

    // Add a preference to a user profile
    void addPreference(int userId, const std::string& preference) {
        userPreferences[userId].insert(preference);
        std::cout << "Preference added: " << preference << " for user " << userId << std::endl;
    }

    // Add an action performed by the user
    void addAction(int userId, const std::string& action) {
        userActions[userId].push_back(action);
        std::cout << "Action added: " << action << " for user " << userId << std::endl;
    }

    // Display user profile details
    void displayUserProfile(int userId) {
        if (userDetails.find(userId) != userDetails.end()) {
            std::cout << "User Profile for " << userDetails[userId] << " (ID: " << userId << "):" << std::endl;
            std::cout << "Preferences: ";
            for (const auto& pref : userPreferences[userId]) {
                std::cout << pref << " ";
            }
            std::cout << std::endl;
            std::cout << "Actions: ";
            for (const auto& action : userActions[userId]) {
                std::cout << action << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "User not found!" << std::endl;
        }
    }
};

int main() {
    UserProfile profileSystem;

    // Add users
    profileSystem.addUser(1, "Alice");
    profileSystem.addUser(2, "Bob");

    // Add preferences
    profileSystem.addPreference(1, "Sports");
    profileSystem.addPreference(2, "Music");

    // Add actions
    profileSystem.addAction(1, "Login");
    profileSystem.addAction(1, "View Profile");
    profileSystem.addAction(2, "Purchase");

    // Display user profiles
    profileSystem.displayUserProfile(1);
    profileSystem.displayUserProfile(2);

    return 0;
}
```

#### Explanation:
- **`std::map<int, std::string>`** is used to store user details by user ID.
- **`std::unordered_set<std::string>`** is used to store preferences for each user, ensuring that each preference is unique.
- **`std::vector<std::string>`** is used to store actions performed by users, allowing multiple actions in sequence.

This system allows adding users, updating preferences and actions, and displaying the profile details for any user.

---

### Conclusion:
In these examples, we demonstrated how to use **C++ STL containers** like `std::map`, `std::set`, `std::unordered_map`, `std::queue`, and `std::vector` to model real-world systems such as inventory management, event processing, and user profile management. By utilizing STL, we can simplify tasks like searching, updating, and storing collections of data, making the code more efficient and easier to maintain.