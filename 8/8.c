/*
============================================================================
Name : 8.c
Author : Nisha Rathod
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

Date: 5th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void main(int argc, char *argv[]){
    char *filename;
    int fd;
    char buffer[1];
    if(argc != 2){
        printf("Pass file to be read as the argument");
    }
    else{
        filename = argv[1];
        fd = open(filename, O_RDONLY);
        
        if(fd == -1){
            perror("Error opening file");
        }
        else{
            while(read(fd, buffer, 1)==1){
                if(buffer[0] == '\n'){
                    write(STDOUT_FILENO, "\n", 1);
                }
                else{
                    write(STDOUT_FILENO, buffer, 1);
                }
            }
            write(STDOUT_FILENO, "\n", 1);
            close(fd);
        }
    }
}
