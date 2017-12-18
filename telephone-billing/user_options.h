#pragma once

#include "telephone_bill_manager.h"
#include "user_manager.h"

using namespace std;

class UserOptions{

	TelephoneBillManager telephone_bill_manager_;
	UserManager user_manager_;

public:

	UserOptions(const TelephoneBillManager &telephone_bill_manager, const UserManager &user_manager)
		: telephone_bill_manager_(telephone_bill_manager), user_manager_(user_manager)
	{}

	void Interact();

	void AddUser();

	void DisplayUser();

	void DisplayAllUsers();

	void RemoveUser();

};