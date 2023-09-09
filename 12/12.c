/*
============================================================================
Name : 12.c
Author : Nisha Rathod
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 5th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
        printf("Enter the file name\n");
        return 1;
        }
        const char *file = argv[1];
        int fd = open(file, O_RDONLY | O_APPEND, 0466);

        if (fd == -1) {
            perror("Error opening file");
        return 1;
        }

        int flags = fcntl(fd, F_GETFL);
        if (flags == -1) {
            perror("Error getting file flags");
            return 1;
        }
    //flags contains a combination of file access mode and other file-related flags set during the file's opening.
    //it's a bitmask that extracts the access mode bits from the flags.
        if ((flags & O_ACCMODE) == O_RDONLY) printf("Read-only ");
        if ((flags & O_ACCMODE) == O_WRONLY) printf("Write-only ");
        if ((flags & O_ACCMODE) == O_RDWR) printf("Read-write ");
        if ((flags & O_ACCMODE) == O_APPEND) printf("Append ");
        if ((flags & O_ACCMODE) == O_CREAT) printf("Create ");

        printf("\n");
        close(fd);
        return 0;
}
