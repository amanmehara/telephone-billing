#include "user_manager.h"

#include <optional>

#include "user.h"

using namespace std;

void UserManager::AddUser(User &user) {
	
	string phone_number = user.PhoneNumber();	
	if (users_map_.find(phone_number) != users_map_.end()) {
		throw runtime_error("User already there.");
	}
	users_map_.insert(make_pair<>(phone_number, user));

}

optional<User> UserManager::RemoveUser(string phone_number) {
	map<string, User>::iterator it = users_map_.find(phone_number);
	if (it != users_map_.end()) {
		User user = it->second;
		users_map_.erase(it);
		return make_optional(user);
	}
	else {
		return nullopt;
	}

}

optional<User> UserManager::GetUser(string phone_number) {
	map<string, User>::iterator it = users_map_.find(phone_number);
	return it != users_map_.end() ? make_optional(it->second) : nullopt;
}

void UserManager::Persist() {

}

void UserManager::Populate() {

}