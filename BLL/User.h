#pragma once
#include <iostream>
using namespace std;

class User
{
public:
	User(){}
	User(string name, string login, string password) 
		: name(name), login(login), password(password){}

	string getName() const { return name; }
	string getLogin() const { return login; }
	string getPassword() const { return password; }

	void setName(string name) { this->name = name; }
	void setLogin(string login) { this->login = login; }
	void setPassword(string password) { this->password = password; }

private:
	string name;
	string login;
	string password;
};

