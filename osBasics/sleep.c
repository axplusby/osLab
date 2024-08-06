#include<stdio.h>
void main(){
    int sleepTime;
    printf("Going to sleep, For how many second?\n");
    scanf("%d", &sleepTime);
    printf("Going to sleep for %d Sec.\n",sleepTime);
    sleep(sleepTime);
    printf("Waked up after %d second.",sleepTime);
}