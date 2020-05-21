#include <iostream>
#include <ncurses.h>

using namespace std;

class Menu
{
    int menu_pos = 1;
    int members;
private:
   
    
public:

    void MenuDraw(int argc, string test[]);
    void PointerDraw(int c);
};


void Menu::MenuDraw(int argc, string test[])
{
    members = argc;
    for(int i = 0; i < argc; i++)
    {
        const char *t = test[i].c_str();
        printw("   ");
        printw(t);
        printw("\n");
    }
}

void Menu::PointerDraw(int c)
{
    move(1+menu_pos,0);
    printw(">");

switch (c)
   {
   case KEY_UP:
         menu_pos--;
         if(menu_pos<1)
           menu_pos = 1;
         break;
   case KEY_DOWN:
         menu_pos++;
        if(menu_pos > members)
           menu_pos = members;

         break;
    }
}