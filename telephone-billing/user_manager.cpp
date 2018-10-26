// Copyright 2018 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "user_manager.h"

#include <optional>
#include <string>

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

const map<string, User> UserManager::AllUsers()
{
	return users_map_;
}

void UserManager::Persist() {

}

void UserManager::Populate() {

}