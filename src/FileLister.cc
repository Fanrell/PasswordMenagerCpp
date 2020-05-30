#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include <filesystem>
#include "stringer.cc"
#include "FileLister.H"
#include "keys.h"
using namespace std;

void FileLister::read_dir(string path, stringvec& v)
{
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}
void FileLister::Events(bool *exit, string *path, ofstream *pass_file, stringvec v)
{
    string new_file;
    string new_path;
    switch (getch())
    {
    case KEY_DOWN:
        if(point_pos<end-1)
            point_pos++;
        else
            point_pos = 0;
        break;
    case KEY_UP:
        if(point_pos>0)
            point_pos--;
        else
            point_pos = end-1;
        break;
    case KEY_RIGHT:
        if(all_members > 10)
        {
            if(start+10<all_members)
            {
                start+=10;
                end += 10;
            }
            else
            {
                start = all_members - 10;
                end = all_members;
            }
            point_pos = 0;
        }
        break;
    case KEY_LEFT:
     if(all_members > 10)
        {
            if(start - 10 > 0)
            {
                start -= 10;
                end -= 10;
            }
            else
            {
                start = 0;
                end = 10;
            }
            point_pos = 0;
        }
        break;
    case '\n':
        *path += "/"+v[point_pos];
        break;
    case KEY_N:
        new_file = stringer(0,end+2);
        new_file += EXT;
        pass_file->open(*path+"/"+new_file);
        pass_file->close();
        break;
    case KEY_Q:
        *exit = true;
        move(20,0);
        printw("dasdsa");
        break;
    }
}
void FileLister::PointerDraw(int posy)
{
    move(posy+2,0);
    printw(">");
}
void FileLister::Listing(stringvec v)
{
    move(2,0);
    clrtobot();
    move(2,0);
    for(int i = start; i<all_members; i++)
    {
        printw("   %i. ",i+1);
        printw(v[i].c_str());
        printw("\n");
        if(i==end)
            break;
    }
    printw("Confirm: Enter, Move: Arrows, (N)ew, (Q)uit\n");
    move(3,0);
}

void FileLister::ShowDirList(string *path, ofstream *pass_file)
{
    all_members = 100;
    bool exit = false;
    stringvec dir_list;
    do
    {
    read_dir(*path,dir_list);
    sort(dir_list.begin(),dir_list.end());
    all_members = dir_list.size();
    if(dir_list.size() < 10)
        end = dir_list.size();
    Listing(dir_list);
    PointerDraw(point_pos);
    Events(&exit,path, pass_file, dir_list);
    dir_list.erase(dir_list.begin(),dir_list.end());
    }while(!exit);
        move(2,0);
    clrtobot();
}