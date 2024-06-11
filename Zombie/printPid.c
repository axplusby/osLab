
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
    for(int i =0; i<5; i++){
        pid_t p=fork();
        if(p==0){
            printf("Child (pid=%u)\n", getpid());
        }else{
            printf("Parent (pid=%u) created child (pid=%u)\n", getpid(), p);
        }
    }
    return 0;
}
