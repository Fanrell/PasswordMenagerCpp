#include <iostream>
#include "stringer.cc"
#include "Menu.h"
#include "PassList.h"
#include <ncurses.h>

using namespace std;

void PassList::Listing(string data[])
{
    move(2,0);
    clrtobot();
    move(2,0);
    for(int i = start; i<end; i++)
    {
        printw("   %i.",i+1);
        printw(data[i].c_str());
        printw("\n");
    }
    printw("(N)ew, (D)elete, (Q)uit\n");
    move(3,0);
}

void PassList::Events(bool *exit)
{
    switch (getch())
    {
    case KEY_DOWN:
        if(point_pos<end)
            point_pos++;
        else
            point_pos = 1;
        break;
    case KEY_UP:
        if(point_pos>0)
            point_pos--;
        else
            point_pos = end;
        break;
    case KEY_RIGHT:
        if(start+10<all_members)
        {
            start+=10;
            end += 10;
        }
        else
        {
            start = all_members - 10;
            end = all_members;
        }
        break;
    case KEY_LEFT:
        if(start - 10 > 0)
        {
            start -= 10;
            end -= 10;
        }
        else
        {
            start = 0;
            end = 10;
        }
        break;
    case '\n':
        break;
    case 110:
        break;
    case 100:
        break;
    case 113:
        *exit = true;
        move(20,0);
        printw("dasdsa");
        break;
    }


}

void PassList::PointerDraw(int posy)
{
    move(posy+2,0);
    printw(">");
}

void PassList::ShowList(std::string data[])
{
    all_members = 100;
    bool exit = false;
    do
    {
    Listing(data);
    PointerDraw(point_pos);
    Events(&exit);
    }while(!exit);
        move(2,0);
    clrtobot();
}

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
    string testowy[100] = {"a","b","c","e","t","2","5","1","8","h","d","a","d","er","q","t","y","z","q","Y","q","a","o","a","]"};
    PassList pl;
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
            pl.ShowList(testowy);
        if(menu_pos == 4)
            *exit_flag = true;
            
    }
}