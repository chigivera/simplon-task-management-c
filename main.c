#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define EXIT_FAILURE 1


typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char *task;
    Date date;
    int priority;
    int completed;
} Task;

Task *tasks = NULL;
int length = 0;

void addTask(const char *task, int priority, Date date);
void listTask();
void editTask(int index);
void deleteTask(int index);
void completeTask(int index);
void filterByPrio(int priority);
void filterByDate(Date date);
void freeTasks();

int main() {
    printf("## WELCOME TO YOUR TASK MANAGEMENT APP ##\n");
    char task[100];
    int priority;
    Date date;

    // Add some initial tasks for demonstration
    addTask("Buy groceries", 2, (Date){17, 3, 2024});
    addTask("Finish report", 1, (Date){20, 3, 2024});

    int choice;
    do {
        printf("\n1. Add Task\n2. List Tasks\n3. Edit Task\n4. Delete Task\n5. Complete Task\n6. Filter by Priority\n7. Filter by Date\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", task);
                printf("Enter priority (1-5): ");
                scanf("%d", &priority);
                printf("Enter due date (day month year): ");
                scanf("%d %d %d", &date.day, &date.month, &date.year);
                addTask(task, priority, date);
                break;
            case 2:
                listTask();
                break;
            case 3:
                printf("Enter index of task to edit: ");
                int editIndex;
                scanf("%d", &editIndex);
                editTask(editIndex - 1); // Adjust for 0-based indexing
                break;
            case 4:
                printf("Enter index of task to delete: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                deleteTask(deleteIndex - 1); // Adjust for 0-based indexing
                break;
            case 5:
                printf("Enter index of task to mark as completed: ");
                int completeIndex;
                scanf("%d", &completeIndex);
                completeTask(completeIndex - 1); // Adjust for 0-based indexing
                break;
            case 6:
                printf("Enter priority to filter by: ");
                int prio;
                scanf("%d", &prio);
                filterByPrio(prio);
                break;
            case 7:
                printf("Enter date to filter by (day month year): ");
                scanf("%d %d %d", &date.day, &date.month, &date.year);
                filterByDate(date);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    // Free allocated memory before exiting
    freeTasks();

    return 0;
}


void addTask(const char *task, int priority, Date date) {
    tasks = realloc(tasks, (length + 1) * sizeof(Task));
    if (tasks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    tasks[length].task = strdup(task);
    tasks[length].date = date;
    tasks[length].priority = priority;
    tasks[length].completed = 0;
    length++;
    printf("Task added\n");
}

void listTask() {
    printf("Tasks:\n");
    for (int i = 0; i < length; i++) {
        char status[10];
        if (tasks[i].completed == 1) {
            strcpy(status, "done");
        } else {
            strcpy(status, "pending");
        }
        printf("%d. %s [Due: %d-%02d-%02d][Priority: %d][%s]\n", i + 1, tasks[i].task, tasks[i].date.year, tasks[i].date.month, tasks[i].date.day, tasks[i].priority, status);
    }
}

void editTask(int index) {
    if (index < 0 || index >= length) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter new task description: ");
    scanf(" %[^\n]", tasks[index].task);
    printf("Enter new priority (1-5): ");
    scanf("%d", &tasks[index].priority);
    printf("Enter new due date (day month year): ");
    scanf("%d %d %d", &tasks[index].date.day, &tasks[index].date.month, &tasks[index].date.year);

    printf("Task at index %d edited\n", index + 1);
}

void deleteTask(int index) {
    if (index < 0 || index >= length) {
        printf("Invalid index\n");
        return;
    }

    free(tasks[index].task);
    for (int i = index; i < length - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    length--;

    printf("Task at index %d deleted\n", index + 1);
}

void completeTask(int index) {
    if (index < 0 || index >= length) {
        printf("Invalid index\n");
        return;
    }

    tasks[index].completed = 1;
    printf("Task at index %d marked as completed\n", index + 1);
}
void filterByPrio(int priority) {
    printf("Tasks with priority %d:\n", priority);
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (tasks[i].priority == priority) {
            char status[10];
            if (tasks[i].completed == 1) {
                strcpy(status, "done");
            } else {
                strcpy(status, "pending");
            }
            printf("%d. %s [Due: %d-%02d-%02d][Priority: %d][%s]\n", i + 1, tasks[i].task, tasks[i].date.year, tasks[i].date.month, tasks[i].date.day, tasks[i].priority, status);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks with priority %d\n", priority);
    }
}

void filterByDate(Date date) {
    printf("Tasks due on %d-%02d-%02d:\n", date.year, date.month, date.day);
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (tasks[i].date.day == date.day && tasks[i].date.month == date.month && tasks[i].date.year == date.year) {
            char status[10];
            if (tasks[i].completed == 1) {
                strcpy(status, "done");
            } else {
                strcpy(status, "pending");
            }
            printf("%d. %s [Priority: %d][%s]\n", i + 1, tasks[i].task, tasks[i].priority, status);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks due on %d-%02d-%02d\n", date.year, date.month, date.day);
    }
}

void freeTasks() {
    for (int i = 0; i < length; i++) {
        free(tasks[i].task);
    }
    free(tasks);
}
