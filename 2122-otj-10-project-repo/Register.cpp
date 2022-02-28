#include "Register.h";

void inputUserInfo()
{
	std::string fName, lName;
	std::cin >> fName >> lName;
	std::cout << fName << " " << lName;
	writeToFile(fName, lName);
}

void writeToFile(std::string fName, std::string lName)
{
	std::ofstream MyFile("userInfo.txt");
	MyFile << fName << " " << lName << std::endl;
	MyFile.close();
}