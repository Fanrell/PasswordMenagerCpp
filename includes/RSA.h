#include <iostream>
#include <math.h>
using namespace std;
//https://eduinf.waw.pl/inf/alg/001_search/0067.php
class RSA
{
    int puk[2];
    int prk[2];
    private:
        int IsPrimal(int value);
        bool CheckPrimal(int value);
        int Nwd(int a, int b);
        int PrivateValue(int e, int ro);
        int Pot_Horn(int value, int pod, int wyk);
    public:
        void KeyGenerate(string password);
        string Encrypt(string data);
        string Decrypt(string data);
        void Keys(int a, int b, int c, int d);

};