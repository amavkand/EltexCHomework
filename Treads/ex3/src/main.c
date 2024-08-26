#include "main.h"
    int shops[NUM_SHOP]; // магазины
    pthread_mutex_t shop_mutexs[NUM_SHOP]; // мьютексы для магазинов


int main(){
   // int shoper_needs[MAX_NEED_SHOPER]; // потребность покупателей
    pthread_t shopers[NUM_SHOPER]; // покупатели
    pthread_t loader_thread; // погрузчик

    srand(time(NULL));
    //инициализация магазиновcle
    for(int i = 0; i < NUM_SHOP; i++){
        shops[i] = rand() % (RANDOM_VAL +1);
        printf("Магазин %d мой баланс %d\n",i,shops[i]);
        pthread_mutex_init(&shop_mutexs[i],NULL); 
    }
    //инициализация потоков покупателей и их id
    int shopers_ids[NUM_SHOPER];
    for(int i = 0; i < NUM_SHOPER; i++){
        shopers_ids[i] = i;
        if(pthread_create(&shopers[i],NULL,shoper,&shopers_ids[i]) != 0){
            perror("Ошибка создания потока покупателя");
            exit(EXIT_FAILURE);
        }
    }
    //инициализация погрузчика
    if (pthread_create(&loader_thread,NULL,loader,NULL) != 0){
        perror("Ошибка создания потока погрузчика");
        exit(EXIT_FAILURE);
    } 
    //ожидания завершения потоков покупателей
    for(int i = 0; i < NUM_SHOPER; i++){
        pthread_join(shopers[i],NULL);
    }
    //завершения работы погрузчика
    pthread_cancel(loader_thread);
    //освобождение памяти
    for(int i = 0; i < NUM_SHOP; i++){
        pthread_mutex_destroy(&shop_mutexs[i]);
    }
    exit(EXIT_SUCCESS);
}