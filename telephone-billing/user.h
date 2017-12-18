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

#include <string>
#include <vector>

using namespace std;

class User {

	string name_;
	string phone_number_;
	double due_;
	string city_;
	string pin_code_;

public:
	
	User(string name, string phone_number, string city, string pin_code)
		: name_(name), phone_number_(phone_number), city_(city), pin_code_(pin_code)
	{}

	friend ostream& operator<<(ostream& os, const User &user);

	string PhoneNumber() {
		return phone_number_;
	}

};