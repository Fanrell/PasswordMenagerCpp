#include <iostream>
#include "menu.h"

void drawMenu()
{
    printw("   1. New File \n");
    printw("   2. Open File \n");
    printw("   3. Password view \n");
    printw("   4. Exit \n");
}
void drawCursor(int pos)
{
    move(1+pos,0);
    printw(">");
}
