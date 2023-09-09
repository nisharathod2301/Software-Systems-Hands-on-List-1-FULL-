/*
============================================================================
Name : 5.c
Author : Nisha Rathod
Description :  Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 5th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
void main(){
    while(1){
        creat("./f1",O_CREAT);
        creat("./f2",O_CREAT);
        creat("./f3",O_CREAT);
        creat("./f4",O_CREAT);
        creat("./f5",O_CREAT);
        break;
    }
}
