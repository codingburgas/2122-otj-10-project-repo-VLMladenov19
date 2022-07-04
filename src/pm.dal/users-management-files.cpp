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

	for (int i = 0; i < 2; i++)
	{
		line.erase(0, pos + 1);
		pos = line.find(',');
	}

	return line.substr(0, pos);
}

std::string getFirstName(std::string line)
{
	int pos = line.find(',');

	for (int i = 0; i < 3; i++)
	{
		line.erase(0, pos + 1);
		pos = line.find(',');
	}

	return line.substr(0, pos);
}

std::string getLastName(std::string line)
{
	int pos = line.find(',');

	for (int i = 0; i < 4; i++)
	{
		line.erase(0, pos + 1);
		pos = line.find(',');
	}

	return line.substr(0, pos);
}

std::string getAge(std::string line)
{
	int pos = line.find(',');

	for (int i = 0; i < 5; i++)
	{
		line.erase(0, pos + 1);
		pos = line.find(',');
	}

	return line.substr(0, pos);
}

std::string getRole(std::string line)
{
	int pos = line.find(',');

	for (int i = 0; i < 6; i++)
	{
		line.erase(0, pos + 1);
		pos = line.find(',');
	}

	return line;
}

void addEditedUser(int id, std::string username, std::string password, std::string fName, std::string lName, short age, int role)
{
	std::ifstream users("../pm.dal/files/userInfo.txt");
	std::string line;

	std::ofstream file("../pm.dal/files/tempFile.txt", std::ios::trunc);

	getline(users, line);
	file << line << '\n';
	while (stoi(getId(line)) != id)
	{
		getline(users, line);
		if (stoi(getId(line)) != id)
		{
			file << line << '\n';
		}
	}

	file << id << ",";
	file << username << ",";
	file << md5(password) << ",";
	file << fName << ",";
	file << lName << ",";
	file << age << ",";
	file << role << "\n";

	while (getline(users, line))
	{
		file << line << '\n';
	}

	users.close();
	file.close();

	std::ofstream allUsers("../pm.dal/files/userInfo.txt", std::ios::trunc);
	std::ifstream temporary("../pm.dal/files/tempFile.txt");

	while (getline(temporary, line))
	{
		allUsers << line << '\n';
	}

	allUsers.close();
	temporary.close();
}

void deleteUser(int id)
{
	std::ifstream users("../pm.dal/files/userInfo.txt");
	std::string line;

	std::ofstream file("../pm.dal/files/tempFile.txt", std::ios::trunc);

	getline(users, line);
	file << line << '\n';
	while (stoi(getId(line)) != id)
	{
		getline(users, line);
		if (stoi(getId(line)) != id)
		{
			file << line << '\n';
		}
	}

	while (getline(users, line))
	{
		file << stoi(getId(line)) - 1 << ",";
		file << getUsername(line) << ",";
		file << md5(getPassword(line)) << ",";
		file << getFirstName(line) << ",";
		file << getLastName(line) << ",";
		file << getAge(line) << ",";
		file << getRole(line) << "\n";
	}

	users.close();
	file.close();

	std::ofstream allUsers("../pm.dal/files/userInfo.txt", std::ios::trunc);
	std::ifstream temporary("../pm.dal/files/tempFile.txt");

	while (getline(temporary, line))
	{
		allUsers << line << '\n';
	}

	allUsers.close();
	temporary.close();
}