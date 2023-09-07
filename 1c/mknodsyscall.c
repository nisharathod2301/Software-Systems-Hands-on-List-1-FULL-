/*
============================================================================
Name : 1c.c
Author : Nisha Rathod
Description : Create the following types of a files using (i) shell command (ii) system call c.FIFO (mkfifo Library Function or mknod system call)
Date: 6th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    const char *fifopath = "/Users/nisharathod/Desktop/1c -FIFO/mknodeOutput";
    
    if(mknod(fifopath, S_IFIFO | 0666, 0) == -1){
        perror("mknod");
        exit(EXIT_FAILURE);
        //0 or EXIT_SUCCESS: The statements exit(EXIT_SUCCESS) and exit(0) mean that the program has terminated successfully without any errors or interruptions.
        // 1 or EXIT_FAILURE: The statements exit(1) and exit(EXIT_FAILURE) mean that the program terminated abruptly with an error.
    }
    printf("FIFO file was created at : %s", fifopath);
    return 0;
}
