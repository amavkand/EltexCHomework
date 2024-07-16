#include <stdio.h>
#include<string.h>
#include<termio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE_ABONENTS 100

struct abonent
{
    char name[10];
    char second_name[10];
    char tel[10];
};

void addAbonent(struct abonent *abonent[], int* count){
        char name[10] = {0}, secondName[10] = {0}, tel[10] = {0};

        printf("\nВведите имя:\n");
        scanf("%s", &name);

        name[strcspn(name, "\n")] = '\0';
        if(strlen(name) > 10){
            printf("Ошибка имени пользователя");
            return 1;
        }

        printf("\nВведите фамилию:\n");
        scanf("%s", &secondName);

        secondName[strcspn(secondName, "\n")] = '\0';
        if(strlen(secondName) > 10){
            printf("Ошибка фамилии пользователя");
            return 1;
        }

        printf("\nВведите телефон:\n");
        scanf("%s", &tel);

        tel[strcspn(tel, "\n")] = '\0';
        if(strlen(tel) > 10){
            printf("Ошибка ввода телефона пользователя");
            return 1;
        }

        if (*count < SIZE_ABONENTS){
            if (*count == 0) *abonent = malloc((*count + 1) * sizeof(struct abonent));
            else *abonent = realloc(*abonent, (*count + 1) * sizeof(struct abonent));
            strcpy((*abonent)[*count].name, name);
            strcpy((*abonent)[*count].second_name, secondName);
            strcpy((*abonent)[*count].tel, tel);
            *count +=1;
            printf("\nАбонент %s %s добавлен!", name,secondName);
        }
        else printf("\nБаза данных переполнена");

}

void printBase(struct abonent abonent[], int count){
    if(count == 0) printf("Список абонентов пуст!");
    if (count > 0) {
        printf("Список абонентов:\n");
        for (int i = 0; i < count; i++) {
            printf("%d) ",i + 1);
            printf("Имя: %s ", abonent[i].name);
            printf("Фамилия: %s ", abonent[i].second_name);
            printf("Телефон: %s\n", abonent[i].tel);
            }
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {}
    printf("\nДля продолжения нажмите любую клавишу...");
    getchar();

}

void rebuildBase(struct abonent *abonent[], int count, int delIndex){
    for (int i = delIndex -1; i < count; i++){
            strcpy((*abonent)[i].name, (*abonent)[i+1].name);
            strcpy((*abonent)[i].second_name, (*abonent)[i+1].second_name);
            strcpy((*abonent)[i].tel, (*abonent)[i+1].tel);
    }
}

void delAbonent(struct abonent *abonent[], int *count){
    int indexDel = 0;
    printBase(*abonent, *count);
    if (*count != 0) 
    {
        printf("\nВведите номер абонента, которого вы хотите удалить: ");
        scanf("%d", &indexDel);

        if((indexDel <= *count) ){
            memset((*abonent)[indexDel - 1].name, 0, sizeof((*abonent)[indexDel - 1].name));
            memset((*abonent)[indexDel - 1].second_name, 0, sizeof((*abonent)[indexDel - 1].second_name));
            memset((*abonent)[indexDel - 1].tel, 0, sizeof((*abonent)[indexDel - 1].tel));

            rebuildBase(abonent, *count, indexDel);
            *count -= 1;

        printf("\nАбонент был успешно удален!");
        }
        else printf("Некорректный номер");
        int ch;
        while ((ch = getchar()) != EOF && ch != '\n') {}
        printf("\nДля продолжения нажмите любую клавишу...");
        getchar();
    }
}

int searchAbonent(struct abonent abonent[], int count)
{
    char searchName[10];

    printf("Введите имя абонента: ");
    scanf("%s", &searchName);
    if (strlen(searchName) > 10)
    {
        printf("При попытке ввода имени произошла ошибка!");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(searchName, abonent[i].name))
        {
            printf("%d) ", i + 1);
            printf("%s, ", abonent[i].name);
            printf("%s, ", abonent[i].second_name);
            printf("%s\n", abonent[i].tel);
        }
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {}
    printf("\nДля продолжения нажмите любую клавишу...");
    getchar();
    return 0;
}

int main(){

    struct abonent *dataBase;
    int abonent_count = 0;

    while(1){

        system("clear");
        printf("\nАбонентский справочник:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Введите пункт меню: ");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear");
            addAbonent(&dataBase,&abonent_count);           
            break;
        case 2:
            system("clear");
            delAbonent(&dataBase, &abonent_count);           
            break;
        case 3:
            system("clear");
            searchAbonent(dataBase, abonent_count);
            break;
        case 4:
            system("clear");
            printBase(dataBase, abonent_count);
            break;
        case 5:
            system("clear");
            if(abonent_count != 0){
                free(dataBase);
            }
            printf("\nДо свидания!\n");
            exit(EXIT_SUCCESS);   
        default:
            printf("Данная опция не существует");
            break;
        }   
    }
}