#include<pthread.h>
#include<stdio.h>
#include<stdlib.h> // for atoi
int sum;
void *runner(void *param);
int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    printf(" The Sum is = %d\n The tid is = %lu\n", sum, (unsigned long)tid);
    printf(" argv[] are %s , %d\n", argv[0], atoi(argv[1]));
}

void * runner(void *param){
    int i, upper = atoi((char *) param); // array to integer --> atoi (// Cast param to char* and convert to int)
    sum = 0;
    for (i = 1; i <= upper; i++){
        sum = sum + i;
    }
    pthread_exit(0);
}

/*
how to run
gcc atchalaCThread.c -o p -lpthread

./p 5
 The Sum is = 15
 The tid is = 6128087040
argv[] are ./p , 5
*/