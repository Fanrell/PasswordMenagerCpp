#include <iostream>
#include <ncurses.h>
#include "PassList.h"
#include "keys.h"

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
        if(point_pos<end-1)
            point_pos++;
        else
            point_pos = 0;
        break;
    case KEY_UP:
        if(point_pos>0)
            point_pos--;
        else
            point_pos = end-1;
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
        point_pos = 0;
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
        point_pos = 0;
        break;
    case '\n':
        break;
    case KEY_N:
        break;
    case KEY_D:
        break;
    case KEY_Q:
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