#include <ncurses.h>
#include "Menu.h"
#include <iostream>
using namespace std;

int c;
bool exit_flag = FALSE;
bool enter = false;
string test[] = {"New File","Open File","Passwords List","Exit"};

Menu mainMenu;
bool window() {
  initscr();
  keypad(stdscr,TRUE);
  
  move(0, 0);
  printw("Password Menager \n");
  printw("============================= \n");
  
  mainMenu.MenuDraw(4,test);
  c = getch();
  move(20,20);
  mainMenu.EventHandler(c,&exit_flag);
  refresh();

    return(exit_flag);

}