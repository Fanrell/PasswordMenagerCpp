#include <iostream>
#include <ncurses.h>
using namespace std;

string stringer(int posx, int posy)
{
    keypad(stdscr,TRUE);
    int c;
    string path;
    int pos = 0;
    bool in_loop = true;
    const char * ret_path;
    move(posy-2,0);
    clrtobot();
    move(posy,posx);
    do
    {
        c = getch();
        switch (c)
        {
        case('/'):
            path += '/';
            path += '/';
            break;
        case('\n'):
            in_loop = false;
            break;
        
        default:
            path += c;        
            break;
        }
    } while (in_loop);
    return path;
    
}