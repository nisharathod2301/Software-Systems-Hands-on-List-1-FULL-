/*
============================================================================
Name : 15.c
Author : Nisha Rathod
Description : Write a program to display the environmental variable of the user (use environ).
Date: 5th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern char **environ;

int main() {
    char **env = environ;

    while (*env) {
    if (strncmp(*env, "USER", 4) == 0) printf("%s\n", *env);
        env++;
    }

    return 0;
}
