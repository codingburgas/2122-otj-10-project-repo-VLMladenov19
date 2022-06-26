#include "../pm.bll/pch.h"
#include "../pm.types/user.h"
#include "main-menu.h"

int main()
{
	std::string adminUsername = "admin", adminPass = "adminpass";
	User admin(adminUsername, adminPass, "admin", "admin", 0, Roles::administrator);
	if (!adminUserExists())
		admin.addUserToFile();

	printMenu();
}