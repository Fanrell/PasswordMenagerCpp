#include <iostream>
#include <ncurses.h>
using namespace std;

string stringer()
{
    keypad(stdscr,TRUE);
    int c;
    string path;
    int pos = 0;
    bool in_loop = true;
    const char * ret_path;
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
            move(10,10);
            printw("1");
            break;
        
        default:
            path += c;        
            break;
        }
    } while (in_loop);
    return path;
    
}