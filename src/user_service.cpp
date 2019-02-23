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

#include "user_service.h"

#include <optional>
#include <string>

#include "user.h"

void user_service::add_user(user& user) {
    std::string phone_number = user.phone_number();
    if (users_map_.find(phone_number) != users_map_.end()) {
        throw std::runtime_error("User already there.");
    }
    users_map_.insert(std::make_pair<>(phone_number, user));
}

std::optional<user> user_service::remove_user(std::string phone_number) {
    std::map<std::string, user>::iterator it = users_map_.find(phone_number);
    if (it != users_map_.end()) {
        user user = it->second;
        users_map_.erase(it);
        return std::make_optional(user);
    } else {
        return std::nullopt;
    }
}

std::optional<user> user_service::get_user(std::string phone_number) {
    std::map<std::string, user>::iterator it = users_map_.find(phone_number);
    return it != users_map_.end()
               ? std::make_optional(it->second)
               : std::nullopt;
}

const std::map<std::string, user> user_service::all_users() {
    return users_map_;
}
