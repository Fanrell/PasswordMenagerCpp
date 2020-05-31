#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include <filesystem>
#include "stringer.cc"
#include "FileLister.h"
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

string FileLister::Inputer(string prompt)
{
    keypad(stdscr,TRUE);
    int c;
    string path;
    int pos = 0;
    bool in_loop = true;
    do
    {
        move(end+2,0);
        clrtobot();
        printw(prompt.c_str());
        printw(path.c_str());
        c = getch();
        switch (c)
        {
        case('\n'):
            in_loop = false;
            break;
        case KEY_BACKSPACE:
            path = path.substr(0,path.size()-1);
            break;
        default:
            path += c;        
            break;
        }
    } while (in_loop);
    return path;
}

void FileLister::Events(bool *exit, string *path, stringvec v)
{
    string new_file;
    DIR *new_folder;
    string line;
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
                mod += 10;
            }
            else
            {
                start = all_members - 10;
                mod += all_members - 10;
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
                mod -= 10;
            }
            else
            {
                start = 0;
                end = 10;
                mod = 0;
            }
            point_pos = 0;
        }
        break;
    case '\n':
        new_folder = opendir((*path + "/" + v[point_pos + mod]).c_str());
        if(new_folder != NULL)
        {
            *path += "/" + v[point_pos+mod];
            closedir(new_folder);
            mod = 0;
            end = 10;
            start = 0;
            point_pos = 0;
        }
        else if (new_folder == NULL && v[point_pos + mod ] != "Makefile")
        {
            new_file = v[point_pos+mod];
            if(new_file.substr(new_file.find(".") + 1) == "pssmg")
            {
                read_pass.open(*path + "/" + new_file);
                new_file = Inputer("Password: ");
                coder.KeyGenerate(new_file);
                getline(read_pass,line);
                if(coder.Decrypt(line) == "test")
                {
                    for(line; getline(read_pass,line);)
                    {
                        *deco += coder.Decrypt(line);
                        *file = v[point_pos+mod];
                    }
                }
                
            }

        }
        
        
        break;
    case KEY_N:
        new_file = Inputer("File name");
        new_file += EXT;
        *file = new_file;
        pass_file.open(*path+"/"+new_file);
        move(end+3,0);
        do
        {
        new_file = Inputer("Password: ");
        }while(new_file.size() < 8);
        coder.KeyGenerate(new_file);
        pass_file << coder.Encrypt("test");
        *exit = true;
        break;
    case KEY_Q:
        *exit = true;
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
        if(i==end-1)
            break;
    }
    printw("Confirm: Enter, Move: Arrows, (N)ew, (Q)uit\n");
    move(3,0);
}

void FileLister::ShowDirList(string *path,string *filename ,string *decoded)
{
    cbreak();
    all_members = 100;
    bool exit = false;
    stringvec dir_list;
    deco = decoded;
    file = filename;
    do
    {
    read_dir(*path,dir_list);
    sort(dir_list.begin(),dir_list.end());
    all_members = dir_list.size();
    if(dir_list.size() < 10)
        end = dir_list.size();
    Listing(dir_list);
    PointerDraw(point_pos);
    Events(&exit,path, dir_list);
    dir_list.erase(dir_list.begin(),dir_list.end());
    }while(!exit);
        move(2,0);
    clrtobot();
    
}