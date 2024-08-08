#include "main.h"
//получение пути к текущему каталогу
int get_Path(char** path){
    *path = malloc(PATH_MAX); 
    if(getcwd(*path, PATH_MAX)){
        //printf("Текущая директория: %s\n", *path);
        *path = realloc(*path, strlen(*path));  
        return 0;
    }
    else{
        //printf("Ошибка определения директории\n");
        return 1;
    }  
}
//очистка стрктуры
int delete_Directory(int n, struct dirent **namelist){
    while(n--){
        free(namelist[n]);
    }
    free(namelist);
    return 0;
}