#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void addTask(const char *task,int priority);
void listTask();
void editTask(int index);
void deleteTask(int index);
void completeTask(int index);
void filterByPrio(int priority);
void filterByDate(Date date);


void main() {
   printf("## WELCOME TO YOUR TASK MANAGEMENT APP ##\n");
    char task[] = "first task";
    int priority = 3;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    Date date = {tm->tm_mday,tm->tm_mon + 1,tm->tm_year + 1900};
    printf("%d %d %d\n",date.day,date.month,date.year);
    addTask(task,priority);
    listTask();
    free(tasks);
}


void addTask(const char *task,int priority) {
    tasks = (Task*)realloc(tasks,(length + 1) * sizeof(Task));
    tasks[length].task = (char *)malloc(strlen(task) + 1);
    tasks[length].completed = 0;
    tasks[length].priority = priority;
    strcpy(tasks[length].task,task);
    length++;
    printf("task added\n");
}

void listTask() {
    char status[10];
    for( int i = 0 ; i< length ; i++) {
        if(tasks[i].completed == 1) {
            strcpy(status,"done");
        } else {
            strcpy(status,"pending");
        }
        printf("%d. %s [%s][%d]\n",i + 1,tasks[i].task,status,tasks[i].priority);
    }
}

