/*
============================================================================
Name : 1b.c
Author : Nisha Rathod
Description : Create the following types of a files using (i) shell command (ii) system call b. hard link (link system call)
Date: 5th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
    int op = link("sample.txt","HardLinktoSample");
    if(op==-1){
        perror("Error: ");
    }
    return 0;
}
