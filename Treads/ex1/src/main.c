#include "main.h"

int main(){
    pthread_t threads[TREADS_SIZE];
    int indexs[TREADS_SIZE];

    for(int i = 0; i < TREADS_SIZE; i++){
        indexs[i] = i;
        if (pthread_create(&threads[i],NULL,&printIndex,&indexs[i]) !=0 ){
            perror("Ошибка при создании потока");
            exit(EXIT_SUCCESS);
        }
    }

    for(int i = 0; i < TREADS_SIZE; i++){
        pthread_join(threads[i],NULL);
    }  
    exit(EXIT_SUCCESS);
}