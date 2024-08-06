#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int array[1000];
int total_sum = 0;

typedef struct {
    int start_index;
    int end_index;
    int *partial_sum;
} ThreadData;

void* sum_array_chunk(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start_index = data->start_index;
    int end_index = data->end_index;

    int local_sum = 0;
    for (int i = start_index; i < end_index; ++i) {
        local_sum += array[i];
    }

    *(data->partial_sum) = local_sum;  
    pthread_exit(NULL);  
}

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 1000; ++i) {
        array[i] = rand() % 200;  
    }

    pthread_t threads[5];
    ThreadData thread_data[5];
    int partial_sums[5];  

    for (int i = 0; i < 5; ++i) {
        thread_data[i].start_index = i * 200;
        thread_data[i].end_index = thread_data[i].start_index + 200;
        thread_data[i].partial_sum = &partial_sums[i];
        pthread_create(&threads[i], NULL, sum_array_chunk, &thread_data[i]);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    
    for (int i = 0; i < 5; ++i) {
        total_sum += partial_sums[i];
    }

    int array_sum = 0;
    for (int i = 0; i < 1000; i++) {
        array_sum += array[i];
    }

    printf("Total sum of the array is %d\n", total_sum);
    printf("Total without threads %d\n", array_sum);

    if (total_sum == array_sum) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
