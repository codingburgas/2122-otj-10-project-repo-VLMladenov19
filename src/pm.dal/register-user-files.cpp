#include "pch.h"
#include "register-user-files.h"

void User::addUserToFile(User tempUser)
{
	std::ofstream file("../pm.dal/files/userInfo.txt", std::ios::app);

	file << tempUser.id << ",";
	file << tempUser.username << ",";
	file << tempUser.password << ",";
	file << tempUser.firstName << ",";
	file << tempUser.lastName << ",";
	file << tempUser.age << ",";
	file << int(tempUser.userRole) << "\n";

	file.close();
}