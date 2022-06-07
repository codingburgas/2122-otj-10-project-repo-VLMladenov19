#include "pch.h"
#include "register-user.h"

void registerUser()
{
	std::string username, password;
	std::string firstName, lastName;
	short age;

	std::cout << "Username: ";
	std::cin >> username;
	
	std::cout << "Password: ";
	std::cin>> password;

	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Last Name: ";
	std::cin >> lastName;

	std::cout << "Age: ";
	std::cin >> age;

	Roles role = Roles::user;

	User tempUser(username, password, firstName, lastName, age, role);

	tempUser.addUserToFile();
}