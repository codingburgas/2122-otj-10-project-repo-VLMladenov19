#include "main-menu.h"

void printMenu()
{
	std::cout << "1. Register user\n";
	std::cout << "2. Login user\n";
	std::cout << "3. Exit\n";

	int option;
	std::cin >> option;

	switch(option)
	{
	case 1: system("cls"); registerUser(); system("cls"); printMenu(); break;
	case 2: system("cls"); loginUser(); system("cls"); printMenu(); break;
	}
}