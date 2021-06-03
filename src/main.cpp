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
#include <memory>

#include "bill_options.h"
#include "bill_service.h"
#include "rate.h"
#include "user_options.h"
#include "user_service.h"

int main()
{
    using namespace telbill;
    rate rate(1, 0.2, 2);
    auto user_service_ = std::make_shared<user_service>(user_service());
    auto bill_service_ = std::make_shared<bill_service>(bill_service(user_service_, rate));
    auto user_options_ = std::make_shared<user_options>(user_options(user_service_));
    auto bill_options_ = std::make_shared<bill_options>(bill_options(bill_service_));
    bool loop = true;
    while (loop) {
        std::cout << "Telephone Billing \n";
        std::cout << "1 -> User \n";
        std::cout << "2 -> Bill \n";
        std::cout << "_ -> Exit \n";
        char option;
        std::cin >> option;
        switch (option) {
        case '1':
            user_options_->interact();
            break;
        case '2':
            bill_options_->interact();
            break;
        default:
            loop = false;
            break;
        }
    }

    return 0;
}
