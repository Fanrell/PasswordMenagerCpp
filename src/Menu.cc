#include <iostream>
#include "stringer.cc"
#include "Menu.h"
#include <ncurses.h>

using namespace std;




void Menu::MenuDraw(int argc, string test[])
{
    members = argc;
    for(int i = 0; i < argc; i++)
    {
        const char *t = test[i].c_str();
        printw("%i.   ",i+1);
        printw(t);
        printw("\n");
    }
    printw("Option: ");
}
void Menu::FileList()
{
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

void Menu::EventHandler(int c, bool *exit_flag)
{
    move(9,0);
    clrtobot();
    move(2,0);
    switch (c)
    {
    case '1':
        stringer(0,9);
        break;
    case '2':
        break;
    case '3':
        FileList();
        break;
    case '4':
        *exit_flag = true;
        break;
    }
}