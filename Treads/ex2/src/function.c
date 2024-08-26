#include "main.h"

extern int sum;
extern pthread_mutex_t mutex;

void* incrementSum(void*){
    for (int i = 0; i < (TOTAL/TREADS_SIZE); i++){
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}