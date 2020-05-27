#include <iostream>
using namespace std;

class Menu
{
    int menu_pos = 1;
    int members;
    string flierPath = "1";
private:
   void FileList();
   void DrawCursor(int ypos);
    
public:
    virtual void MenuDraw(int argc, string test[]);
    virtual void EventHandler(bool *exit_flag);
    
};