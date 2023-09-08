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
#include<unistd.h>
#include<stdlib.h>
int main(){
    if(execl("/bin/ls","ls","-Rl",NULL)==-1){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    printf("execl file was created sucessfully");
    return 0;
}
