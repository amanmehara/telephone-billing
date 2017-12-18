#pragma once

class Rate {

	double incoming_call_rate_;
	double outgoing_call_rate_;
	double data_rate_;
	double message_rate_;

public:

	Rate(double incoming_call_rate, double outgoing_call_rate, double data_rate, double message_rate)
		: incoming_call_rate_(incoming_call_rate), outgoing_call_rate_(outgoing_call_rate), data_rate_(data_rate), message_rate_(message_rate)
	{}

	double IncomingCallRate() {
		return incoming_call_rate_;
	}

	double OutgoingCallRate() {
		return outgoing_call_rate_;
	}

	double DataRate() {
		return data_rate_;
	}

	double MessageRate() {
		return message_rate_;
	}

};