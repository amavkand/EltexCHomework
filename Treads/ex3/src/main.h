#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define RANDOM_VAL 10000 // максимальное количество товаров в магазине
#define NUM_SHOP 5 // количество магазинов
#define NUM_SHOPER 3 // количество покупателей
#define NUM_LOADER 1 // количество погрузчиков
#define MAX_NEED_SHOPER 100000 // максимальная потребность покупателя
#define TIME_SLEEP_SHOPER 2 // время засыпания покупателя
#define TIME_SLEEP_LOADER 1 // время засыпания погрузчика
#define VAL_LOADER 5000 // количество товаров завозимое погрузчиком

void* loader(void* arg);
void* shoper(void* shopers_ids);

#endif