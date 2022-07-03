#pragma once

#include "pch.h"
#include "users-management-files.h"

bool userIsRegistered(std::string, std::string);
void addCurrentUser(std::string);
int getCurrentUserRole();
bool userLoggedIn();