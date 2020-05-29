#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <fstream>
#include "stringer.cc"
#include "Menu.h"
#include "PassList.h"
#include "FileLister.H"

#define KEY_N 110
#define KEY_Q 113
#define KEY_D 100
#define EXT ".Pssmg";

using namespace std;

void PassList::Listing(string data[])
{
    move(2,0);
    clrtobot();
    move(2,0);
    for(int i = start; i<end; i++)
    {
        printw("   %i.",i+1);
        printw(data[i].c_str());
        printw("\n");
    }
    printw("(N)ew, (D)elete, (Q)uit\n");
    move(3,0);
}

void PassList::Events(bool *exit)
{
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
        break;
    case KEY_LEFT:
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
        break;
    case '\n':
        break;
    case KEY_N:
        break;
    case KEY_D:
        break;
    case KEY_Q:
        *exit = true;
        move(20,0);
        printw("dasdsa");
        break;
    }


}

void PassList::PointerDraw(int posy)
{
    move(posy+2,0);
    printw(">");
}

void PassList::ShowList(std::string data[])
{
    all_members = 100;
    bool exit = false;
    do
    {
    Listing(data);
    PointerDraw(point_pos);
    Events(&exit);
    }while(!exit);
        move(2,0);
    clrtobot();
}

void FileLister::read_dir(string path, stringvec& v)
{
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}
void FileLister::Events(bool *exit, string path, ofstream *pass_file)
{
    string new_file;
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
        break;
    case KEY_LEFT:
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
        break;
    case '\n':
        break;
    case KEY_N:
        new_file = stringer(0,end+2);
        new_file += EXT;
        pass_file->open(path+"/"+new_file);
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
    printw("(N)ew, (Q)uit\n");
    move(3,0);
}

void FileLister::ShowDirList(string *path, ofstream *pass_file)
{
    all_members = 100;
    bool exit = false;
    bool changed = true;
    stringvec dir_list;
    do
    {
    read_dir(*path,dir_list);
    sort(dir_list.begin(),dir_list.end());
    all_members = dir_list.size();
    Listing(dir_list);
    PointerDraw(point_pos);
    Events(&exit,*path, pass_file);
    dir_list.erase(dir_list.begin(),dir_list.end());
    }while(!exit);
        move(2,0);
    clrtobot();
}

void Menu::MenuDraw(int argc, string menuList[])
{
    members = argc;
    for(int i = 0; i < argc; i++)
    {
        const char *t = menuList[i].c_str();
        printw("   %i.   ",i+1);
        printw(t);
        printw("\n");
    }
    printw("Option: ");
    DrawCursor(menu_pos);
}
void Menu::FileList()
{
        move(9,0);
        clrtobot();
        move(members+5,0);
        if(file_path.empty())
        {
            
            printw("You didn't open file");
        }
        else
        {
            printw("You opened file");
        }

}

void Menu::DrawCursor(int ypos)
{
    move(ypos+1,0);
    printw(">");
}

void Menu::EventHandler(bool *exit_flag)
{
    string testowy[100] = {"a","b","c","e","t","2","5","1","8","h","d","a","d","er","q","t","y","z","q","Y","q","a","o","a","]"};
    PassList pl;
    FileLister fl;
    switch (getch())
    {
    case KEY_DOWN:
        if(menu_pos<members)
            menu_pos++;
        else
            menu_pos = 1;
        
        break;
    case KEY_UP:
        if(menu_pos>1)
            menu_pos--;
        else
            menu_pos = members;
        break;
    case '\n':
        if(menu_pos == 1)
            fl.ShowDirList(&file_path,&pass_file);
        if(menu_pos == 2)
            pl.ShowList(testowy);
        if(menu_pos == 3)
            *exit_flag = true;
            
    }
}