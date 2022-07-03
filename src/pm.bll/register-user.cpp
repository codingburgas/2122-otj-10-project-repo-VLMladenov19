#include "pch.h"
#include "register-user.h"

bool User::checkPassword()
{
	if (password.length() < 8)
	{
		std::cout << "Password needs to be at least 8 characters!\n";
		return false;
	}
	if (!stringHasNumbers(password))
	{
		std::cout << "Password needs to have numbers in it!\n";
		return false;
	}
	if (!stringHasSymbols(password))
	{
		std::cout << "Password needs to have at least one symbols int it(~`!@#$%^&*()_-+={[}]|:;\'<,>.?\\/\")!\n";
		return false;
	}
	return true;
}

void registerUser()
{
	system("cls");
	std::cout << "Register user\n\n";

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

	if (!tempUser.checkPassword())
	{
		registerUser();
		return;
	}
	else if (tempUser.usernameExists())
	{
		std::cout << "Username already exists!\n";
		registerUser();
	}
	else
	{
		tempUser.addUserToFile();
	}
}

bool stringHasNumbers(std::string text)
{
	bool flag = false;

	for (int i = 48; i <= 57; i++)
	{
		if (text.find(char(i)) != std::string::npos)
			flag = true;
	}

	return flag;
}

bool stringHasSymbols(std::string text)
{
	bool flag = false;

	for (int i = 33; i <= 47; i++)
	{
		if (text.find(char(i)) != std::string::npos)
			flag = true;
	}

	return flag;
}