#pragma once
#include "ServiceBase.h"
#include "User.h"

class UserService : public ServiceBase<User>
{
public:
	void add(User item) override{
		items.push_back(item);
	}

	void remove(User item) override{
		
		items.erase(getUserByLogin(item.getLogin()));
	}

	void update(User oldItem, User newItem) override {
		/*auto iter = getUserByLogin(oldItem.getLogin());
		(*iter).setName(newItem.getName());*/

		auto iter = items.begin();

		while (iter != items.end()) {
			if ((*iter).getLogin() == oldItem.getLogin()) {
				break;
			}
			iter++;
		}

		if (iter == items.end())
			throw new exception("no user found");

		(*iter).setLogin(newItem.getLogin());
		(*iter).setName(newItem.getName());
		(*iter).setPassword(newItem.getPassword());
	}

	vector<User>::const_iterator getUserByLogin(string login) const {
		auto iter = items.begin();

		while (iter != items.end()) {
			if ((*iter).getLogin() == login) {
				break;
			}
			iter++;
		}

		if (iter == items.end())
			throw new exception("no user found");

		return iter;
	}
};

