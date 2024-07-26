#include<stdio.h>
#include<unistd.h>
int main(){
    int i, pid;
    pid = fork();
    if(pid == 0){
        printf("Child Process Started\n");
        for (i = 0; i < 10; i++){
            sleep(1);
            printf("\ni=%d", i);
        }
        printf("\nChild Process Ends");
    }else{
        printf("\nI am Parent Process.");
        printf("\nParent Process Ends.");
    }
    return 0;
}