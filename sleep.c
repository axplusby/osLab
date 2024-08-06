//          Sleep() System call:-
// It will keeps a running process in sleep state up to a specified time seconds. 
// it allows a process to relinquish the CPU and enter a sleep state for set period.

#include<stdio.h>
#include<unistd.h>
int main()
{
    int i,pid;
    pid = fork();
    if(pid ==0)
    {
        printf("\n Child process sarted");
        for(i=0; i<10; i++)
        {
            sleep(5);
            printf("\n i = %d",i);
        }
        printf("\nchild prcess ends ");
    }
    else{
        printf("\nI am parent");
        printf("\nParent process ends");

    }
    return 0;
}