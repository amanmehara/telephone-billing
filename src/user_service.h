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

#ifndef TELBILL_USER_SERVICE_H_
#define TELBILL_USER_SERVICE_H_

#include <map>
#include <optional>
#include <string>

#include "user.h"

class user_service {
public:
    void add_user(const user& _user);

    std::optional<user> remove_user(const std::string& phone_number);

    std::optional<user> get_user(const std::string& phone_number) const;

    const std::map<std::string, user> all_users() const;

private:
    std::map<std::string, user> users_map_;
};

#endif // TELBILL_USER_SERVICE_H_
