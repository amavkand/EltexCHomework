#include "main.h"

void run_command(char* command) {
  char *args[1024];
  parse_command(command, args);

  // Создание дочернего процесса
  pid_t pid = fork();

  if (pid == 0) {
    // Дочерний процесс: выполнение команды
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else if (pid > 0) {
    // Родительский процесс: ожидание завершения дочернего процесса
    wait(NULL);
  } else {
    perror("fork");
    exit(1);
  }
}

void parse_command(char *command, char *args[]) {
  int arg_count = 0;
  char *token = strtok(command, " ");

  // Разделение команды на аргументы
  while (token != NULL) {
    args[arg_count++] = token;
    token = strtok(NULL, " ");
  }
  args[arg_count] = NULL; // Завершение списка аргументов
}