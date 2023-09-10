/*
============================================================================
Name : 26.c
Author : Nisha Rathod
Description : Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 6th Sept, 2023.
============================================================================
*/
#include <unistd.h> // Import for `execl` library function

void main()
{
    char *executable_path = "b.out";
    char *arg = "21.c";

    execl(executable_path, executable_path, arg, NULL);
}
