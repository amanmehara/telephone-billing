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

#include "bill_service.h"
#include "user_service.h"

class user_options {
public:
    user_options(const bill_service& bill_service, const user_service& user_service)
        : bill_service_(bill_service), user_service_(user_service) {
    }

    void interact();

    void add_user();

    void display_user();

    void display_all_users();

    void remove_user();

private:
    bill_service bill_service_;
    user_service user_service_;
};

#endif // TELBILL_USER_OPTIONS_H_
