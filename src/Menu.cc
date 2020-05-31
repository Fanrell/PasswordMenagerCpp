#include <iostream>
#include <ncurses.h>
#include <vector> // obsługa wektorów
#include "Menu.h"
#include "PassList.h"
#include "FileLister.h"
#include "keys.h"

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
    printw("Confirm: Enter, Move: Arrows");
    DrawCursor(menu_pos);
}

void Menu::DrawCursor(int ypos)
{
    move(ypos+1,0);
    printw(">");
   
}

void Menu::EventHandler(bool *exit_flag)
{
    // pass_vect.push_back(Account("test","test1"));
    PassList pl;
    FileLister fl;
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
            fl.ShowDirList(&file_path,&file_name ,&decoded);
            move(0,0);
            printw(decoded.c_str());
        if(menu_pos == 2)
            pl.ShowList(decoded);
        if(menu_pos == 3)
        {
            *exit_flag = true;
        }
            
    }
}