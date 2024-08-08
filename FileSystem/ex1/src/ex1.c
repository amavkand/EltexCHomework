#include "ex1.h"

int main() {
  FILE *fp;
  char buf[50];
  int i = 0, j = 0;
  fp = fopen("output.txt", "w");

  if (fp == NULL) {
    perror("Ошибка открытия файла для записи");
    exit(EXIT_SUCCESS);
  }

  fprintf(fp, "String from file");

  fclose(fp);

  fp = fopen("output.txt", "r");
  if (fp == NULL) {
    perror("Ошибка открытия файла для чтения");
    exit( EXIT_SUCCESS);
  }

  fseek(fp, 0, SEEK_END);
  int file_size = ftell(fp);
  fseek(fp,0, SEEK_SET);

  for (i = file_size - 1, j = 0; i >=0; i--, j++){
    fseek(fp,i,SEEK_SET);
    fscanf(fp,"%c",&buf[j]);

  }
  buf[file_size] = '\0';

  fclose(fp);

  printf("%s\n", buf);

  exit(EXIT_SUCCESS);
}
