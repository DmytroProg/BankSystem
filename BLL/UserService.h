#pragma once
#include "ServiceBase.h"
#include "User.h"
#include "EqualPred.h"

class UserService : public ServiceBase<User>
{
public:

	void remove(User item) override{
		try {
			auto user = find_if(items.begin(), items.end(),
				[item](const User& u) { return u.getLogin() == item.getLogin(); });
			items.erase(user);
			logger.LogInfo("User " + item.getLogin() + " was removed");
		}
		catch (exception& ex) {
			logger.LogError(ex);
		}
	}

	void update(User oldItem, User newItem) override {
		try {
			auto user = find_if(items.begin(), items.end(),
				[oldItem](const User& u) { return u.getLogin() == oldItem.getLogin(); });

			if (user == items.end())
				throw new exception("no user found");

			(*user).setLogin(newItem.getLogin());
			(*user).setName(newItem.getName());
			(*user).setPassword(newItem.getPassword());
			logger.LogInfo("User " + oldItem.getLogin() + " was updated");
		}
		catch (exception& ex) {
			logger.LogError(ex);
		}
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

