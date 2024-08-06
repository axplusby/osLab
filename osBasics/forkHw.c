#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    printf("Hello process 1\n");
    fork();
    fork();
    printf("Hello World!\n");
    return 0;
}