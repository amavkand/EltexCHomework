#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  char substring[50];
  char *ptr = NULL; 

  printf("Введите строку: ");
  fgets(string, sizeof(string), stdin);

  printf("Введите подстроку: ");
  fgets(substring, sizeof(substring), stdin);

  substring[strcspn(substring, "\n")] = '\0';

  ptr = strstr(string, substring);

  if (ptr != NULL) {
    printf("Подстрока найдена по адресу: %p\n", ptr);
  } else {
    printf("Подстрока не найдена.\n");
  }
}