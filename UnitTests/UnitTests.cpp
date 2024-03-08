#include "pch.h"
#include "CppUnitTest.h"
#include "../BLL/User.h"
#include "../BLL/UserService.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UserTest)
	{
	public:
		
		TEST_METHOD(TestLogin)
		{
			User user("John", "", "qwerty");
			string logins[] = {
				"",
				"login",
				"login@",
				"login@."
				"login@.com",
				"login..",
				"@gmail.com",
				"login@gmail"
			};
			UserService userService;

			int count = 0;
			for (int i = 0; i < 8; i++) {
				user.setLogin(logins[i]);
				count += userService.isValid(user);
			}

			Assert::AreEqual(0, count);
		}
	};
}
