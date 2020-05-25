#include <iostream>
#include "stringer.cc"
#include "Menu.h"
#include <ncurses.h>

using namespace std;




void Menu::MenuDraw(int argc, string menuList[])
{
    members = argc;
    for(int i = 0; i < argc; i++)
    {
        const char *t = menuList[i].c_str();
        printw("   %i.   ",i+1);
        printw(t);
        printw("\n");
    }
    printw("Option: ");
    DrawCursor(menu_pos);
}
void Menu::FileList()
{
        move(9,0);
        clrtobot();
        move(members+5,0);
        if(flierPath.empty())
        {
            
            printw("You didn't open file");
        }
        else
        {
            printw("You opened file");
        }

}

void Menu::DrawCursor(int ypos)
{
    move(ypos+1,0);
    printw(">");
}

void Menu::EventHandler(bool *exit_flag)
{


    switch (getch())
    {
    case KEY_DOWN:
        if(menu_pos<members)
            menu_pos++;
        else
            menu_pos = 1;
        
        break;
    case KEY_UP:
        if(menu_pos>1)
            menu_pos--;
        else
            menu_pos = members;
        break;
    case '\n':
        if(menu_pos == 1)
            stringer(0,9);
        if(menu_pos == 2)
            printw("12");
        if(menu_pos == 3)
            FileList();
        if(menu_pos == 4)
            *exit_flag = true;
            
    }
}