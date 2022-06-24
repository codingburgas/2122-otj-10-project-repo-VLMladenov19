#include "pch.h"
#include "users-management-files.h"

std::vector<std::vector<std::string>> getAllUsers()
{
	std::ifstream file("../pm.dal/files/userInfo.txt");
	std::string line;
	int i = 0;

	std::vector<std::vector<std::string>> v;

	while (getline(file, line))
	{
		std::vector<std::string> tempV;

		std::string id = getId(line);
		tempV.push_back(id);

		std::string username = getUsername(line);
		tempV.push_back(username);

		std::string password = getPassword(line);
		tempV.push_back(password);

		std::string firstName = getFirstName(line), lastName = getLastName(line);
		tempV.push_back(firstName);
		tempV.push_back(lastName);

		std::string age = "" + getAge(line);
		tempV.push_back(age);

		std::string role = "" + getRole(line);
		tempV.push_back(role);

		v.push_back(tempV);
	}

	file.close();
	return v;
}

std::string getId(std::string line)
{
	int pos = line.find(',');
	return line.substr(0, pos);
}

std::string getUsername(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	return line.substr(0, pos);
}

std::string getPassword(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	return line.substr(0, pos);
}

std::string getFirstName(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	return line.substr(0, pos);
}

std::string getLastName(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	return line.substr(0, pos);
}

std::string getAge(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	return line.substr(0, pos);
}

std::string getRole(std::string line)
{
	int pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);
	pos = line.find(',');
	line.erase(0, pos + 1);

	return line;
}