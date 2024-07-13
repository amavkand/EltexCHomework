#include <stdio.h>

void toBinary(int number) { 
  for (int i = sizeof(number)*8-1; i >= 0; i--) {
    if (number & (1 << i)) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
}

int main() {
    int number1, number2;

    printf("Введите первое число: ");
    scanf("%d", &number1);

    printf("Введите второе число: ");
    scanf("%d", &number2);

    printf("Двоичное представление первого числа до изменения: \n");
    toBinary(number1);
    
    printf("Двоичное представление второго числа:\n");
    toBinary(number2);

    char* ptr1 = (char*)&number1 + 2;
    char* ptr2 = (char*)&number2 + 2;

    *ptr1 = *ptr2; 

    printf("Двоичное представление первого числа после изменения: \n");
    toBinary(number1);

    return 0;
}
