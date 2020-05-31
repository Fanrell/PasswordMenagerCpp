#include <iostream>
#include <ncurses.h>
#include "Account.h"
#include "keys.h"

using namespace std;

class PassList
{
    Account acclist[100];
    string d;
    int start = 0;
    int end = 10;
    int all_members = 100;
    int point_pos = 0;
    int mod = 0;
    private:
        void Listing();
        void Events(bool *exit);
        void PointerDraw(int posy);
        string Inputer(string prompt);
    public:
        string ShowList(string decoded);
};