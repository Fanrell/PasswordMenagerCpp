
#include "FileLister.h"
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
    string tmp;
    DIR *new_folder;
    string line;
    switch (getch())
    {
    case KEY_DOWN:
        if(point_pos<end - start - 1)
            point_pos++;
        else
            point_pos = 0;
        break;
    case KEY_UP:
        if(point_pos>0)
            point_pos--;
        else
            point_pos = end-start-1;
        break;
    case KEY_RIGHT:
        if(all_members > 10)
        {
            if(end+10<all_members)
            {
                start+=10;
                end += 10;
                mod += 10;
            }
            else
            {
                start = end;
                mod += 10;
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
        else if (new_folder == NULL)
        {
            tmp = v[point_pos+mod];
            if(tmp.substr(tmp.find(".") + 1) == "pssmg")
            {
                read_pass.open(*path + "/" + tmp);
                tmp = Inputer("Password: ");
                if(tmp.size() != 0)
                {
                    coder.KeyGenerate(tmp);
                    getline(read_pass,line);
                    if(coder.Decrypt(line) == "test")
                    {
                        for(line; getline(read_pass,line);)
                        {
                            deco += coder.Decrypt(line);
                        }
                    }
                    read_pass.close();
                    *exit = true;
                }
            }

        }
        
        
        break;
    case KEY_N:
        tmp = Inputer("File name: ");
        tmp += EXT;
        if(!ifstream(tmp).good())
        {
            pass_file.open(*path+"/"+tmp);
            move(end+3,0);
            do
            {
            tmp = Inputer("Password: ");
            }while(tmp.size() < 8 );
            coder.KeyGenerate(tmp);
            pass_file << coder.Encrypt("test");
            *exit = true;
        }
        break;
    case KEY_D:
        new_folder = opendir((*path + "/" + v[point_pos + mod]).c_str());
        if (new_folder == NULL)
        {
            tmp = v[point_pos+mod];
            if(tmp.substr(tmp.find(".") + 1) == "pssmg")
            {
                read_pass.open(*path + "/" + tmp);
                tmp = Inputer("Password: ");
                coder.KeyGenerate(tmp);
                getline(read_pass,line);
                if(coder.Decrypt(line) == "test")
                {
                    remove((*path + "/" + v[point_pos+mod]).c_str());
                }
            }
        }
        break;

    case KEY_S:
    new_folder = opendir((*path + "/" + v[point_pos + mod]).c_str());
    if (new_folder == NULL)
        {
            tmp = v[point_pos+mod];
            if(tmp.substr(tmp.find(".") + 1) == "pssmg")
            {
                read_pass.open(*path + "/" + tmp);
                tmp = Inputer("Password: ");
                coder.KeyGenerate(tmp);
                getline(read_pass,line);
                if(coder.Decrypt(line) == "test")
                {
                    read_pass.close();
                    pass_file.open(*path + "/" + v[point_pos+mod]);
                    pass_file << coder.Encrypt("test");
                    pass_file << "\n";
                    pass_file << coder.Encrypt(deco);
                    pass_file.close();
                    *exit = true;
                }
                
            }

        }
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
    printw("Open: Enter, Move: Arrows, (n)ew, (s)ave, (d)elete ,(q)uit\n");
    move(3,0);
}

string FileLister::ShowDirList(string *path,string decoded)
{
    cbreak();
    all_members = 100;
    bool exit = false;
    stringvec dir_list;
    deco = decoded;
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
    return deco;
    
}