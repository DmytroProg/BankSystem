#pragma once
#include <iostream>
#include "../BLL/ServiceBase.h";
#include "../BLL/UserService.h";
#include "../BLL/CardService.h";
#include "../BLL/User.h";
using namespace std;

class App
{
public:
	App()
	{
		userService = new UserService();
		cardService = new CardService();

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
			currentUser = &(*user);
		}
		else if (index == 2) {
			currentUser = new User();
			string data;

			cout << "Enter name: ";
			cin >> data;
			currentUser->setName(data);

			cout << "Enter login: ";
			cin >> data;
			currentUser->setLogin(data);

			cout << "Enter password: ";
			cin >> data;
			currentUser->setPassword(data);

			userService->add(*currentUser);
		}

		while (true) {
			// add card 
			// block card
			// see all credits
			// add balance to card
			// transaction
			// see all transactions
			index = menu();
			switch (index) {
			case 1: 
				{
				Card card;
				string data;
				cout << "Enter number: ";
				cin >> data;
				card.setNumber(data);

				cout << "Enter cvv: ";
				cin >> data;
				card.setCVV(stoi(data));

				cout << "Enter expired month: ";
				cin >> data;
				card.setExpiredMonth(stoi(data));

				cout << "Enter expired day: ";
				cin >> data;
				card.setExpiredDay(stoi(data));

				cardService->add(card);
				currentUser->cards.push_back(card);
				}
				break;
			case 2:
				for (const auto card : currentUser->cards) {
					cout << "---------------------------" << endl;
					cout << "Number: " << card.getNumber() << endl;
					cout << "CVV: " << card.getCVV() << endl;
					cout << "Exp. data: " << card.getExpiredMonth() << "/" << card.getExpiredDay() << endl;
					cout << "---------------------------" << endl;
				}
				break;
			case 3: {
				string number;
				cout << "Enter number: ";
				// validate
				cin >> number;

				Card card;
				card.setNumber(number);

				//cardService->find(func);
				// validate
				cardService->remove(card);
				auto userCard = find_if(currentUser->cards.begin(), currentUser->cards.end(),
					[number](const Card& c) { return c.getNumber() == number; });
				currentUser->cards.erase(userCard);
			}
		    break;
			}
			system("PAUSE");
			system("CLS");
		}
	}

private:
	ServiceBase<User>* userService;
	ServiceBase<Card>* cardService;
	User* currentUser;

	int menuLogin() {
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;

		int n;
		cin >> n;
		return n;
	}

	int menu() {
		cout << "1. Add card" << endl;
		cout << "2. See cards" << endl;
		cout << "3. Remove card" << endl;
		cout << "4. Add balance" << endl;
		cout << "5. Exit" << endl;

		int n;
		cin >> n;
		return n;
	}
};

