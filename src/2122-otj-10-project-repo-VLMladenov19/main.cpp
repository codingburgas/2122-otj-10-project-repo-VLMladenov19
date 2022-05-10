#include <iostream>
#include <fstream>
#include "../pm.bll/UserManager.h"
#include "../pm.dal/UserStore.h"

int main()
{
	pm::bll::UserManager userManager;
	userManager.registerUser("Vasil", "Mladenov", 16, "VLMladenov19@codingburgas.bg", "Fac65991");
	
	std::cout << "Done";
}