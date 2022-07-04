#include "../pm.bll/pch.h"
#include "../pm.types/user.h"
#include "main-menu.h"

int main()
{
	std::ofstream file("../pm.dal/files/currentUser.txt", std::ios::trunc);
	file.close();

	std::string adminUsername = "admin", adminPass = "adminpass";
	User admin(adminUsername, adminPass, "admin", "admin", 0, Roles::administrator);
	if (!adminUserExists())
		admin.addUserToFile();

	printMenu();
}