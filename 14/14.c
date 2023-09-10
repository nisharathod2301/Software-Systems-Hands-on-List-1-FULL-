/*
============================================================================
Name : 14.c
Author : Nisha Rathod
Description : Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file.
Date: 5th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter the file name\n");
        return 1;
    }
    char *file = argv[1];
    struct stat info;

    stat(file, &info); //stat function is used to gather information about the specified file and store it in the struct stat variable named info.

    printf("%s is: ",file);

    
    //st_mode is a field within the struct stat structure that represents the mode of the file. The file mode includes various information, such as file type (e.g., regular file, directory), permissions (read, write, execute), and more.
    
    //S_IFMT (file type mask) constant is used for bitwise masking to extract the file type information from the st_mode field. It represents the portion of st_mode that contains the file type information.
        switch (info.st_mode & S_IFMT) {
            case S_IFBLK:  printf("block device\n");            break;
            case S_IFCHR:  printf("character device\n");        break;
            case S_IFDIR:  printf("directory\n");               break;
            case S_IFIFO:  printf("FIFO/pipe\n");               break;
            case S_IFLNK:  printf("symlink\n");                 break;
            case S_IFREG:  printf("regular file\n");            break;
            case S_IFSOCK: printf("socket\n");                  break;
              default:       printf("unknown?\n");                break;
        }

    
    return 0;
}
