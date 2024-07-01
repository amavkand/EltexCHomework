#include <stdio.h>

void toBinary(int number) { 
  printf("Двоичное представление: \n");
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

  int number,temp=0;
  
  printf("1.Введите положительное число:\n");
  scanf("%d", &number);
  toBinary(number);

  printf("2.Введите отрицательное число:\n");
  scanf("%d", &number);
  toBinary(number);
  
  printf("3.Введите положительное число:\n");
  scanf("%d", &number);
  for (int i = sizeof(number)*8-1; i >= 0; i--) {
    if (number & (1 << i)) {
    	temp+=1;
    }
  }
  printf("Количество единиц в двоичном представлении: %d\n",temp);
  
  printf("4.Введите два положительное число:\n");
  scanf("%d", &number);
  scanf("%d", &temp);
  toBinary(number);
  toBinary(temp);

  temp = (temp >> 8) & 0xFF;

  number = (number & ~(0xFF << 8)) | (temp << 8);

  toBinary(number);

  return 0;
}
