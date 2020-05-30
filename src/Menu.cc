#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <fstream>
#include "Menu.h"
#include "PassList.h"
#include "FileLister.H"
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
void Menu::FileList()
{
        move(9,0);
        clrtobot();
        move(members+5,0);
        if(file_path.empty())
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
    string testowy[100] = {"a","b","c","e","t","2","5","1","8","h","d","a","d","er","q","t","y","z","q","Y","q","a","o","a","]"};
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
            fl.ShowDirList(&file_path,&pass_file);
        if(menu_pos == 2)
            pl.ShowList(testowy);
        if(menu_pos == 3)
            *exit_flag = true;
            
    }
}