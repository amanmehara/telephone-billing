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
#include <stdexcept>
#include <string>

#include "user.h"

namespace telbill {

void user_service::add_user(const user& u)
{
    auto phone = u.get_phone();
    if (users_map_.find(phone) != users_map_.end()) {
        throw std::runtime_error("User already there.");
    }
    users_map_.emplace(phone, u);
}

std::optional<user> user_service::get_user(const std::string& phone) const
{
    auto it = users_map_.find(phone);
    return it != users_map_.end() ? std::make_optional(it->second) : std::nullopt;
}

const std::map<std::string, user> user_service::all_users() const
{
    return users_map_;
}

void user_service::add_bill(std::shared_ptr<bill> b)
{
    if (b == nullptr) {
        throw std::invalid_argument("Bill is null.");
    }
    auto it = users_map_.find(b->get_phone());
    if (it != users_map_.end()) {
        it->second.add_bill(b);
    }
}

void user_service::remove_bill(std::shared_ptr<bill> b)
{
    if (b == nullptr) {
        throw std::invalid_argument("Bill is null.");
    }
    auto it = users_map_.find(b->get_phone());
    if (it != users_map_.end()) {
        it->second.remove_bill(b);
    }
}

} // namespace telbill
