#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int x = 2;

void* routine(){
    x++;
    sleep(2);
    printf("value of x : %d\n", x);
    return NULL; // Return NULL to avoid warning
} 

void* routine2(){
    sleep(2);
    printf("value of x : %d\n", x);
    return NULL; // Return NULL to avoid warning
}

int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}