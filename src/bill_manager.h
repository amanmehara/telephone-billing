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

#ifndef TELBILL_BILL_MANAGER_H_
#define TELBILL_BILL_MANAGER_H_

#include <map>
#include <optional>
#include <string>

#include "rate.h"
#include "bill.h"

class BillManager
{
	std::map<std::string, Bill> bills_map_;
	Rate rate_;

  public:
	BillManager(Rate rate)
		: rate_(rate)
	{
	}

	void AddBill(std::string phone_number, int calls, double data_usage, int messages);

	std::optional<Bill> RemoveBill(std::string phone_number);

	std::optional<Bill> GetBill(std::string phone_number);

	void Persist();

	void Populate();
};

#endif // TELBILL_BILL_MANAGER_H_