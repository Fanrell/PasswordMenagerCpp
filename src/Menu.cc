#include "Menu.h"


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
            decoded = fl.ShowDirList(&file_path,decoded);
        if(menu_pos == 2)
            decoded = pl.ShowList(decoded);
        if(menu_pos == 3)
        {
            *exit_flag = true;
        }
            
    }
}