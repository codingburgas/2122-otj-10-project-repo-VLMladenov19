#include "pch.h"
#include "register-user.h"

void User::registerUser()
{
	User tempUser;

	Roles role = Roles::administrator;

	tempUser.id = 0;
	std::cin >> tempUser.username >> tempUser.password;
	std::cin >> tempUser.firstName >> tempUser.lastName;
	std::cin >> tempUser.age;
	tempUser.userRole = role;

	addUserToFile(tempUser);
}