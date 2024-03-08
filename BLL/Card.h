#pragma once
#include <iostream>
using namespace std;

class Card
{
public:
	Card() {}
	Card(string number, int cvv, int month, int day, string user_login) 
		: number(number), cvv(cvv), expired_month(month), expired_day(day), user_login(user_login)
	{

	}

	string getNumber() const { return number; }
	int getCVV() const { return cvv; }
	int getExpiredMonth() const { return expired_month; }
	int getExpiredDay() const { return expired_day; }
	string getUserLogin() const { return user_login; }

	void setNumber(string number) { this->number = number; }
	void setCVV(int cvv) { this->cvv = cvv; }
	void setExpiredMonth(int month) { this->expired_month = month; }
	void setExpiredDay(int day) { this->expired_day = day; }
	void setUserLogin(string login) { this->user_login = login; }

private:
	string user_login;
	string number;
	int cvv;
	int expired_month;
	int expired_day;
};

