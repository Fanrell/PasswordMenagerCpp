#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "PassList.h"
#include "keys.h"

using namespace std;

void PassList::Listing()
{
    move(2,0);
    clrtobot();
    move(2,0);
        for(int i = start; i<end; i++)
        {
            printw("   %i.",i+1);
            if(point_pos + mod == i)
                printw(acclist[i].Stringer().c_str());
            else
                printw(acclist[i].Service().c_str());
            printw("\n");
        }

    printw("Chose filed, (N)ew, (D)elete, (Q)uit\n");
    move(3,0);
}

string PassList::Inputer(string prompt)
{
    keypad(stdscr,TRUE);
    int c;
    string path;
    int pos = 0;
    bool in_loop = true;
    do
    {
        move(end+2,0);
        clrtobot();
        printw(prompt.c_str());
        printw(path.c_str());
        c = getch();
        switch (c)
        {
        case('\n'):
            in_loop = false;
            break;
        case KEY_BACKSPACE:
            path = path.substr(0,path.size()-1);
            break;
        default:
            path += c;        
            break;
        }
    } while (in_loop);
    return path;
}

void PassList::Events(bool *exit)
{
    string tmp[2];
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
        if(all_members > 10)
        {
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
            if(mod < 90)
                mod += 10;
            point_pos = 0;
        }
        break;
    case KEY_LEFT:
     if(all_members > 10)
        {
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
            if(mod > 0)
                mod -= 10;
            point_pos = 0;
        }
        break;
    case KEY_N:
        move(end+3,0);
        tmp[0] = Inputer("Service name: ");
        tmp[1] = Inputer("Login: ");
        acclist[point_pos+mod] = Account(tmp[0],tmp[1]);
        break;
    case KEY_D:
        acclist[point_pos+mod] = Account();
        break;
    case KEY_Q:
        *exit = true;
        break;
    }


}

void PassList::PointerDraw(int posy)
{
    move(posy+2,0);
    printw(">");
    move(posy+2,0);
}

void PassList::ShowList(string decoded)
{
    cbreak();
    bool exit = false;
    if(decoded != "")
    {
        string serv,login,pass;
        int pos = 0;
        int loc = 0;
        for(int i = 0; i<decoded.length();i++)
        {
            if(decoded[i] != '\n' && decoded[i] != ' ')
                switch (pos)
                {
                case 0:
                    serv += decoded[i];
                    break;
                case 1:
                    login += decoded[i];
                    break;
                case 2:
                    pass += decoded[i];
                    break;
                }
            else if(decoded[i] == ' ')
                pos++;
            else if(decoded[i] == '\n')
            {
                pos = 0;
                acclist[loc] = Account(serv,login,pass);
                loc++;
            }
        }
    }
    do
    {
    Listing();
    PointerDraw(point_pos);
    Events(&exit);
    }while(!exit);
    ofstream t ("t.txt");
    for(int i = 0; i < 100; i++)
    {
        t << acclist[i].Saver();
    }
        move(2,0);
    clrtobot();
}