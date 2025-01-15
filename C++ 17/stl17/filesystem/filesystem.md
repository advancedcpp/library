In C++17, the **Filesystem library** was officially introduced to the Standard Library. It provides a set of functions and types to work with file systems, such as manipulating files and directories, checking file status, and performing operations like creating, removing, and renaming files and directories.

### Key Features of the Filesystem Library in C++17:

- **`std::filesystem::path`**: Represents a path in the filesystem (either relative or absolute).
- **`std::filesystem::directory_iterator`**: Iterates over the contents of a directory.
- **`std::filesystem::create_directory`**, **`std::filesystem::remove`**, **`std::filesystem::rename`**: Operations to manipulate directories and files.
- **`std::filesystem::exists`**, **`std::filesystem::is_directory`**, **`std::filesystem::is_regular_file`**: Functions to check the status of a path (whether it's a file, directory, or exists).
- **`std::filesystem::copy`**, **`std::filesystem::remove_all`**: Operations to copy files and remove directories recursively.

### Example Usage:

Here’s an example demonstrating how to use the C++17 Filesystem library.

```cpp
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    // Define file and directory paths
    fs::path dir_path = "example_dir";
    fs::path file_path = dir_path / "example.txt";

    // Create a directory
    if (!fs::exists(dir_path)) {
        if (fs::create_directory(dir_path)) {
            std::cout << "Directory created: " << dir_path << std::endl;
        } else {
            std::cout << "Failed to create directory: " << dir_path << std::endl;
        }
    }

    // Create a file
    std::ofstream(file_path) << "Hello, C++17 Filesystem!" << std::endl;

    // Check if the file exists
    if (fs::exists(file_path)) {
        std::cout << "File created: " << file_path << std::endl;

        // Open the file and read contents (just printing the file path in this case)
        std::cout << "File path: " << file_path << std::endl;
    }

    // Iterate over the directory contents
    std::cout << "Contents of the directory:" << std::endl;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        std::cout << entry.path() << std::endl;
    }

    // Rename the file
    fs::path new_file_path = dir_path / "new_example.txt";
    fs::rename(file_path, new_file_path);
    std::cout << "File renamed to: " << new_file_path << std::endl;

    // Remove the file and directory
    fs::remove(new_file_path);
    std::cout << "File removed: " << new_file_path << std::endl;

    // Remove the directory
    fs::remove_all(dir_path);
    std::cout << "Directory removed: " << dir_path << std::endl;

    return 0;
}
```

### Explanation:
1. **Creating Directories and Files**: `fs::create_directory()` creates a new directory, and we use `std::ofstream` to create and write to a file.
2. **Checking Existence**: `fs::exists()` checks whether a path (file or directory) exists.
3. **Renaming**: `fs::rename()` is used to rename files or directories.
4. **Iteration over Directory**: `fs::directory_iterator` allows you to iterate over the contents of a directory.
5. **Removing Files and Directories**: `fs::remove()` deletes a file, and `fs::remove_all()` removes a directory and its contents recursively.

### Commonly Used Functions:

1. **Creating Directories**:
   ```cpp
   fs::create_directory("new_dir");
   ```

2. **Checking File Types**:
   ```cpp
   if (fs::is_regular_file(path)) {
       std::cout << "It's a regular file." << std::endl;
   }
   ```

3. **Copying Files**:
   ```cpp
   fs::copy("source.txt", "destination.txt");
   ```

4. **Removing Files**:
   ```cpp
   fs::remove("file.txt");
   ```

5. **Iterating Over Files in a Directory**:
   ```cpp
   for (const auto& entry : fs::directory_iterator("directory_path")) {
       std::cout << entry.path() << std::endl;
   }
   ```

### Benefits of Filesystem Library in C++17:

- **Platform-independent**: The library works across different operating systems (Windows, Linux, macOS) and abstracts away platform-specific filesystem operations.
- **Ease of Use**: Simplifies common file system tasks like traversing directories, creating/removing files, and checking file types.
- **Standardized**: Being part of the C++ Standard Library, it reduces the need for external libraries to perform filesystem-related tasks.

### Conclusion:
The **Filesystem library** in C++17 provides an efficient and standardized way to handle file system operations. Whether you're managing files, directories, or performing other tasks like copying and renaming, this library helps simplify and streamline file handling in C++ programs.