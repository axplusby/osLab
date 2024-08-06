#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    pid_t p, q;
    printf("Before fork\n");
    p=fork();
    if(p == 0){
        printf("I am First child, my ID is: %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }else{// parent
        q=fork();
        if(q==0){//child 2
            printf("I am second child having PID %d\n", getpid());
            printf("Second child's Parent ID is: %d\n", getppid());
        }else{
            // wait(NULL)
            waitpid(p, NULL, 0);
            printf("I am parent having ID: %d\n", getpid());
            printf("My First child's PID is: %d\n", p);
            printf("My Second child's PID is %d\n", q);
        }
    }
    return 0;
}


/*
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p, q;
    printf("Before fork\n");
    p = fork();
    if (p == 0) {
        printf("I am First child, my ID is: %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    } else {  // parent
        waitpid(p, NULL, 0);
        q = fork();
        if (q == 0) {  // child 2
            printf("I am second child having PID %d\n", getpid());
            printf("Second child's Parent ID is: %d\n", getppid());
        } else {
            waitpid(q, NULL, 0);
            printf("I am parent having ID: %d\n", getpid());
            printf("My First child's PID is: %d\n", p);
            printf("My Second child's PID is %d\n", q);
        }
    }
    return 0;
}
*/