#include <iostream>

class Account
{
	std::string service;
	std::string login;
	std::string password;
	private:
		std::string Generate();
	public:
		Account(std::string service, std::string login);
		Account(std::string service, std::string login, std::string password);
		std::string ToString();
};