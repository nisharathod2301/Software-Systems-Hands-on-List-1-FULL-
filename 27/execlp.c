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
    if(execlp("ls","ls","-Rl",NULL)==-1){
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    printf("execlp was sucessful!");
    return 0;
}
