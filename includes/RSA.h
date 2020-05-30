#include <iostream>
#include <math.h>
using namespace std;
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