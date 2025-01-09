To enhance the task management system by integrating a **GUI (Graphical User Interface)** using **Qt** or **SFML** would involve significant changes in the design, primarily focusing on creating windows, buttons, text fields, and managing events such as user inputs and interactions. Below, I will show you an example of how you can integrate the **Qt framework** for creating a GUI-based **Task Management System**.

Qt is a popular cross-platform C++ framework for GUI development, and it provides tools for building robust, feature-rich desktop applications. I'll walk you through the necessary steps and code to implement the task management system using **Qt**.

---

### **Creating a Task Management System with Qt**

Before you begin, you need to install the **Qt SDK** on your system. You can download it from the official website: https://www.qt.io/download.

Once installed, you can create a **Qt Widgets Application** in Qt Creator, which is the IDE provided by Qt.

Here’s a basic implementation of the task management system using **Qt**. This example will create a simple **task list** where you can **add**, **view**, and **delete tasks** using a **Qt GUI**.

---

### 1. **Task Management System Using Qt**

We will use a **QListWidget** to display tasks, and we will provide buttons to **add**, **remove**, and **mark tasks as completed**. For simplicity, we will use a **`std::map`** to store the task data in the background.

#### Steps:
1. **Create a Qt Widgets Application** in **Qt Creator**.
2. **Add a QWidget** (MainWindow) and design it with buttons and list display.
3. **Use `std::map`** to store the tasks.
4. **Implement event handling** for adding, deleting, and marking tasks as completed.

---

#### **Qt Task Management System Code**

Here’s an example of how to implement it using **Qt**:

**main.cpp**:

```cpp
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <map>
#include <string>
#include <iostream>

using namespace std;

// Task class to represent each task
class Task {
public:
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}

    void markAsCompleted() {
        isCompleted = true;
    }

    QString getStatus() {
        return isCompleted ? "Completed" : "Pending";
    }
};

class TaskManagerWindow : public QWidget {
    Q_OBJECT

public:
    TaskManagerWindow(QWidget *parent = nullptr);
    ~TaskManagerWindow();

private slots:
    void addTask();
    void deleteTask();
    void markTaskAsCompleted();

private:
    QLineEdit* taskInput; // Input field for new task
    QListWidget* taskListWidget; // List view for tasks
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* completeButton;

    map<int, Task> tasks; // Store tasks in a map with Task ID as the key
    int nextTaskID; // ID for next task to add
};

TaskManagerWindow::TaskManagerWindow(QWidget *parent)
    : QWidget(parent), nextTaskID(1) {

    // Setup layout
    QVBoxLayout* mainLayout = new QVBoxLayout;

    // Input field and buttons for task management
    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Enter task description...");

    addButton = new QPushButton("Add Task", this);
    deleteButton = new QPushButton("Delete Task", this);
    completeButton = new QPushButton("Mark as Completed", this);

    taskListWidget = new QListWidget(this);

    mainLayout->addWidget(taskInput);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(taskListWidget);
    mainLayout->addWidget(completeButton);
    mainLayout->addWidget(deleteButton);

    setLayout(mainLayout);

    // Connect buttons to slots
    connect(addButton, &QPushButton::clicked, this, &TaskManagerWindow::addTask);
    connect(deleteButton, &QPushButton::clicked, this, &TaskManagerWindow::deleteTask);
    connect(completeButton, &QPushButton::clicked, this, &TaskManagerWindow::markTaskAsCompleted);
}

TaskManagerWindow::~TaskManagerWindow() {
    // Destructor
}

void TaskManagerWindow::addTask() {
    string description = taskInput->text().toStdString();
    if (description.empty()) {
        QMessageBox::warning(this, "Input Error", "Task description cannot be empty.");
        return;
    }

    // Add task to the map
    tasks[nextTaskID] = Task(description);

    // Add task to the list widget
    QString taskText = QString::fromStdString(description) + " - Pending";
    taskListWidget->addItem(taskText);

    taskInput->clear();
    nextTaskID++;
}

void TaskManagerWindow::deleteTask() {
    int currentRow = taskListWidget->currentRow();
    if (currentRow >= 0) {
        taskListWidget->takeItem(currentRow); // Remove item from UI

        // Find and remove the corresponding task from the map
        auto it = tasks.begin();
        advance(it, currentRow);
        tasks.erase(it);
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a task to delete.");
    }
}

void TaskManagerWindow::markTaskAsCompleted() {
    int currentRow = taskListWidget->currentRow();
    if (currentRow >= 0) {
        // Mark task as completed
        auto it = tasks.begin();
        advance(it, currentRow);

        it->second.markAsCompleted();

        // Update the UI
        QString taskText = QString::fromStdString(it->second.description) + " - Completed";
        taskListWidget->item(currentRow)->setText(taskText);
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a task to mark as completed.");
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TaskManagerWindow window;
    window.setWindowTitle("Task Manager");
    window.resize(400, 300);
    window.show();

    return a.exec();
}
```

---

### **Explanation of the Code**:
1. **Task Class**:
   - The `Task` class contains the **description** of the task and a **status** (`isCompleted`).
   - The method `markAsCompleted()` updates the task's status.
   - The `getStatus()` method returns the task’s status ("Pending" or "Completed").

2. **TaskManagerWindow Class**:
   - This is the **main window** where the tasks are managed.
   - It has a **QLineEdit** for entering new tasks, a **QListWidget** to display tasks, and **QPushButton** widgets for adding, deleting, and marking tasks as completed.
   - Tasks are stored in a **`std::map`** (with the task ID as the key).
   - The GUI updates the list widget when tasks are added, deleted, or marked as completed.

3. **Slot Functions**:
   - `addTask()`: Adds a new task by reading the input, creating a task, and updating the list widget.
   - `deleteTask()`: Deletes the selected task.
   - `markTaskAsCompleted()`: Marks the selected task as completed and updates its status.

---

### **To Compile and Run**:

1. Open **Qt Creator**.
2. Create a new **Qt Widgets Application** project.
3. Copy and paste the provided code into the `main.cpp` file.
4. **Run** the application.

---

### **Features of the Application**:
- **Add Task**: Allows users to input a task and add it to the list.
- **Mark as Completed**: Allows users to mark tasks as completed.
- **Delete Task**: Lets users delete a task from the list.
- **Task List**: Displays tasks with their status ("Pending" or "Completed").

---

### **Enhancements You Can Make**:
1. **Task Editing**: Add a feature to allow users to edit existing tasks.
2. **Due Dates**: Allow users to set due dates for each task and display them.
3. **Task Categories**: Implement task categories (e.g., "Work", "Personal") and allow users to filter tasks based on categories.
4. **Persistence**: Implement a way to save and load tasks from a file (like `tasks.txt`).
5. **Priority**: Allow users to set a priority for each task (e.g., high, medium, low).

---

### Conclusion:
This example demonstrates how to build a **task management system** with a GUI using **Qt**. You can enhance it further with more features like **task filtering**, **due dates**, **priorities**, or **notifications**. Qt's powerful GUI framework makes it easy to create interactive applications, and this system can be extended into a fully-featured task manager.