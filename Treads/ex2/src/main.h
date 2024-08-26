#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TREADS_SIZE 5
#define TOTAL 10000

void* incrementSum(void*);

#endif