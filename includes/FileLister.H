#include <iostream>
#include <vector>
using namespace std;

class FileLister
{
    typedef std::vector<std::string> stringvec;
    int start = 0;
    int end = 10;
    int all_members;
    int point_pos;
    private:
        void read_dir(string path, stringvec& v);
        void Events(bool *exit,string *path,ofstream *pass_file, stringvec v);
        void PointerDraw(int posy);
        void Listing(stringvec v);
    public:
        void ShowDirList(string *path,ofstream *pass_file);
};