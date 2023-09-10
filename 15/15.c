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
extern char **environ; //array of strings that hold env variables

int main() {
    char **env = environ; //a pointer that points same thing that environ points to

    while (*env) { //till current env variable is not null
    if (strncmp(*env, "USER", 4) == 0) printf("%s\n", *env);
        env++;
    }

    return 0;
}
