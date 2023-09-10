/*
============================================================================
Name : 21.c
Author : Nisha Rathod
Description : Write a program, call fork and print the parent and child process id.
 Date: 6th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main() {
    int pid, cpid, c;
    if(!(c=fork())) { // return value of fork() is 0 in the child process and the child's process ID in the parent process.
        cpid = getpid();
        printf("Child's process id is: %d\n", cpid);
    } else {
        pid = getpid();
        printf("Parent's process id is: %d\n", pid);
    }
    wait(0);
    return 0;
}
