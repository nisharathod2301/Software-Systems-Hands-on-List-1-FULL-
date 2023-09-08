/*
============================================================================
Name : 4_O_EXCL.c
Author : Nisha Rathod
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 5th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h> //write

int main(int argc, char *argv[]){
    char *filename;
    int fd;
    
    if(argc!=2){
        write(STDOUT_FILENO, "Pass the file to be opened as the argument\n",43);
    }
    else{
        filename = argv[1];
        fd = open(filename, O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
 //the file should be opened for both reading and writing.
        if(fd==-1){
            perror("Error while opening the file!");
        }
        else{
            printf("File created with file descriptor: %d",fd);
        }
    }
}


