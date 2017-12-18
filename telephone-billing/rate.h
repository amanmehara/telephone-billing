/*

Copyright 2017 Aman Mehara

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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