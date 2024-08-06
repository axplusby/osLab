#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Before exit() sys call");
    exit(0);
    printf("After exit() sys call");
    return 0;
}