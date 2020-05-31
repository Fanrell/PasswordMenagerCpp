#include <iostream>
#include <ncurses.h>
#include "PassList.h"
#include "FileLister.h"
#include "keys.h"
using namespace std;

class Menu
{
    int menu_pos = 1;
    int members;
    string file_path = ".";
    string decoded = "";
private:
   void DrawCursor(int ypos);
    
public:
    virtual void MenuDraw(int argc, string test[]);
    virtual void EventHandler(bool *exit_flag);
    
};