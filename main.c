#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char *task;
    char *date_echeance;
    int priority;
    int completed;
} Task;
Task *tasks = NULL;
int length = 0;

void addTask(const char *task,int priority,char *date_echeance);
void listTask();
void editTask();
void deleteTask();


void main() {
   printf("## WELCOME TO YOUR TASK MANAGEMENT APP ##\n");
    char task[] = "first task";
    int priority = 3;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("%s", asctime(tm));
    addTask(task,priority,asctime(tm));
    listTask();
    free(tasks);
}


void addTask(const char *task,int priority,char *date_echeance) {
    tasks = (Task*)realloc(tasks,(length + 1) * sizeof(Task));
    tasks[length].task = (char *)malloc(strlen(task) + 1);
    tasks[length].date_echeance = (char *)malloc(strlen(date_echeance) + 1);
    tasks[length].completed = 0;
    tasks[length].priority = priority;
    strcpy(tasks[length].task,task);
    strcpy(tasks[length].date_echeance,date_echeance);
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
        printf("%d. %s [%s][%d][%s]\n",i + 1,tasks[i].task,status,tasks[i].priority,tasks[i].date_echeance);
    }
}