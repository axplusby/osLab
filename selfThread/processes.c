#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
    int x = 2;
    int pid = fork();
    if (pid == -1){
        return 1;
    }
    if (pid == 0){
        x++;
    }
    sleep(2);
    printf("value of x : %d\n", x);

    printf("Process id is : %d\n", getpid());
    if(pid != 0){
        wait(NULL);
    }
    return 0;
}