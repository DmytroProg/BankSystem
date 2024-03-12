#pragma once
#include "ServiceBase.h"
#include "User.h"
#include "EqualPred.h"

class UserService : public ServiceBase<User>
{
public:
	void remove(User item) override{
		
		//TODO
		/*auto user = find_if(items.begin(), items.end(),
			[item](const User& u) { return u.getLogin() == item.getLogin(); });
		items.erase(user);*/
	}

	void update(User oldItem, User newItem) override {
		auto user = find_if(items.begin(), items.end(),
			[oldItem](const User& u) { return u.getLogin() == oldItem.getLogin(); });

		if (user == items.end())
			throw new exception("no user found");

		(*user).setLogin(newItem.getLogin());
		(*user).setName(newItem.getName());
		(*user).setPassword(newItem.getPassword());
	}

	bool isValid(const User& user) override {
		if (user.getName().empty())
			return false;

		if (user.getLogin().empty())
			return false;

		if (user.getPassword().empty())
			return false;

		return true;
	}
};

