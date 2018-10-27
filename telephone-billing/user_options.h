// Copyright 2018 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TELBILL_USER_OPTIONS_H_
#define TELBILL_USER_OPTIONS_H_

#include "telephone_bill_manager.h"
#include "user_manager.h"

using namespace std;

class UserOptions
{

	TelephoneBillManager telephone_bill_manager_;
	UserManager user_manager_;

  public:
	UserOptions(const TelephoneBillManager &telephone_bill_manager, const UserManager &user_manager)
		: telephone_bill_manager_(telephone_bill_manager), user_manager_(user_manager)
	{
	}

	void Interact();

	void AddUser();

	void DisplayUser();

	void DisplayAllUsers();

	void RemoveUser();
};

#endif // TELBILL_USER_OPTIONS_H_