#include "main.h"

int sum = 0;
pthread_mutex_t mutex;
int main(){
    pthread_t threads[TREADS_SIZE];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < TREADS_SIZE; i++){
        pthread_create(&threads[i],NULL,&incrementSum,NULL);
    }

    for(int i = 0; i < TREADS_SIZE; i++){
        pthread_join(threads[i],NULL);
    }

    printf("Сумма = %d\n", sum);  
    exit(EXIT_SUCCESS);
}