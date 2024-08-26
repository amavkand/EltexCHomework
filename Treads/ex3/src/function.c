#include "main.h"

extern int shops[NUM_SHOP];
extern pthread_mutex_t shop_mutexs[NUM_SHOP];
bool shops_lock[NUM_SHOP] = {false, false, false, false, false}; // массив для проверки занятости магазинов

void* loader(void* arg){
        while (1) {
        for (int i = 0; i < NUM_SHOP; i++) {
            // Пытаемся зайти в магазин
            if (shops_lock[i] == false) {
                pthread_mutex_lock(&shop_mutexs[i]);
                shops_lock[i] = true;
                printf("Грузчик: вошел в магазин %d, там было %d\n", i, shops[i]);
                shops[i] += VAL_LOADER;
                if (shops[i] > RANDOM_VAL) {
                    shops[i] = RANDOM_VAL; // Ограничиваем максимальную вместимость магазина
                }
                printf("Грузчик: положил %d, теперь в магазине %d\n", VAL_LOADER, shops[i]);
                shops_lock[i] = false;
                pthread_mutex_unlock(&shop_mutexs[i]);
                printf("Грузчик: заснул\n");
                sleep(TIME_SLEEP_LOADER);  // Засыпает
                break; // Выход если зашел в магазин
            }
        }
    }
    return 0;
}

void* shoper(void* shopers_ids){
    int id = *(int*)shopers_ids;
    int need = rand() % (MAX_NEED_SHOPER +1);
    printf("Я покупатель %d, моя потребность %d\n", id, need);
    while (need > 0) {
        for (int i = 0; i < NUM_SHOP; i++) {
            // Пытаемся зайти в магазин
            if ((shops_lock[i] == false) && (shops[i] != 0)) {
                pthread_mutex_lock(&shop_mutexs[i]);
                shops_lock[i] = true;
                printf("Покупатель %d: вошел в магазин %d, там было %d\n", id, i, shops[i]);

                int purchase = (shops[i] < need) ? shops[i] : need;
                need -= purchase;
                shops[i] -= purchase;
                printf("Покупатель %d: купил %d, потребность теперь %d\n", id, purchase, need);

                shops_lock[i] = false;
                pthread_mutex_unlock(&shop_mutexs[i]);
                printf("Покупатель %d: заснул\n", id);
                sleep(TIME_SLEEP_SHOPER);  // Засыпает
                break;
            }
        }
    }
    printf("Покупатель %d: завершил покупки\n", id);
    return 0;
}