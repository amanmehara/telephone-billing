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