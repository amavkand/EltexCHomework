#include "main.h"
#define BOTTOM_SIZE 3
#define AT_MOD A_BLINK | A_REVERSE

WINDOW *main_Window; 
 
WINDOW *name_RightWindow; // окно с именами правой панели
WINDOW *size_RigthWindow; // окно с размерами правой панели
WINDOW *data_RightWindow; // окно с дату изменений правой панели
 
WINDOW *name_LeftWindow; // окно с именами левой панели
WINDOW *size_LeftWindow; // окно с размерами левой панели
WINDOW *data_LeftWindow; // окно с дату изменений левой панели

WINDOW *bottom_Window; //окно с текущими путями для каждой панели

struct winsize ws; // структура для получения размера терминального окна

// Отрисовка окон
void showWindow(){
    int len_tmp;
    struct stat *bufferFile;
    char *tmp_path;

    len_tmp = strlen(left_path);
    wmove(bottom_Window, 1, 1); 
    if((ws.ws_col/2) < len_tmp){
        wprintw(bottom_Window, "/...%s         ", &(left_path[len_tmp - ((ws.ws_col/3)-5)]));
    }
    else    
        wprintw(bottom_Window, "%s  ", left_path);
    wmove(bottom_Window, 1, (ws.ws_col/2)+1);
    len_tmp = strlen(right_path);
    if((ws.ws_col/2) < len_tmp){
        wprintw(bottom_Window, "/...%s         ", &(right_path[len_tmp - ((ws.ws_col/3)-5)]));
    }
    else    
        wprintw(bottom_Window, " %s ", right_path); 
    wmove(bottom_Window, 2, 1);
    tmp_path = malloc(PATH_MAX);
    strcat(tmp_path, right_path);
    strcat(tmp_path, "/"); 
    for(int i = 1; i < right_quantity; i++){ 
        if((position % 2 == 0) && (position / 2 == i)){
            wattron(name_RightWindow, AT_MOD);
        }
        wmove(name_RightWindow, i, 1);
        wmove(data_RightWindow, i, 1); 
        wmove(size_RigthWindow, i, 1); 
        if(right_namelist[i]->d_type == 4)
            wprintw(name_RightWindow, "/");
        wprintw(name_RightWindow, "%s", right_namelist[i]->d_name);

        if(i > 1){    
            bufferFile = malloc(sizeof(struct stat));
            tmp_path[strlen(right_path)+1] = '\000';
            strcat(tmp_path, right_namelist[i]->d_name); 
            stat(tmp_path, bufferFile);
            wprintw(size_RigthWindow, "%ld", bufferFile->st_size); 
            wprintw(data_RightWindow, "%s", &(ctime(&(bufferFile->st_mtime)))[4]);
            free(bufferFile); 
        }
        if(position % 2 == 0 && (position / 2 == i)){
            wattroff(name_RightWindow, AT_MOD);
        }
    }
    free(tmp_path);
    tmp_path = malloc(PATH_MAX);
    tmp_path[0] = '\000';
    strcat(tmp_path, left_path);
    strcat(tmp_path, "/");

    for(int i = 1; i < left_quantity; i++){
        if((position % 2 == 1) && (position / 2 == i)){
            wattron(name_LeftWindow, AT_MOD);
        } 
        wmove(data_LeftWindow, i, 1);
        wmove(name_LeftWindow, i, 1);
        wmove(size_LeftWindow, i, 1);
        if(left_namelist[i]->d_type == 4)
            wprintw(name_LeftWindow, "/");
        wprintw(name_LeftWindow, "%s", left_namelist[i]->d_name);
        if(i > 1){
            bufferFile = malloc(sizeof(struct stat));
            tmp_path[strlen(left_path)+1] = '\000';
            strcat(tmp_path, left_namelist[i]->d_name); 
            stat(tmp_path, bufferFile);
            wprintw(size_LeftWindow, "%ld", bufferFile->st_size); 
            wprintw(data_LeftWindow, "%s", &(ctime(&(bufferFile->st_mtime)))[4]);
            free(bufferFile); 
        } 
        if((position % 2 == 1) && (position / 2 == i)){
            wattroff(name_LeftWindow, AT_MOD);
        }
    }
    free(tmp_path);
    
}

void resizeWindow(){
    delete_Window();

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 
    main_Window = newwin(ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col, 0, 0); 
    wbkgd(main_Window, COLOR_PAIR(1));

    name_RightWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col / 4, 0, (ws.ws_col / 2) + 1);
    size_RigthWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col / 8, 0, (ws.ws_col / 2) + 1 + ws.ws_col / 4);
    data_RightWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, (ws.ws_col / 8) - 1, 0, (ws.ws_col / 2) + 1 + ws.ws_col / 4 + ws.ws_col / 8);
     
    name_LeftWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col / 4, 0, 0);
    size_LeftWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col / 8, 0, ws.ws_col / 4);
    data_LeftWindow = derwin(main_Window, ws.ws_row - BOTTOM_SIZE - 1, ws.ws_col / 8, 0, ws.ws_col / 4 + ws.ws_col / 8);

    bottom_Window = newwin(BOTTOM_SIZE, ws.ws_col - 1, ws.ws_row - BOTTOM_SIZE, 0);
    wbkgd(bottom_Window, COLOR_PAIR(2));

    showWindow();

    move(ws.ws_row - 1 - BOTTOM_SIZE, 1);
    printw("q - quit    TAB - right/left win    input : ");
 
    box(size_RigthWindow, 0, 0);
    box(name_RightWindow, 0, 0);
    box(data_RightWindow, 0, 0); 

    box(size_LeftWindow, 0, 0);
    box(name_LeftWindow, 0, 0);
    box(data_LeftWindow, 0, 0);

    box(bottom_Window, 0, 0);

    wrefresh(main_Window); 
    wrefresh(bottom_Window); 
    refresh();   
}
//переход между каталогами
int directory_transition(char** path, char *name){
    if(position / 2 == 1){
        for(int i = strlen(*path); i != 0; i--){
            if((*path)[i] == '/'){
                (*path)[i] = '\000';
                break;
            }
        } 
        *path = realloc(*path, strlen(*path)); 
    }
    else{
        *path = realloc(*path, strlen(*path) + strlen(name)); 
        strcat(*path, "/");
        strcat(*path, name); 
    } 
    return 0;
}
//обработка изменения размера терминального окна
void signal_Winch(int signo){ 
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);  
    resizeWindow(); 
}
//инициализация графики
void init_Graphic(){
    initscr();
    signal(SIGWINCH, signal_Winch);
    cbreak();
    curs_set(0); 
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_GREEN); 
    refresh();

    resizeWindow();  
}
//удаление окон
int delete_Window(){
    delwin(main_Window);
    delwin(bottom_Window); 
    delwin(name_RightWindow);
    delwin(data_RightWindow);
    delwin(size_RigthWindow);
    delwin(name_LeftWindow);
    delwin(data_LeftWindow);
    delwin(size_LeftWindow);

    return 0;
}
//удаление графики
int delete_Graphic(){ 
    delete_Window();
    return endwin();
}