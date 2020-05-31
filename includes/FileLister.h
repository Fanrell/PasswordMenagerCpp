#include <iostream>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include "keys.h"
#include "RSA.h"
using namespace std;

class FileLister
{
    typedef vector<string> stringvec;
    int start = 0;
    int end = 10;
    int all_members;
    int point_pos;
    int mod = 0;
    string deco;
    ofstream pass_file;
    ifstream read_pass;
    RSA coder;
    private:
        void read_dir(string path, stringvec& v);
        void Events(bool *exit,string *path, stringvec v);
        void PointerDraw(int posy);
        void Listing(stringvec v);
        string Inputer(string prompt);
    public:
        string ShowDirList(string *path,string decoded);
};