/*
============================================================================
Name : infiniteloop.c
Author : Nisha Rathod
Description : 2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 5th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Hello, World!\n");
        usleep(1000000);  // Sleep for 1 second (1,000,000 microseconds)
    }
    return 0;
}

