#include <iostream>

using namespace std;

class PassList
{
    int start = 0;
    int end;
    int all_members;
    int point_pos;
    private:
        void Listing(int s, int k, string data[]);
        void Events(bool *exit);
        void PointerDraw(int posy);
    public:
        void Draw(string data[]);
};