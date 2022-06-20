#include "pch.h"
#include "register-user-files.h"

User::User(std::string userUsername, std::string userPassword, std::string userFirstName, std::string userLastName, short userAge, Roles userRole)
{
	id = 0;
	incrementId();
	username = userUsername;
	password = userPassword;
	password = md5(password);
	firstName = userFirstName;
	lastName = userLastName;
	age = userAge;
	role = userRole;
}

void User::addUserToFile()
{
	std::ofstream file("../pm.dal/files/userInfo.txt", std::ios::app);

	file << id << ",";
	file << username << ",";
	file << password << ",";
	file << firstName << ",";
	file << lastName << ",";
	file << age << ",";
	file << int(role) << "\n";

	file.close();
}

void User::incrementId()
{
	std::ifstream file("../pm.dal/files/userInfo.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line != "")
			id = stoi(line);
	}

	id += 1;
}

bool User::usernameExists()
{
	std::ifstream file("../pm.dal/files/userInfo.txt");
	std::string line;
	std::string tempUsername;
	
	while (getline(file, line))
	{
		line.erase(0, 2);
		int pos = line.find(',');
		tempUsername = line.substr(0, pos);
	}

	if (username == tempUsername)
		return true;
	return false;
}