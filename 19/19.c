/*
============================================================================
Name : 19.c
Author : Nisha Rathod
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 6th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    int pid;

    // Start measuring time
    start = rdtsc();

    // Perform getpid system call
    pid = getpid();

    // End measuring time
    end = rdtsc();

    // Calculate elapsed time
    uint64_t elapsed = end - start;

    printf("Process ID: %d\n", pid);
    printf("Time taken by getpid system call: %lu CPU cycles\n", elapsed);

    return 0;
}
