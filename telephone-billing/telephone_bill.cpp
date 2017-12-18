#include "telephone_bill.h"

void TelephoneBill::ComputeBill() {
	bill_amount_ = incoming_calls_ * rate_.IncomingCallRate() + outgoing_calls_ * rate_.OutgoingCallRate() + data_usage_ * rate_.DataRate() + messages_ * rate_.MessageRate();
}