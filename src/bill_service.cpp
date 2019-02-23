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

#include <optional>
#include <string>

#include "bill.h"
#include "rate.h"

void bill_service::add_bill(std::string phone_number, int calls, double data, int messages) {
    if (bills_map_.find(phone_number) != bills_map_.end()) {
        throw std::runtime_error("Bill already there.");
    }
    bills_map_.insert(std::make_pair<>(phone_number, bill(phone_number, calls, data, messages, rate_)));
}

std::optional<bill> bill_service::remove_bill(std::string phone_number) {
    std::map<std::string, bill>::iterator it = bills_map_.find(phone_number);
    if (it != bills_map_.end()) {
        bill bill = it->second;
        bills_map_.erase(it);
        return std::make_optional(bill);
    } else {
        return std::nullopt;
    }
}

std::optional<bill> bill_service::get_bill(std::string phone_number) {
    std::map<std::string, bill>::iterator it = bills_map_.find(phone_number);
    return it != bills_map_.end()
               ? std::make_optional(it->second)
               : std::nullopt;
}

void bill_service::persist() {
}

void bill_service::populate() {
}
