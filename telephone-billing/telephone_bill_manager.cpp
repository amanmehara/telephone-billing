#include "telephone_bill_manager.h"

#include <optional>
#include <string>

#include "telephone_bill.h"

void TelephoneBillManager::AddBill(string phone_number, int incoming_calls, int outgoing_calls, double data_usage, int messages) {

	if (telephone_bills_map_.find(phone_number) != telephone_bills_map_.end()) {
		throw runtime_error("Bill already there.");
	}
	telephone_bills_map_.insert(make_pair<>(phone_number, TelephoneBill(phone_number, incoming_calls, outgoing_calls, data_usage, messages, rate_)));

}

optional<TelephoneBill> TelephoneBillManager::RemoveTelephoneBill(string phone_number) {
	map<string, TelephoneBill>::iterator it = telephone_bills_map_.find(phone_number);
	if (it != telephone_bills_map_.end()) {
		TelephoneBill telephone_bill = it->second;
		telephone_bills_map_.erase(it);
		return make_optional(telephone_bill);
	}
	else {
		return nullopt;
	}

}

optional<TelephoneBill> TelephoneBillManager::GetTelephoneBill(string phone_number) {
	map<string, TelephoneBill>::iterator it = telephone_bills_map_.find(phone_number);
	return it != telephone_bills_map_.end() ? make_optional(it->second) : nullopt;
}


void TelephoneBillManager::Persist() {

}

void TelephoneBillManager::Populate() {

}