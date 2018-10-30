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

#include "bill_manager.h"

#include <optional>
#include <string>

#include "rate.h"
#include "bill.h"

void BillManager::AddBill(std::string phone_number, int calls, double data, int messages)
{
	if (bills_map_.find(phone_number) != bills_map_.end())
	{
		throw std::runtime_error("Bill already there.");
	}
	bills_map_.insert(std::make_pair<>(phone_number, Bill(phone_number, calls, data, messages, rate_)));
}

std::optional<Bill> BillManager::RemoveBill(std::string phone_number)
{
	std::map<std::string, Bill>::iterator it = bills_map_.find(phone_number);
	if (it != bills_map_.end())
	{
		Bill bill = it->second;
		bills_map_.erase(it);
		return std::make_optional(bill);
	}
	else
	{
		return std::nullopt;
	}
}

std::optional<Bill> BillManager::GetBill(std::string phone_number)
{
	std::map<std::string, Bill>::iterator it = bills_map_.find(phone_number);
	return it != bills_map_.end()
			   ? std::make_optional(it->second)
			   : std::nullopt;
}

void BillManager::Persist()
{
}

void BillManager::Populate()
{
}