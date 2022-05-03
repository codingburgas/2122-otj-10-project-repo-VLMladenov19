#pragma once

#include "pch.h"
#include "../pm.types/User.h"

namespace pm::dal
{
	// CRUD - CREATE, READ, UPDATE, DELETE

	struct UserStore
	{
		void create(pm::types::User&);
		pm::types::User getById(size_t);
		pm::types::User getByEmail(std::string);
		std::vector<pm::types::User> getAll();
		void remove(size_t);
		void update(pm::types::User);
	};
}