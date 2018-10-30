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

#include <iostream>

#include "bill.h"
#include "bill_manager.h"
#include "bill_options.h"
#include "user.h"
#include "user_manager.h"
#include "user_options.h"

UserManager *user_manager_;
BillManager *bill_manager_;

void initialize(Rate rate)
{
	user_manager_ = new UserManager();
	user_manager_->Populate();

	bill_manager_ = new BillManager(rate);
	bill_manager_->Populate();
}

void shutdown()
{
	user_manager_->Persist();
	delete (user_manager_);

	bill_manager_->Persist();
	delete (bill_manager_);
}

int main()
{
	Rate rate(0, 0, 0);
	initialize(rate);

	bool loop = true;
	while (loop)
	{
		std::cout << "Telephone Billing \n";
		std::cout << "1 -> User \n";
		std::cout << "2 -> Bill \n";
		std::cout << "_ -> Exit \n";

		int option;
		std::cin >> option;

		switch (option)
		{
		case 1:
			UserOptions(*bill_manager_, *user_manager_).Interact();
			break;
		case 2:
			break;
		default:
			loop = false;
			break;
		}
	}

	shutdown();

	return 0;
}