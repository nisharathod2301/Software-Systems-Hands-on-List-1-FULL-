/*
============================================================================
Name : 11.c
Author : Nisha Rathod
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
 Date: 5th Sept, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter the file name\n");
        return 1;
    }
    char *file = argv[1];
    int fd = open(file, O_WRONLY | O_CREAT, 0666);
    if(fd == -1) {
        perror("Some error in opening of files\n");
        return 1;
    }
    int dup_fd = dup(fd);
    if(dup_fd == -1) {
        perror("Error in opening of files\n");
        return 1;
    }
    int dup2_fd = dup2(fd, 7);
    if(dup2_fd == -1) {
        perror("Error in opening of files\n");
        return 1;
    }
    
    char data[] = "This is from initial fd \n";
    char data2[] = "This data is inserted using dup() \n ";
    char data3[] = "This data is inserted using dup2() \n";
    char data4[] = "Data inserted after adding O_APPEND flag from fcntl \n";
    char data5[] = "Data inserted after creating fd using fcntl.\n";

    write(fd, data, strlen(data));
    write(dup_fd, data2, strlen(data2));
    write(dup2_fd, data3, strlen(data3));

    fcntl(fd, F_SETFL, O_APPEND);
    //F_SETFL specfies we want to set specific file status flag
    //O_APPEND is used to set append mode on fd
    write(fd,data4, strlen(data4));

    int fcntl_dup_fd = fcntl(fd, F_DUPFD, 0);
    //0 ensures we get minimum fd value, what ever number we write there will be the lowest threshold, and os will assign fd greater than or equal to that number
    if(fcntl_dup_fd == -1) {
        perror("Some error in opening of file\n");
        return 1;
    }
    write(fcntl_dup_fd, data5, strlen(data5));

    close(fd);
    close(dup_fd);
    close(dup2_fd);
    close(fcntl_dup_fd);

    return 0;
}
