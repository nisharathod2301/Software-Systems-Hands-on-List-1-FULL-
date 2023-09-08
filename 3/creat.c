/*
============================================================================
Name : creat.c
Author : Nisha Rathod
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
 Date: 5th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(int argc, char *argv[]){
    char *filename; //Don't use const char
    int fd;
    
    if(argc!=2){
        printf("Pass the file to open as an argument:\n");
    }
    else{
        filename = argv[1];
        fd = creat(filename, S_IRWXU);
        if(fd == -1){
            perror("Error while creating the file");
        }
        else{
            printf("File was sucessfully created with file decriptor: %d",fd);
        }
    }
}
