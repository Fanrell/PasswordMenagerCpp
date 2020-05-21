#include <ncurses.h>
#include "mainWindow.cc"
#include <iostream>
using namespace std;
bool t = true;
int main()
{
    while (t)
    {
        t = !window();
    }
    refresh();
    endwin();
    return 0;
}