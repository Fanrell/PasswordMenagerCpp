#include <iostream>
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
    
};