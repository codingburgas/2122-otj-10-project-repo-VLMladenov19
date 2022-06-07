#include "pch.h"
#include "register-user.h"

void registerUser()
{
	short age;
	std::string username, password, firstName, lastName;
	std::cin >> username >> password;
	std::cin >> firstName >> lastName;
	std::cin >> age;
	Roles role = Roles::administrator;

	User tempUser(username, password, firstName, lastName, age, role);

	tempUser.addUserToFile();
}