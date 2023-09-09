/*
============================================================================
Name : 7.c
Author : Nisha Rathod
Description :Write a program to copy file1 into file2 ($cp file1 file2).
Date: 5th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(int argc, char *argv[]){
    char *spath;
    char *dpath;
    int sfd, dfd;
    int sreadcount;
    int dwritecount;
    
    char *buffer[100];
    if(argc !=3 ){
        printf("Pass the source and destination name:");
    }
    else{
        spath = argv[1];
        dpath = argv[2];
        
        sfd = open(spath, O_RDONLY);
        dfd = open(dpath, O_CREAT | O_RDWR, S_IRWXU);
        
        if(sfd == -1 || dfd == -1){
            perror("Error while opening");
            exit(EXIT_FAILURE);
        }
        
        while((sreadcount = read(sfd, buffer, 100))>0){
            dwritecount = write(dfd, buffer, sreadcount);
            if(dwritecount == -1){
                perror("Error while writing");
            }
        }
        if(sreadcount == -1){
            perror("Error while reading");
        }
        else{
            printf("File copied sucessfully");
        }
        close(sfd);
        close (dfd);
    }
    
}

