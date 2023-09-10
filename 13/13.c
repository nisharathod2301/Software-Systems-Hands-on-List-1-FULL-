/*
============================================================================
Name : 13.c
Author : Nisha Rathod
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 5th Sept, 2023.
============================================================================
*/

/*
 select() replaces the given descriptor sets with
subsets consisting of those descriptors that are ready for the requested
operation.  select() returns the total number of ready descriptors in all
the sets
*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>

int main() {
    fd_set rfds;
    struct timeval tv; //for specifying timeout
    int retval; //return value of select
    FD_ZERO(&rfds); //clears all file descriptrors
    FD_SET(0, &rfds); //adds file descriptor 0(stdin) to rdfs indicating we want to monitor stdin
    tv.tv_sec = 10; //sets timeout for select, if no data available in this time select will return 0
    // (1) represents the highest file descriptor number in the set (0 for stdin) plus 1.
    retval = select(1, &rfds, NULL, NULL, &tv);
    //3-writability 4-exceptions
    if(retval) printf("Data was available in 10 seconds\n");
    else printf("Data was not available in 10 seconds\n");
    return 0;
}
