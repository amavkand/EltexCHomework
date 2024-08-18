#include "main.h"

int main(){
    pid_t processParent, processChild;
    int status;

    processParent = fork();

    if (processParent == 0 ){
        printf("Parent 2 PID: %d,Parent PPID: %d \n", getpid(), getppid());
        processChild = fork();
        if (processChild == 0){
            printf("5 Child PID: %d, Child PPID: %d\n", getpid(),getppid());
            exit(5);
        }
        else{
            wait(&status);
            printf("Status 5 Child: %d\n", WEXITSTATUS(status));
        }
        exit(2);
    }
    else{
        processChild = fork();
        if(processChild == 0){
            printf("Parent 1 PID: %d, Parent PPID: %d\n", getpid(), getppid());

            processChild = fork();
            if (processChild == 0){
                printf("3 Child PID: %d, Child PPID: %d\n", getpid(),getppid());
                exit(3);
            }

            wait(&status);
            printf("Status 3 Child: %d\n", WEXITSTATUS(status));

            processChild = fork();
            if (processChild == 0){
                printf("4 Child PID: %d, Child PPID: %d\n", getpid(),getppid());
                exit(4);
            }
            wait(&status);
            printf("Status 4 Child: %d\n", WEXITSTATUS(status));

            exit(1);
        }
        else{
            wait(&status);
            printf("Status 2 Parent: %d\n", WEXITSTATUS(status));
        }
        wait(&status);
        printf("Status 1 Parent: %d\n", WEXITSTATUS(status));
    }
    exit(EXIT_SUCCESS);
}