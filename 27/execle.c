/*
============================================================================
Name : execle.c
Author : Nisha Rathod
Description : Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
 d. execv
 e. execvp
Date: 5th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    char *arr[] ={NULL};
    if(execle("/bin/ls","ls","-Rl",NULL,arr)==-1){
        perror("execle");
        exit(EXIT_FAILURE);
    }
    return 0;
}
