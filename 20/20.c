/*
============================================================================
Name : 20.c
Author : Nisha Rathod
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 6th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int old = nice(0); //Stores  original priority of the process before any modification.
    int pid = getpid();
    printf("Process id is: %d\n", pid);
    printf("\nOld priority value: %d", old);
    getchar();
    int new = nice(-10); //decrease the process's priority by 10
    printf("\nNew Priority value: %d\n", new);
    getchar();
    return 0;
}
