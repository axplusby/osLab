#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int array[1000];

int partial_sums[5];

int total_sum = 0;

void* sum_array_chunk(void* arg) {
    int thread_id = *(int*)arg;
    int start_index = thread_id * 200;
    int end_index = start_index + 200;

    int local_sum = 0;
    for (int i = start_index; i < end_index; ++i) {
        local_sum += array[i];
    }

    partial_sums[thread_id] = local_sum;
    return NULL;  
}



int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 1000; ++i) {
        array[i] = rand() % 200;  
    }

    pthread_t threads[5];
    int thread_ids[6];

    for (int i = 0; i < 5; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_array_chunk, &thread_ids[i]);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 5; ++i) {
        total_sum += partial_sums[i];
    }
    
    int array_sum = 0;
    for(int i=0; i <1000; i++){
        array_sum += array[i];
    }
    printf("Total sum of the array is %d\n", total_sum);

    printf("Total without threads %d\n", array_sum);

    if (total_sum == array_sum){
        printf("True\n");
    }else{
        printf("False\n");
    }

    return 0;
}