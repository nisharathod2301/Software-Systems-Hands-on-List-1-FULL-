/*
============================================================================
Name : execv.c
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    char *args[]={"ls","-Rl",NULL};
    if(execv("/bin/ls",args)==-1){
        perror("execv");
        exit(EXIT_FAILURE);
    }
    return 0;
}
