#include "pch.h"
#include "register-user-files.h"

User::User(std::string userUsername, std::string userPassword, std::string userFirstName, std::string userLastName, short userAge, Roles userRole)
{
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
		id = stoi(line);
	}

	id += 1;
}