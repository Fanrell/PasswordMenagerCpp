#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Account.h"

using namespace std;

Account::Account()
{

}

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

string Account::Generate()
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

string Account::Stringer()
{
	string pss;
	pss = "Service: "+service+" Login: "+login+" Password: "+password;
	return(pss);
}
string Account::Service()
{
	return(service);
}