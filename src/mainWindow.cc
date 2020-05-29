#include <ncurses.h>
#include "Menu.h"
#include <iostream>
using namespace std;

int c;
bool exit_flag = FALSE;
bool enter = false;
string menuList[] = {"File List","Passwords List","Exit"};
Menu mainMenu;
bool window() {
  cbreak();
  initscr();
  keypad(stdscr,TRUE);
  
  move(0, 0);
  printw("Password Menager \n");
  printw("============================= \n");
  
  mainMenu.MenuDraw(3,menuList);
  move(20,20);
  mainMenu.EventHandler(&exit_flag);
  refresh();

    return(exit_flag);

}