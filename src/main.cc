#include <ncurses.h>
#include "Menu.cc"
#include <iostream>
using namespace std;

int c;
bool exit_flag = FALSE;
string test[] = {"test\0","test2\0","1","t"};

Menu mainMenu;
int main() {
  initscr();
  keypad(stdscr,TRUE);
  do
  {
  move(0, 0);
  printw("Password Menager \n");
  printw("============================= \n");
  mainMenu.MenuDraw(4,test);
  mainMenu.PointerDraw(c);
  c = getch();
  }while(!exit_flag);
  getch();
  refresh();
  endwin();
  return(0);
}