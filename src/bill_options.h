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

#ifndef TELBILL_BILL_OPTIONS_H_
#define TELBILL_BILL_OPTIONS_H_

#include "bill_service.h"

#include <memory>

namespace telbill {

class bill_options {
  public:
    bill_options(std::shared_ptr<bill_service> bill_service) : bill_service_(bill_service) {}

    void interact();

    void add_bill();

    void display_bill();

    void display_user_bills();

    void display_all_bills();

  private:
    std::shared_ptr<bill_service> bill_service_;
};

} // namespace telbill

#endif // TELBILL_BILL_OPTIONS_H_
