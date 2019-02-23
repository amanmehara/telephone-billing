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
#include "bill_options.h"
#include "bill_service.h"
#include "user.h"
#include "user_options.h"
#include "user_service.h"

user_service* user_service_;
bill_service* bill_service_;

void initialize(rate rate) {
    user_service_ = new user_service();
    user_service_->populate();

    bill_service_ = new bill_service(rate);
    bill_service_->populate();
}

void shutdown() {
    user_service_->persist();
    delete (user_service_);

    bill_service_->persist();
    delete (bill_service_);
}

int main() {
    rate rate(0, 0, 0);
    initialize(rate);

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
            user_options(*bill_service_, *user_service_).interact();
            break;
        case '2':
            break;
        default:
            loop = false;
            break;
        }
    }

    shutdown();

    return 0;
}
