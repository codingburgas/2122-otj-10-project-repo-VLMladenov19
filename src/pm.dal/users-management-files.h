#pragma once

#include "pch.h"
#include "../pm.types/user.h"

std::vector<std::vector<std::string>> getAllUsers();
std::string getId(std::string);
std::string getUsername(std::string);
std::string getPassword(std::string);
std::string getFirstName(std::string);
std::string getLastName(std::string);
std::string getAge(std::string);
std::string getRole(std::string);