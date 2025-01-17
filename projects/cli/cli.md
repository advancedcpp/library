The **most used CLI libraries** vary depending on the programming language and the type of project being built. However, some libraries have become well-established and widely adopted due to their flexibility, features, and ease of use. Here's a list of the most commonly used CLI libraries for popular programming languages:

---

### **1. Python: `argparse`**

- **Most Commonly Used**: `argparse` is part of Python’s standard library, making it the most popular choice for building command-line tools in Python. It is widely used due to its simplicity, powerful argument parsing, and automatic help generation.

- **Why It's Popular**:
  - Built-in with Python.
  - Handles positional and optional arguments.
  - Automatically generates help and error messages.

- **Usage Example**:
  ```python
  import argparse

  parser = argparse.ArgumentParser(description='CLI Tool Example')
  parser.add_argument('input', help='Input file path')
  parser.add_argument('--verbose', action='store_true', help='Enable verbose output')

  args = parser.parse_args()
  if args.verbose:
      print("Verbose mode enabled")
  print(f'Input: {args.input}')
  ```

---

### **2. Rust: `clap`**

- **Most Commonly Used**: `clap` (Command Line Argument Parser) is the most widely used CLI library in the Rust ecosystem. It is the go-to library for Rust developers to handle argument parsing, subcommands, and automatic help generation.

- **Why It's Popular**:
  - Offers comprehensive support for argument parsing, validation, and help messages.
  - Supports subcommands (for multi-command CLI tools).
  - Auto-generates help and version flags.
  - Actively maintained and highly performant.

- **Usage Example**:
  ```toml
  [dependencies]
  clap = "3.0"
  ```

  ```rust
  use clap::{Arg, Command};

  fn main() {
      let matches = Command::new("CLI Tool")
          .version("1.0")
          .author("Author Name")
          .about("Command-line tool example")
          .arg(Arg::new("input")
              .about("Input file")
              .required(true)
              .index(1))
          .get_matches();

      let input = matches.value_of("input").unwrap();
      println!("Input file: {}", input);
  }
  ```

---

### **3. Go: `cobra`**

- **Most Commonly Used**: `cobra` is the most popular CLI library in the Go (Golang) ecosystem. It is used by many production-grade CLI tools in Go due to its robust support for subcommands, flags, and arguments.

- **Why It's Popular**:
  - Supports complex CLI structures with subcommands.
  - Handles flags, arguments, and error messages well.
  - Actively maintained and used in many Go-based projects.

- **Usage Example**:
  ```bash
  go get github.com/spf13/cobra
  ```

  ```go
  package main

  import (
      "fmt"
      "github.com/spf13/cobra"
      "os"
  )

  func main() {
      var rootCmd = &cobra.Command{
          Use:   "cli-tool",
          Short: "CLI Tool Example",
          Run: func(cmd *cobra.Command, args []string) {
              fmt.Println("Hello from the CLI tool!")
          },
      }

      rootCmd.Execute()
  }
  ```

---

### **4. Node.js: `commander`**

- **Most Commonly Used**: `commander` is the go-to CLI library for **Node.js**. It is widely used for creating command-line applications due to its simplicity and powerful feature set.

- **Why It's Popular**:
  - Supports subcommands and easy argument parsing.
  - Provides automatic help and version flags.
  - Extensively used in Node.js applications and tools.

- **Usage Example**:
  ```bash
  npm install commander
  ```

  ```javascript
  const { program } = require('commander');

  program
    .version('1.0.0')
    .description('CLI Tool Example')
    .option('-v, --verbose', 'Enable verbose output')
    .argument('<input>', 'Input file')
    .action((input, options) => {
        console.log(`Input file: ${input}`);
        if (options.verbose) {
            console.log('Verbose mode enabled');
        }
    });

  program.parse(process.argv);
  ```

---

### **5. C++: `cxxopts`**

- **Most Commonly Used**: `cxxopts` is one of the most popular libraries for CLI argument parsing in **C++**. It's lightweight, easy to use, and supports all the basic features required for command-line tools.

- **Why It's Popular**:
  - Simple and lightweight.
  - Supports flags, options, and argument types.
  - Provides clear error handling and help generation.

- **Usage Example**:
  ```cpp
  #include <cxxopts.hpp>
  #include <iostream>

  int main(int argc, char* argv[]) {
      cxxopts::Options options("cli-tool", "A simple example CLI tool");

      options.add_options()
          ("i,input", "Input file", cxxopts::value<std::string>())
          ("v,verbose", "Enable verbose output");

      auto result = options.parse(argc, argv);

      if (result.count("input")) {
          std::cout << "Input file: " << result["input"].as<std::string>() << std::endl;
      }

      if (result.count("verbose")) {
          std::cout << "Verbose mode enabled" << std::endl;
      }

      return 0;
  }
  ```

---

### **6. Ruby: `thor`**

- **Most Commonly Used**: `thor` is one of the most commonly used libraries in **Ruby** for building CLI tools, especially for tools that require tasks, subcommands, and options.

- **Why It's Popular**:
  - Supports subcommands and task-based CLI structures.
  - Easy to use with comprehensive documentation.
  - Automatically generates help and usage messages.

- **Usage Example**:
  ```bash
  gem install thor
  ```

  ```ruby
  require 'thor'

  class MyCLI < Thor
    desc "hello NAME", "Say hello to NAME"
    option :verbose, type: :boolean, default: false
    def hello(name)
      puts "Hello, #{name}!"
      if options[:verbose]
        puts "Verbose mode enabled"
      end
    end
  end

  MyCLI.start(ARGV)
  ```

---

### **Conclusion:**

Here’s a quick recap of the **most used CLI libraries**:

1. **Python**: `argparse` – Built-in, powerful, and easy to use.
2. **Rust**: `clap` – Highly feature-rich, with support for subcommands and validation.
3. **Go**: `cobra` – Robust, with subcommand support, and widely used in production.
4. **Node.js**: `commander` – Simple, flexible, and widely adopted in the JavaScript ecosystem.
5. **C++**: `cxxopts` – Lightweight and easy-to-use, with a simple interface.
6. **Ruby**: `thor` – Powerful, supports tasks, subcommands, and easy to use for Ruby developers.

**`argparse`**, **`clap`**, and **`cobra`** are the most commonly used in Python, Rust, and Go, respectively. These libraries are well-maintained, feature-rich, and are commonly used in production environments, making them the top choices for creating command-line tools in those languages.