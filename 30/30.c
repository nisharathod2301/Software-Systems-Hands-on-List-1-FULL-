/*
============================================================================
Name : 30.c
Author : Nisha Rathod
Description : Write a program to run a script at a specific time using a Daemon process.
 Date: 6th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

void makeDaemon(time_t now, time_t actual) {
    setsid(); //This is a common step in creating daemon processes to ensure they are completely detached from the terminal and can continue running in the background even if the terminal is closed.
    chdir("/");
    umask(0); //to have the permissions specified when they are created, without any restrictions imposed by the process's umask.
    printf("Childs pid is: %d and parents id is: %d\n", getpid(), getppid()); //Daemon
    printf("It is going to wait until correct time\n");
    do {
        time(&now);
    } while (difftime(actual, now) > 0);  // calculates the difference in seconds between two time_t values.
    printf("Time matched\n");
    exit(0);
}

int main() {
    time_t now, actual;
    struct tm *deadline;
    time(&now);
        deadline = localtime(&now);

        deadline->tm_hour = 03;
        deadline->tm_min = 26;
        deadline->tm_sec = 0;
    actual = mktime(deadline);
    if(!fork()) {
        makeDaemon(now, actual);
    }
    else {
        printf("Parent %d is going to exit\n", getpid());
    }
    return 0;
}
