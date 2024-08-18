#include "main.h"

int main(){
    pid_t process;
    int status;

    process = fork();

    if (process == 0 ){
        printf("Child PID: %d,Child PPID: %d \n", getpid(), getppid());
        exit(3);
    }
    else{
        printf("PARENT PID: %d, PARENT PPID: %d\n", getpid(), getppid());
        wait(&status);
        printf("Status child: %d\n", WEXITSTATUS(status));
    }
    exit(EXIT_SUCCESS);
}