#pragma once

#include "pch.h"

enum class Roles
{
	administrator,
	user,
	guest
};

class User
{
private:
	short int id;
	std::string username, password;
	std::string firstName, lastName;
	short int age;
	Roles userRole;

public:
	void registerUser();
	int getLastId();
	int incrementId();
	void addUserToFile(User);
};