# Task Management Application

This is a simple command-line task management application written in C. It allows users to manage their tasks, including adding, listing, editing, deleting, and marking tasks as completed.

## Features

- **Add Task**: Users can add a new task specifying the task description, priority, and due date.
- **List Tasks**: Users can list all tasks along with their details such as description, due date, priority, and completion status.
- **Edit Task**: Users can edit an existing task to update its description, priority, or due date.
- **Delete Task**: Users can delete a task from the list.
- **Complete Task**: Users can mark a task as completed.
- **Memory Management**: The application dynamically allocates memory for tasks and properly frees it to prevent memory leaks.
- **Menu Interface**: The application provides a simple menu-based interface for easy navigation.

## Getting Started

### Prerequisites

To run this application, you need to have a C compiler installed on your system.

### Installation

1. Clone this repository to your local machine:


```git clone https://github.com/chigivera/simplon-task-management-c```

2. Navigate to the project directory:

```cd simplon-task-management-c```

3. Compile the source code:

```gcc -o task_manager main.c```

4. Run the executable:

```./task_manager```

## Usage

Upon running the application, you will be presented with a menu where you can choose various options to manage tasks.

1. **Add Task**: Enter details for the new task when prompted.
2. **List Tasks**: View all tasks along with their details.
3. **Edit Task**: Enter the index of the task to edit and provide new details.
4. **Delete Task**: Enter the index of the task to delete.
5. **Complete Task**: Enter the index of the task to mark as completed.
6. **Exit**: Quit the application.

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License