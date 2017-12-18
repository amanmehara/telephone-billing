#pragma once

#include <map>
#include <optional>
#include <string>

#include "rate.h"
#include "telephone_bill.h"

using namespace std;

class TelephoneBillManager {

	map<string, TelephoneBill> telephone_bills_map_;
	Rate rate_;

public:

	TelephoneBillManager(Rate rate) 
		: rate_(rate)
	{}

	void AddBill(string phone_number, int incoming_calls, int outgoing_calls, double data_usage, int messages);

	optional<TelephoneBill> RemoveTelephoneBill(string phone_number);

	optional<TelephoneBill> GetTelephoneBill(string phone_number);

	void Persist();

	void Populate();

};