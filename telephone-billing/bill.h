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

#ifndef TELBILL_BILL_H_
#define TELBILL_BILL_H_

#include <fstream>
#include <string>
#include <vector>

#include "rate.h"

class TelephoneBill
{
	std::string phone_number_;
	int incoming_calls_;
	int outgoing_calls_;
	double data_usage_;
	int messages_;
	double bill_amount_;
	Rate rate_;

  public:
	TelephoneBill(std::string phone_number, int incoming_calls, int outgoing_calls, double data_usage, int messages, Rate rate)
		: phone_number_(phone_number), incoming_calls_(incoming_calls), outgoing_calls_(outgoing_calls), data_usage_(data_usage), messages_(messages), rate_(rate)
	{
	}

	void ComputeBill();

	std::string PhoneNumber()
	{
		return phone_number_;
	}
};

#endif // TELBILL_BILL_H_