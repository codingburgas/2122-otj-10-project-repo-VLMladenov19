#pragma once

#include "pch.h"
#include "../pm.dal/UserStore.h"

namespace pm::bll
{
	struct UserManager
	{
		pm::dal::UserStore m_userStore;
		std::string hashString(std::string);

		void registerUser(std::string, std::string, uint8_t, std::string, std::string);
		pm::types::User loginUser(std::string, std::string);
		std::vector<pm::types::User> getRegisteredUsers();

		void seedDataBase();

		void removeUser(size_t);

		void updateUser(pm::types::User);
	};
}