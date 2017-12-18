#pragma once

#include <map>
#include <optional>
#include <string>

#include "user.h"

using namespace std;

class UserManager {

	map<string, User> users_map_;

public:

	void AddUser(User &user);

	optional<User> RemoveUser(string phone_number);

	optional<User> GetUser(string phone_number);

	void Persist();

	void Populate();

};