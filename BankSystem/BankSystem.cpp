#include <iostream>
#include "../BLL/UserService.h"

int main()
{
    UserService userService;

    User user("John", "user@gmail.com", "qwerty");
    User user1("Alice", "alice@gmail.com", "qwerty");
    userService.add(user);
    userService.update(user, user1);
    //userService.remove(user);

    for (auto u : userService.getAll()) {
        cout << u.getName() << endl;
    }
}
