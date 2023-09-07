#include<stdio.h>
#include<unistd.h>
int main(){
    int op = link("sample.txt","HardLinktoSample");
    if(op==-1){
        perror("Error: ");
    }
    return 0;
}
