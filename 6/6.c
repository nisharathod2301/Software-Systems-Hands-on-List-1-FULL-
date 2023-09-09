/*
============================================================================
Name : 6.c
Author : Nisha Rathod
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
 Date: 5th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

void main(){
    char buffer[100];
    int rcnt, wcnt;
    while(1){
        rcnt = read(STDIN_FILENO, buffer, 1);
        wcnt = write(STDOUT_FILENO, buffer, 1);
        
        if(rcnt == -1 || wcnt == -1){
            perror("Error occured while reading/writing");
            break;
        }
    }
}
