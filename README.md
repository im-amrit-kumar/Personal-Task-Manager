Personal Task Manager

A simple, interactive Task Manager that allows users to manage their tasks in a user-friendly console interface. This task manager provides various features like adding tasks, displaying tasks, marking tasks as completed, undoing task additions, and displaying the most urgent task based on priority.
The project demonstrates the use of data structures such as Linked List, Priority Queue, Stack, and Hash Map for efficient task management. It provides an engaging user experience with clear input validation and feedback messages for common input errors.


Features
Add Task: Add a task with a unique ID, title, category, and priority.

Display Tasks: 
View a list of all tasks with their status (Completed/Pending).

Mark Task as Completed: 
Mark a task as completed by providing its ID.

Undo Last Task: 
Undo the last task addition, effectively removing it from the task list.

Show Urgent Task: 
Display the task with the highest priority.

Exit and Clear All Tasks: 
Exit the program and clear all tasks from memory.


Data Structures Used

Linked List: 
Used to store tasks as nodes, where each task is connected to the next.

Priority Queue: 
Used to keep track of the most urgent tasks based on priority. The task with the highest priority is always accessible at the top.

Stack: 
Used to store the tasks in the order they are added, enabling an "undo" functionality.

Hash Map: 
Provides a fast way to lookup tasks by their unique ID.


How to Run

Prerequisites:
A C++ compiler such as g++ or an IDE like Code::Blocks or Visual Studio Code with C++ extensions.

Steps:

Clone the repository:
git clone https://github.com/yourusername/task-manager.git

Navigate to the project directory:
cd task-manager

Compile the program:
g++ main.cpp -o task-manager

Run the program:
./task-manager


Usage Example:

Add Task:
Enter a unique Task ID, Title, Category, and Priority (from 0 to 10).
Example: Task 1: "Complete Homework", Category: "Studies", Priority: 5

Mark Task as Completed:
Enter the Task ID to mark a task as completed.

Undo Last Task:
Undo the most recent task addition.

Show Urgent Task:
View the task with the highest priority.

Exit:
Exit the program and clear all tasks.

Code Walkthrough

Task Structure
Each task is stored as a Task Node with the following attributes:
id: Unique identifier for each task.
title: Name or title of the task.
category: Category the task belongs to (e.g., "Work", "Study").
completed: Boolean value to track whether the task is completed or pending.
next: Pointer to the next task (used for the linked list).


TaskList Class
The TaskList class contains the following functions:
addTask: Adds a new task to the task list, hash map, and priority queue.
displayTasks: Displays all tasks in the linked list.
completeTask: Marks a task as completed by its ID.
undoTask: Removes the most recently added task (undo operation).
showUrgentTask: Displays the task with the highest priority.
clearAllTasks: Clears all tasks when the program exits.

Input Validation
The program includes input validation to ensure that users enter valid data (e.g., task ID should be a number, priority should be between 0 and 10).
Invalid inputs are handled gracefully, with appropriate error messages displayed.

User Interface
The user interacts with the program through a simple text-based menu. After choosing an option, users can add tasks, view tasks, complete tasks, and more. The interface is designed to be intuitive and user-friendly.


Example Output


============================
📋  PERSONAL TASK MANAGER
============================
1️⃣  Add Task
2️⃣  Display Tasks
3️⃣  Mark Task as Completed
4️⃣  Undo Last Task
5️⃣  Show Urgent Task
6️⃣  Exit
============================
Enter choice: 1

🔹 Enter Task ID: 1
🔹 Enter Task Title: Complete Homework
🔹 Enter Category: Studies
🔹 Enter Priority (0-10): 5
✅ Task Added Successfully: Complete Homework (Priority: 5)

============================
📋  PERSONAL TASK MANAGER
============================
1️⃣  Add Task
2️⃣  Display Tasks
3️⃣  Mark Task as Completed
4️⃣  Undo Last Task
5️⃣  Show Urgent Task
6️⃣  Exit
============================
Enter choice: 2

📌 Task List:
------------------------------------------
🔹 [1] Complete Homework (Category: Studies) ⏳ [Pending]
------------------------------------------
