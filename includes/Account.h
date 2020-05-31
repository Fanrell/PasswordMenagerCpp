#include <iostream>

using namespace std;

class Account
{
	string service;
	string login;
	string password;
	private:
		string Generate();
	public:
		Account();
		Account(string service, string login);
		Account(string service, string login, string password);
		string Stringer();
		string Service();
};