#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits> // For input validation

using namespace std;

// Task Node (Linked List)
struct Task {
    int id;
    string title;
    string category;
    bool completed;
    Task* next;

    Task(int i, string t, string c) {
        id = i;
        title = t;
        category = c;
        completed = false;
        next = nullptr;
    }
};

// Linked List for Tasks
class TaskList {
private:
    Task* head;
    unordered_map<int, Task*> taskMap;  // Hash Map for quick lookup
    stack<Task*> undoStack;             // Stack for Undo operations
    priority_queue<pair<int, int>> priorityQueue;  // Priority Queue for urgent tasks (priority, taskID)

public:
    TaskList() {
        head = nullptr;
    }

    // Add Task
    void addTask(int id, string title, string category, int priority = 0) {
        if (taskMap.find(id) != taskMap.end()) {
            cout << "\n⚠️ Task ID already exists! Try a different ID.\n";
            return;
        }

        Task* newTask = new Task(id, title, category);
        newTask->next = head;
        head = newTask;

        // Add to Hash Map
        taskMap[id] = newTask;

        // Push to Priority Queue (higher number = higher priority)
        priorityQueue.push({priority, id});

        // Save to Undo Stack
        undoStack.push(newTask);

        cout << "\n✅ Task Added Successfully: " << title << " (Priority: " << priority << ")\n";
    }

    // Display Tasks
    void displayTasks() {
        Task* temp = head;
        if (!temp) {
            cout << "\n📂 No tasks available.\n";
            return;
        }
        cout << "\n📌 Task List:\n";
        cout << "------------------------------------------\n";
        while (temp) {
            cout << "🔹 [" << temp->id << "] " << temp->title << " (Category: " << temp->category << ") ";
            cout << (temp->completed ? "✅ [Completed]\n" : "⏳ [Pending]\n");
            temp = temp->next;
        }
        cout << "------------------------------------------\n";
    }

    // Mark Task as Completed
    void completeTask(int id) {
        if (taskMap.find(id) != taskMap.end()) {
            taskMap[id]->completed = true;
            cout << "\n✅ Task " << id << " marked as completed.\n";
        } else {
            cout << "\n⚠️ Task not found. Please enter a valid Task ID.\n";
        }
    }

    // Undo Last Added Task
    void undoTask() {
        if (!undoStack.empty()) {
            Task* lastTask = undoStack.top();
            undoStack.pop();

            // Remove from linked list
            if (head == lastTask) {
                head = head->next;
            } else {
                Task* temp = head;
                while (temp->next && temp->next != lastTask) {
                    temp = temp->next;
                }
                if (temp->next) {
                    temp->next = temp->next->next;
                }
            }
            // Remove from Hash Map
            taskMap.erase(lastTask->id);
            delete lastTask;
            cout << "\n🔄 Last task addition undone.\n";
        } else {
            cout << "\n⚠️ No actions to undo.\n";
        }
    }

    // Display Urgent Task (Highest Priority)
    void showUrgentTask() {
        if (!priorityQueue.empty()) {
            // Get the highest priority task
            int urgentTaskID = priorityQueue.top().second;
            Task* urgent = taskMap[urgentTaskID];
            cout << "\n🚀 Urgent Task: " << urgent->title << " (Category: " << urgent->category << ")\n";
        } else {
            cout << "\n⚠️ No urgent tasks.\n";
        }
    }

    // Clear all tasks before exiting
    void clearAllTasks() {
        while (head) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
        taskMap.clear();
        while (!undoStack.empty()) undoStack.pop();
        while (!priorityQueue.empty()) priorityQueue.pop();
        cout << "\n🧹 All tasks cleared. Exiting program...\n";
    }
};

// Function to handle input validation
void clearInputBuffer() {
    cin.clear(); // Clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
}

// Driver Code
int main() {
    TaskList taskManager;
    int choice, id, priority;
    string title, category;

    do {
        cout << "\n============================";
        cout << "\n📋  PERSONAL TASK MANAGER";
        cout << "\n============================";
        cout << "\n1️⃣  Add Task";
        cout << "\n2️⃣  Display Tasks";
        cout << "\n3️⃣  Mark Task as Completed";
        cout << "\n4️⃣  Undo Last Task";
        cout << "\n5️⃣  Show Urgent Task";
        cout << "\n6️⃣  Exit";
        cout << "\n============================";
        cout << "\nEnter choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cout << "\n⚠️ Invalid input! Please enter a number from the menu.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\n🔹 Enter Task ID: ";
                cin >> id;
                if (cin.fail()) {
                    cout << "\n⚠️ Invalid ID! Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                cin.ignore(); // Clear newline character
                cout << "🔹 Enter Task Title: ";
                getline(cin, title);
                cout << "🔹 Enter Category: ";
                getline(cin, category);
                cout << "🔹 Enter Priority (0-10): ";
                cin >> priority;
                if (cin.fail() || priority < 0 || priority > 10) {
                    cout << "\n⚠️ Invalid Priority! Please enter a number between 0-10.\n";
                    clearInputBuffer();
                    break;
                }
                taskManager.addTask(id, title, category, priority);
                break;
            case 2:
                taskManager.displayTasks();
                break;
            case 3:
                cout << "\n🔹 Enter Task ID to Complete: ";
                cin >> id;
                if (cin.fail()) {
                    cout << "\n⚠️ Invalid ID! Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                taskManager.completeTask(id);
                break;
            case 4:
                taskManager.undoTask();
                break;
            case 5:
                taskManager.showUrgentTask();
                break;
            case 6:
                taskManager.clearAllTasks();
                break;
            default:
                cout << "\n⚠️ Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
