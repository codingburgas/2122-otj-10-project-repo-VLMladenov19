#include "main-menu.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void printMenu()
{
	int option = 0;
	printOptions(option);

	int arrow;

	while (_getch() != ' ')
	{
		system("cls");
		switch ((arrow = _getch())) {
		case KEY_UP:
			if(option > 0)
				option -= 1;
			break;
		case KEY_DOWN:
			if (option < 3)
				option += 1;
			break;
		}
		printOptions(option);
	}

	switch(option)
	{
	case 0: 
		registerUser();
		_getch();
		system("cls");
		printMenu(); 
		break;

	case 1: 
		system("cls");
		if (userLoggedIn())
		{
			std::cout << "You are already logged in!\n";
			_getch();

			system("cls");
			printMenu();
			return;
		}
		loginUser();
		system("cls");
		printMenu();
		break;

	case 2:
		system("cls");
		int roleNum = getCurrentUserRole();
		if (roleNum != 0)
		{
			std::cout << "You need administrative rights!\n";
			_getch();

			system("cls");
			printMenu();
			return;
		}
		printUsersManagement();
		system("cls");
		printMenu();
		break;
	}
}

void printOptions(int arrow)
{
	switch (arrow)
	{
	case 0:
		std::cout << "--> Register user\n";
		std::cout << "    Login user\n";
		std::cout << "    Users Management\n";
		std::cout << "    Exit\n";
		break;
	case 1:
		std::cout << "    Register user\n";
		std::cout << "--> Login user\n";
		std::cout << "    Users Management\n";
		std::cout << "    Exit\n";
		break;
	case 2:
		std::cout << "    Register user\n";
		std::cout << "    Login user\n";
		std::cout << "--> Users Management\n";
		std::cout << "    Exit\n";
		break;
	case 3:
		std::cout << "    Register user\n";
		std::cout << "    Login user\n";
		std::cout << "    Users Management\n";
		std::cout << "--> Exit\n";
		break;
	}
}