#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t q;
    printf("Before fork\n");
    q=fork();
    if(q == 0){
        printf("I am child, my ID is: %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }else{
        printf("My child's ID is: %d\n", q);
        printf("I am parent, my ID is: %d\n", getpid());
    }
    printf("Common\n");
    return 0;
}