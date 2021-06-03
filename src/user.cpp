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

#include "user.h"

#include <format>
#include <iostream>
#include <stdexcept>

namespace telbill {

std::ostream& operator<<(std::ostream& os, const user& u)
{
    os << std::format("{{'name': '{}', 'phone': '{}', 'city': '{}'}}", u.name_, u.phone_, u.city_);
    return os;
}

void user::add_bill(std::shared_ptr<bill> b)
{
    if (b == nullptr) {
        throw std::invalid_argument("Bill is null.");
    }
    if (b->get_phone() != phone_) {
        throw std::invalid_argument("Phone number mismatch.");
    }
    bills_.push_back(b);
}

void user::remove_bill(std::shared_ptr<bill> b)
{
    if (b == nullptr) {
        throw std::invalid_argument("Bill is null.");
    }
    if (b->get_phone() != phone_) {
        throw std::invalid_argument("Phone number mismatch.");
    }
    for (auto it = bills_.begin(); it != bills_.end(); it++) {
        if (*it == b) {
            bills_.erase(it);
            break;
        }
    }
}

const std::shared_ptr<bill> user::get_bill(const int& month, const int& year)
{
    for (const auto& bill : bills_) {
        if (bill->get_bill_month() == month && bill->get_bill_year() == year) {
            return bill;
        }
    }
    return nullptr;
}

} // namespace telbill
