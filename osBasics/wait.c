#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    pid_t q;
    printf("Before fork [Child is sleeping for 10 sec, & Parent is waiting to complete the child Process.\n");
    q=fork();
    if(q == 0){// child
        sleep(10);
        printf("I am child, my ID is: %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }else{// parent
        wait(NULL);
        printf("My child's ID is: %d\n", q);
        printf("I am parent, my ID is: %d\n", getpid());
    }
    printf("Common\n");
    return 0;
}