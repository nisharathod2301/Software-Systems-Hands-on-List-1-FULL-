#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
void main(){
    while(1){
        creat("./f1",O_CREAT);
        creat("./f2",O_CREAT);
        creat("./f3",O_CREAT);
        creat("./f4",O_CREAT);
        creat("./f5",O_CREAT);
        break;
    }
}
