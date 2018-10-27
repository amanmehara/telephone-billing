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
#include "telephone_bill.h"

using namespace std;

class TelephoneBillManager
{

	map<string, TelephoneBill> telephone_bills_map_;
	Rate rate_;

  public:
	TelephoneBillManager(Rate rate)
		: rate_(rate)
	{
	}

	void AddBill(string phone_number, int incoming_calls, int outgoing_calls, double data_usage, int messages);

	optional<TelephoneBill> RemoveTelephoneBill(string phone_number);

	optional<TelephoneBill> GetTelephoneBill(string phone_number);

	void Persist();

	void Populate();
};

#endif // TELBILL_BILL_MANAGER_H_