#include "../pm.bll/pch.h"
#include "users-management-menu.h"

void printUsersManagement()
{
	system("cls");

	std::cout << "1. Delete user by ID   2. Edit user's information   3. Exit\n\n\n";

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

	switch (_getch())
	{
	case '1':
		system("cls");
		deleteUserById();
		break;
	case '2':
		system("cls");
		editUserById();
		break;
	}
}

void editUserById()
{
	int id;
	std::cout << "Input the id of the user you want to edit: ";
	std::cin >> id;

	std::string username, password;
	std::string fName, lName;
	short age;
	int role;

	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Password: ";
	std::cin >> password;
	std::cout << "First Name: ";
	std::cin >> fName;
	std::cout << "Last Name: ";
	std::cin >> lName;
	std::cout << "Age: ";
	std::cin >> age;
	std::cout << "Role(0-admin, 1-user): ";
	std::cin >> role;

	addEditedUser(id, username, password, fName, lName, age, role);

	std::cout << "User edited!\n";
	_getch();
}

void deleteUserById()
{
	int id;
	std::cout << "Insert the id of the user you want to edit: ";
	std::cin >> id;

	deleteUser(id);

	std::cout << "User deleted!\n";
	_getch();
}