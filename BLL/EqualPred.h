#pragma once
#include <string>
#include "User.h"

class EqualUserPred
{
public:
	bool operator ()(const User& user, string login) {
		return user.getLogin() == login;
	}
};

