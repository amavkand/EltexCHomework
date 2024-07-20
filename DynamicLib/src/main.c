#include "calc.h"

int main(){

    long long int result;
    int choice = 0;
    int ch;

    while(1){
        system("clear");
        printf("\nКалькулятор:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");
        printf("Введите пункт меню: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear");
            result = 0;
            result = add();
            printf("Результат сложения = %lld", result);

            while ((ch = getchar()) != EOF && ch != '\n') {}
            printf("\nНажмите любую клавишу...");
            getchar();

            break;
        case 2:
            system("clear");
            result = 0;
            result = sub();
            printf("Результат вычитания = %lld", result);

            while ((ch = getchar()) != EOF && ch != '\n') {}
            printf("\nНажмите любую клавишу...");
            getchar(); 

            break;
        case 3:
            system("clear");
            result = 0;
            result = mul();
            printf("Результат умножения = %lld", result);

            while ((ch = getchar()) != EOF && ch != '\n') {}
            printf("\nНажмите любую клавишу...");
            getchar();

            break;
        case 4:
            system("clear");
            result = 0;
            result = divi();
            printf("Результат деления = %lld", result);

            while ((ch = getchar()) != EOF && ch != '\n') {}
            printf("\nНажмите любую клавишу...");
            getchar();

            break;
        case 5:
            system("clear");
            printf("\nДо свидания!\n");
            exit(EXIT_SUCCESS);   
        default:
            printf("Данная опция не существует");
            while ((ch = getchar()) != EOF && ch != '\n')
            break;
        }   
    }
}