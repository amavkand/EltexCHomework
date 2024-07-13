#include <stdio.h>

#define N 10

int main(){
    int array[N];
    int *ptr = array;

    for(int i = 0; i < N; i++){
        *ptr = i+1;
        ptr++;
    }

    ptr = array;

    for(int i = 0; i<N; i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}