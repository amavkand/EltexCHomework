#include "calc.h"

long long int sub(){
    long long int one = 0, two = 0;
    printf("Введите первое число:\n");
    scanf("%lld",&one);

    printf("Введите второе число:\n");
    scanf("%lld",&two);

    return one - two;
}