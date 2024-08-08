#include "main.h" 

char *right_path, *left_path; // путь к каталогам для правой и левой части менеджера
struct dirent **right_namelist; // список файлов директории для правой части
struct dirent **left_namelist; // список файлов директории для левой части
int right_quantity, left_quantity; //количество записей в текущей директории
int position = 3; // положение курсора на экране чёт - правая, нечёт - левая

int main(){
    int counter;
    get_Path(&right_path);
    get_Path(&left_path);
    right_quantity = scandir(right_path, &right_namelist, 0, alphasort);
    left_quantity = scandir(left_path, &left_namelist, 0, alphasort);
    
    init_Graphic();
    while(counter != 113 && counter != 185){
    counter = getch();
    
    switch (counter){
        case 66:
            if(position % 2 == 1){
                if(position / 2 < (left_quantity -1)){
                    position += 2;
                }
            }
            else
                if(position / 2 < right_quantity - 1){
                    position += 2;
                }
            break;
        case 65:
            if(position > 3)
                position -= 2;
            break;
        case 9:
            if(position % 2 == 1){
                position = 2;
            }
            else
                position = 3;
            break;
        case 10:
            if(position % 2 == 1){
                if(left_namelist[position / 2]->d_type == 4){
                    directory_transition(&left_path, left_namelist[position / 2]->d_name);
                    delete_Directory(left_quantity, left_namelist);
                    left_quantity = scandir(left_path, &left_namelist, 0, alphasort);
                    position = 3;
                }
            }
            else{
                if(right_namelist[position / 2]->d_type == 4){
                    directory_transition(&right_path, right_namelist[position / 2]->d_name);
                    delete_Directory(right_quantity, right_namelist);
                    right_quantity = scandir(right_path, &right_namelist, 0, alphasort);
                    position = 2;
                }
            }  
            break;
    }
    resizeWindow();  
    }
    delete_Directory(right_quantity, right_namelist);
    delete_Directory(left_quantity, left_namelist);
    free(right_path);
    free(left_path); 
    delete_Graphic();
    return 0;
}