/*
============================================================================
Name : 1a.c
Author : Nisha Rathod
Description : Create the following types of a files using (i) shell command (ii) system call a. soft link (symlink system call)
Date: 5th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    int op = symlink("/crap/new.txt", "news");
    if(op==-1){
        printf("error");
    }
    return 0;
}
