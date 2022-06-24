#include "../pm.bll/pch.h"
#include "users-management-menu.h"

void printUsersManagement()
{
	std::vector<std::vector<std::string>> v = getAllUsers();

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << "Id: " << v[i][0] << " ";
		std::cout << "Username: " << v[i][1] << " ";
		std::cout << "Password: " << v[i][2] << " ";
		std::cout << "FirstName: " << v[i][3] << " ";
		std::cout << "LastName: " << v[i][4] << " ";
		std::cout << "Age: " << v[i][5] << " ";
		std::cout << "Role: " << v[i][6] << "\n";
	}

	std::cin.get();
	int n;
	std::cin >> n;
}