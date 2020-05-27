#include <iostream>
#include <ncurses.h>
#include "PassList.h"

using namespace std;

void PassList::Listing(int s, int k, string data[])
{
    move(2,3);
    for(int i = s; s<k; i++)
    {
        printw(data[i].c_str());
    }
}

void PassList::Events(bool *exit)
{
    switch (getch())
    {
    case KEY_UP:
        if(point_pos<end)
            point_pos++;
        else
            point_pos = 1;
        break;
    case KEY_DOWN:
        if(point_pos>1)
            point_pos--;
        else
            point_pos = end;
        break;
    case KEY_RIGHT:
        if(start+20<all_members)
            start+=20;
        else
            start = all_members - 20;
        break;
    case KEY_LEFT:
        if(start - 20 > 0)
            start -= 20;
        else
            start = 0;
        break;
    case '\n':
        break;
    case 'n':
        break;
    case 'd':
        break;
    case 'e':
        break;
    case 'q':
        *exit = true;
        break;
    }
}

void PointerDraw(int posy)
{
    move(posy,0);
    printw(">");
}

void PassList::Draw(string data[])
{
    bool exit = true;
    do
    {
    Listing(start,end,data);
    PointerDraw(point_pos);
    Events(&exit);
    }while(exit);
}