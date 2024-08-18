#include "main.h"

int main() {
  char command[1024];

  while (1) {
    printf("$ ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;

    if (strcmp(command, "exit") == 0) {
      break;
    }

    run_command(command);
  }

  return 0;
}