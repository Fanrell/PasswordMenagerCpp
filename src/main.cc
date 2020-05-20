#include <ncurses.h>
#include "menu.cc"
int menu_pos = 1;
int c;
bool exit_flag = FALSE;
int main() {
  initscr();
  keypad(stdscr,TRUE);
  do
  {
  move(0, 0);
  printw("Password Menager \n");
  printw("============================= \n");
  drawMenu();
  drawCursor(menu_pos);
  c = getch();
  switch (c)
  {
  case KEY_UP:
        menu_pos--;
        if(menu_pos<1)
          menu_pos = 4;
        break;
  case KEY_DOWN:
        menu_pos++;
        if(menu_pos > 4)
          menu_pos = 1;
        break;
  case KEY_RIGHT:
        move(10,10);
        if(menu_pos == 1)
        {
          NULL;
        }
        else if (menu_pos == 2)
        {
           NULL;
        }

        else if (menu_pos == 3)
        {
          NULL;
        }

        else if (menu_pos == 4)
        {
          exit_flag = TRUE;
        }
        
        
  }
  refresh();
  }while(!exit_flag);
  endwin();
  return(0);
}