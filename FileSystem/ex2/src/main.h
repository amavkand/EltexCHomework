#ifndef __MAIN_H__
#define __MAIN_H__

 
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>  
#include <string.h> 
#include <time.h>

extern char *right_path, *left_path;
extern struct dirent **right_namelist;
extern struct dirent **left_namelist;
extern int right_quantity, left_quantity, position; 

void showWindow();
void resizeWindow();
void signal_Winch(int signo);
void init_Graphic();
int delete_Window();
int delete_Graphic();
int get_Path(char** path);
int delete_Directory(int n, struct dirent **namelist);
int directory_transition(char** path, char *name);
#endif 