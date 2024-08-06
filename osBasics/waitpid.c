#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    pid_t p, w;
    int w1, wstatus;
    printf("Before fork\n");
    p=fork();
    if(p == 0){
        printf("I am child, my ID is: %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }else{
        // w=wait(NULL);
        w1=wait(&wstatus);
        printf("Status is %d\n",WIFEXITED(wstatus));
        printf("PID of chid(i.e. Terminated): %d\n",w1);
        printf("My child's ID is: %d\n", p);
        printf("I am parent, my ID is: %d\n", getpid());
    }
    printf("Common\n");
    return 0;
}