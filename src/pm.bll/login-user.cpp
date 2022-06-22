#include "pch.h"
#include "login-user.h"

void loginUser()
{
	std::cout << "Login user\n\n";

	std::string username, password;

	std::cout << "Username: ";
	std::cin >> username;

	std::cout << "Password: ";
	std::cin >> password;

	if (userIsRegistered(username, password))
	{
		std::cout << "You are in!\n";
		return;
	}
	std::cout << "There is no such user!\n";
}

bool userIsRegistered(std::string username, std::string password)
{
	std::ifstream file("../pm.dal/files/userInfo.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line.find(username) != std::string::npos && line.find(md5(password)) != std::string::npos)
		{
			return true;
		}
	}

	return false;

	file.close();
}