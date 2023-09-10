//Using this code to give trains an id and initial value of ticket number

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

//This structures has information about train ids and respective ticket number
struct ticket {
    int id;
    int number;
};


int main(int argc, char *argv[]) {
    if(argc < 2) {
        perror("Please enter the file name\n");
        return 1;
    }
    char *file = argv[1];
    int fd = open(file, O_RDWR | O_CREAT);
    if(fd == -1) {
        perror("Some error occurred while file opening\n");
        return 1;
    }
    
    
    int i = 1;
    while(i <= 3) { //Right now we give 3 trains as input and ask user to give them ids and initial number
        struct ticket t;
        printf("\nPlease enter train id: ");
        scanf("%d", &t.id);
        printf("\nPlease enter the ticket number: ");
        scanf("%d", &t.number);
        write(fd, &t, sizeof(t));
        printf("\n");
        i++;
    }
    i=1;
    lseek(fd, 0, SEEK_SET); //reposition the cursor to the start of a file before reading or writing data from the beginning
    while(i<=3) {
        struct ticket t;
        read(fd, &t, sizeof(t));
        printf("The train with id %d has current ticket number: %d\n", t.id, t.number);
        i++;
    }
    return 0;
}
