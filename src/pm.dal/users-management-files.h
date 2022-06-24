#pragma once

#include "pch.h"
#include "../pm.types/user.h"

std::vector<std::vector<std::string>> getAllUsers();
int getId(std::string);
std::string getUsername(std::string);
std::string getPassword(std::string);
std::string getFirstName(std::string);
std::string getLastName(std::string);
int getAge(std::string);
int getRole(std::string);