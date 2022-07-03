#include "pch.h"
#include "login-user.h"

void loginUser()
{
	system("cls");
	std::cout << "Login user\n\n";

	std::string username, password;

	std::cout << "Username: ";
	std::cin >> username;

	std::cout << "Password: ";
	std::cin >> password;

	if (userIsRegistered(username, password))
	{
		std::cout << "You are in!\n";
		addCurrentUser(username);

		_getch();

		return;
	}
	std::cout << "There is no such user!\n";

	_getch();
}