#include <iostream>

using namespace std;

class PassList
{
    int start = 0;
    int end = 10;
    int all_members;
    int point_pos;
    private:
        void Listing(string data[]);
        void Events(bool *exit);
        void PointerDraw(int posy);
    public:
        void ShowList(string data[]);
};