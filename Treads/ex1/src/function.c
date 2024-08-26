#include "main.h"

void* printIndex(void* index){
    int* indexTread = (int*) index;
    printf("Индекс потока: %d\n", *indexTread);
    pthread_exit(0);
}