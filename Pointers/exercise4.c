#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  char substring[50];
  char *ptr = NULL;
  int i, j, k;

  printf("Введите строку: ");
  fgets(string, sizeof(string), stdin);

  printf("Введите подстроку: ");
  fgets(substring, sizeof(substring), stdin);

  substring[strcspn(substring, "\n")] = '\0';

  for (i = 0; string[i] != '\0'; i++) {
    if (string[i] == substring[0]) {
      for (j = 1, k = i + 1; substring[j] != '\0'; j++, k++) {
        if (string[k] != substring[j]) {
          break;
        }
      }
      if (substring[j] == '\0') {
        ptr = &string[i];
        break;
      }
    }
  }

  if (ptr != NULL) {
    printf("Подстрока найдена по адресу: %p\n", ptr);
  } else {
    printf("Подстрока не найдена.\n");
  }

  return 0;
}