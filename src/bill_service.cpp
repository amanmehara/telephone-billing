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

#include "bill_service.h"

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

#include "bill.h"

namespace telbill {

std::string bill_service::add_bill(const std::string& phone, int month, int year, int calls,
                                   double data, int messages)
{
    if (user_service_->get_user(phone).has_value()) {
        auto b = bill(phone, month, year, calls, data, messages, rate_);
        if (bills_map_.find(b.get_id()) != bills_map_.end()) {
            throw std::runtime_error("Bill already there.");
        }
        bills_map_[b.get_id()] = std::make_shared<bill>(b);
        user_service_->add_bill(bills_map_[b.get_id()]);
        return b.get_id();
    }
    else {
        throw std::runtime_error("Add the user first.");
    }
}

std::shared_ptr<bill> bill_service::remove_bill(const std::string& id)
{
    auto it = bills_map_.find(id);
    if (it != bills_map_.end()) {
        user_service_->remove_bill(it->second);
        auto bill = it->second;
        bills_map_.erase(it);
        return bill;
    }
    else {
        return nullptr;
    }
}

std::shared_ptr<bill> bill_service::get_bill(const std::string& id) const
{
    const auto& it = bills_map_.find(id);
    return it != bills_map_.end() ? it->second : nullptr;
}

std::vector<std::shared_ptr<bill>> bill_service::get_bills(const std::string& phone) const
{
    auto user_optional = user_service_->get_user(phone);
    if (user_optional.has_value()) {
        return user_optional->get_bills();
    }
    return {};
}

std::vector<std::shared_ptr<bill>> bill_service::get_bills() const
{
    std::vector<std::shared_ptr<bill>> bills;
    for (const auto& [_, bill] : bills_map_) {
        bills.push_back(bill);
    }
    return bills;
}

} // namespace telbill
