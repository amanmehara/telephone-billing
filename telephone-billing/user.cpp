#include "user.h"


ostream & operator<<(ostream & os, const User & user) {
	os << "{\"Name\":\"" << user.name_ << "\",\"PhoneNumber\":\"" << user.phone_number_ << "\",\"City:\"" << user.city_ << "\",\"PinCode\":\"" << user.pin_code_ << "\"}";
	return os;
}