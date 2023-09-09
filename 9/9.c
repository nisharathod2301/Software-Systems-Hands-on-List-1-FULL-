/*
============================================================================
Name : 9.c
Author : Nisha Rathod
Description : Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
 Date: 5th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter the file name\n");
        return 1;
    }
    char *file = argv[1];
    struct stat info; //info is declared to hold information about the file.

    stat(file, &info); //Retrieves information about file and stores it to info

    printf("inode: %lu\n", info.st_ino);  //inode, uniquely identifies a file
    printf("number of hard links: %lu\n", info.st_nlink); //file with multiple hardlinks shares same inode number
    printf("uid: %d\n", info.st_uid); //uid is numeric identifier assosiated with a user
    printf("gid: %d\n", info.st_gid); // assosiated with a group
    printf("size: %ld\n", info.st_size);
    printf("block size: %ld\n", info.st_blksize);
    printf("number of blocks: %ld\n", info.st_blocks);
    printf("time of last access: %s\n", ctime(&info.st_atime));
    printf("time of last modification: %s\n", ctime(&info.st_mtime));
    printf("time of last status change: %s\n", ctime(&info.st_ctime));
    
    return 0;
}
