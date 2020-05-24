#include <iostream>
#include <ncurses.h>
#include "stringer.cc"

using namespace std;

class Menu
{
    int menu_pos = 1;
    int members;
    string flierPath = "1";
private:
   void FileList();
    
public:
    void MenuDraw(int argc, string test[]);
    void PointerDraw(int c, bool enter);
    virtual void EventHandler(int c, bool *exit_flag);
    //void FileList();
    
};


void Menu::MenuDraw(int argc, string test[])
{
    members = argc;
    for(int i = 0; i < argc; i++)
    {
        const char *t = test[i].c_str();
        printw("%i.   ",i+1);
        printw(t);
        printw("\n");
    }
    printw("Option: ");
}
void Menu::FileList()
{
        move(members+5,0);
        stringer();

}

void Menu::EventHandler(int c, bool *exit_flag)
{
    switch (c)
    {
    case '3':
        FileList();
        break;
    case '4':
        *exit_flag = true;
        break;
    }
}