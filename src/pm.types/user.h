#pragma once

#include "pch.h"
#include "../pm.tools/md5.h"

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
	Roles role;

public:
	User(std::string, std::string, std::string, std::string, short, Roles);
	void addUserToFile();
	void incrementId();
};