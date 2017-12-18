#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "rate.h"

using namespace std;

class TelephoneBill {

	string phone_number_;
	int incoming_calls_;
	int outgoing_calls_;
	double data_usage_;
	int messages_;
	double bill_amount_;
	Rate rate_;

public:

	TelephoneBill(string phone_number, int incoming_calls, int outgoing_calls, double data_usage, int messages, Rate rate)
		: phone_number_(phone_number), incoming_calls_(incoming_calls), outgoing_calls_(outgoing_calls), data_usage_(data_usage), messages_(messages), rate_(rate)
	{}

	void ComputeBill();
	
	string PhoneNumber() {
		return phone_number_;
	}

};