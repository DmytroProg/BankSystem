#pragma once
#include <iostream>
#include "../BLL/ServiceBase.h";
#include "../BLL/UserService.h";
#include "../BLL/User.h";
using namespace std;

class App
{
public:
	App()
	{
		userService = new UserService();
		User user("John", "login", "1234");
		userService->add(user);
	}

	void run() {
		int index = menuLogin();

		if (index == 1) {
			cout << "Enter login: ";
			string login;
			cin >> login;
			auto users = userService->getAll();
			auto user = find_if(users.begin(), users.end(), 
				[login](User u) { return u.getLogin() == login; });

			cout << (*user).getName() << endl;
		}
		else if (index == 2) {
			User user;
			string data;

			cout << "Enter name: ";
			cin >> data;
			user.setName(data);

			cout << "Enter login: ";
			cin >> data;
			user.setLogin(data);

			cout << "Enter password: ";
			cin >> data;
			user.setPassword(data);

			userService->add(user);
		}
	}

private:
	ServiceBase<User>* userService;

	int menuLogin() {
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;

		int n;
		cin >> n;
		return n;
	}
};

