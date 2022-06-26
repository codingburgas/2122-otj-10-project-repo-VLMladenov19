#include "pch.h"
#include "login-user-files.h"

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

void addCurrentUser(std::string username)
{
	std::ofstream file("../pm.dal/files/currentUser.txt", std::ios::trunc);

	file << username << "\n";

	file.close();
}

int getCurrentUserRole()
{
	std::ifstream file("../pm.dal/files/currentUser.txt");
	std::string line;

	getline(file, line);

	std::string username = line;

	file.close();

	std::ifstream fileUsers("../pm.dal/files/userInfo.txt");

	while (getline(fileUsers, line))
	{
		if (getUsername(line) == username)
		{
			return stoi(getRole(line));
		}
	}
	return 0;
}