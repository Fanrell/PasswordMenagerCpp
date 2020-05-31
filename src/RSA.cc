#include "RSA.h"

using namespace std;
//https://eduinf.waw.pl/inf/alg/001_search/0067.php

int RSA::PrivateValue(int e, int ro)
{
    int d = 1;

    while( ( d * e ) % ro != 1) d++;

    return d;
}

bool RSA::CheckPrimal(int value)
{
    if(value <= 1) return false;
    else if (value == 2) return true;
    else if (value %2 == 0) return false;

    int range = static_cast<int>(floor(sqrt(value)));

    for (int i = 3; i <= range; i++)
    {
        if(value % i == 0) return false;
    }

    return true;
}

int RSA::IsPrimal(int value)
{
    int i = 0;
    while(!CheckPrimal(value)) value++;

    return value;
}

int RSA::Nwd(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int RSA::Pot_Horn(int value, int w, int n)
{
    int pot = value;
    int wyn = 1;
    for(int q = w; q>0; q /= 2)
    {
        if(q%2) 
            wyn = (wyn * pot) % n;
        pot = (pot * pot) % n;
    }
    return wyn;
}

void RSA::KeyGenerate(string password)
{
    int primals[] = { 0, 0 };
    int i = 0, start = 0;
    int e = 512;
    int border = floor(password.length()/2);
    int end = border;
    while(i<2)
    {
        for(int z = start; start<=border;start++)
        {
            primals[i] += static_cast<int>(password[z]);
        }
        i++;
        start = (int)border + 1;
        end = password.length();
    }
    primals[0] =  IsPrimal(primals[0]);
    primals[1] =  IsPrimal(primals[1]);
    int ro = (primals[0] - 1) * (primals[1] - 1);
    int n = primals[0] * primals[1];
    for(e = 3; Nwd(e,ro) != 1; e += 2);
    int d = PrivateValue(e,ro);
    puk[0] = e;
    puk[1] = n;
    prk[0] = d;
    prk[1] = n;
}
void RSA::Keys(int a, int b, int c, int d)
{
    puk[0] = a;
    puk[1] = b;
    prk[0] = c;
    prk[1] = d;
}
string RSA::Encrypt(string data)
{
    string encrypted = "";
    int c;
    for(int i = 0; i<data.length(); i++)
    {
        c = static_cast<int>(data[i]);
        encrypted += to_string((Pot_Horn(c, puk[0], puk[1] )));
        encrypted += ";";
    }

    return encrypted;
}

string RSA::Decrypt(string data)
{
    string decrypted = "";
    string tmp = "";
    int c;
    for(int i = 0; i<data.length(); i++)
    {
        if(data[i]  != ';')
        {
            tmp += data[i];
        }
        else
        {
            c = stoi(tmp);
            decrypted += Pot_Horn(c,prk[0],prk[1]);
            tmp = "";
        }
    }

    return decrypted;
}