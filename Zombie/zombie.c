#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
   pid_t t;
   t=fork();
   if(t==0){
       printf("Child having id %d\n",getpid());
    }else{
        printf("Parent having id %d\n",getpid());
        sleep(15);
    }
    return 0;
}
