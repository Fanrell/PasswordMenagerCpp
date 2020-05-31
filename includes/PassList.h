#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class PassList
{
    // typedef vector<Account> accountvec;
    // accountvec passvec;
    Account acclist[100] = {Account{"t1", "t"}, Account{"t2", "t1"}};
    int start = 0;
    int end = 10;
    int all_members = 100;
    int point_pos = 0;
    int mod = 0;
    int ocupated = 0;
    private:
        void Listing();
        void Events(bool *exit);
        void PointerDraw(int posy);
        string Inputer(string prompt);
    public:
        void ShowList(string decoded);
};