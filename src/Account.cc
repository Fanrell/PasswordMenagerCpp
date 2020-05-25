#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Account.h>

using namespace std;



Account::Account(string service, string login)
{
	this->service = service;
	this->login = login;
	this->password = Generate();
}

Account::Account(string service, string login, string password)
{
	this->service = service;
	this->login = login;
	this->password = password;
}

std::string Account::Generate()
{
	int len = 8 + (rand() % ( 16 - 8 + 1) );
	int ch;
	string pass;
	srand(time(NULL));
	for(int i = 0; i<len; i++)
	{
		ch = 33 + ( rand() % (126 - 33 + 1 ) );
		pass += static_cast<char>(ch);
	}
	return pass;
}

std::string Account::ToString()
{
	string pss;
	pss = service+" "+login+" "+password;
	return(pss);
}

int main()
{
	Account a("test","testlogin");
	cout << a.ToString()<<endl;
	return 0;
}
