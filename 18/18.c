/*
============================================================================
Name : 18.c
Author : Nisha Rathod
Description : Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
 Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
 Date: 5th Sept, 2023.
============================================================================
*/
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
//First run init.c to set initial values
struct ticket{
    int id;
    int number;
};

int main(int argc, char *argv[]) {
    if(argc < 2) {
        perror("Please enter the file name\n");
        return 1;
    }
    char *file = argv[1];
    int fd = open(file, O_RDWR, 0666);
    
    if(fd == -1) {
        perror("Some error occurred\n");
        return 1;
    }
    
    int no;
    printf("Enter the Train number (1,2,3) you want to modify or see: ");
    scanf("%d", &no);
    printf("1. If you want to modify the train id\n2. If you want to book ticket.\n3.If you want to print the details only\n");
    int ch;
    scanf("%d", &ch);
    
    //Out of bound checking
    if(ch > 3 || ch < 1 || no < 1 || no > 3) {
        perror("Wrong choices\n");
        return 1;
    }

    
    struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start =(no-1)*sizeof(struct ticket) ; //calculates the byte offset in the file where the specific ticket's data is located.
        lock.l_len = sizeof(struct ticket); //So we are only locking data of one single ticket
        lock.l_pid = getpid();
    
    
    struct ticket t;
    
    //This if block is for when the user wants to modify the train id
    if(ch == 1) {
        int nid;
        printf("Enter the new train id: ");
        scanf("%d", &nid);
        
        lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET); //going to start of that train
        fcntl(fd, F_SETLKW, &lock);
        read(fd, &t, sizeof(t));
        t.id = nid;
        lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
        
        printf("Changing the ticket id in system\n");
        write(fd, &t, sizeof(t));
        printf("Changed successfully please press enter to continue.\n");
        getchar();
        getchar();
        lock.l_type = F_UNLCK;
            fcntl(fd, F_SETLK, &lock);
            printf("Id has been changed.\n");
    }
    //if user whats to book the ticket
    else if(ch == 2) {
        printf("Trying to access the details\n");
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                fcntl(fd, F_SETLKW, &lock);
                read(fd, &t, sizeof(t));
                t.number = t.number+1;
        printf("Booked ticket number %d in the train with id %d \n", t.number, t.id);
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                write(fd, &t, sizeof(t));
                printf("Booked successfully please press enter to continue.\n");
                getchar();
                getchar();
                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Thank you.\n");
        }
    //user wants to pront the details
    else if(ch == 3) {
        printf("Trying to access the details\n");
        lock.l_type = F_RDLCK;
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                fcntl(fd, F_SETLKW, &lock);
        printf("Reading the details.\n");
                read(fd, &t, sizeof(t));
                printf("Train id %d has %d tickets booked.\nPress Enter to Continue.\n", t.id, t.number);
                getchar();
                getchar();
                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Read successfully.\n");
        }
    return 0;
}
