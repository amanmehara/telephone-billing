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

#ifndef TELBILL_BILL_SERVICE_H_
#define TELBILL_BILL_SERVICE_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "bill.h"
#include "rate.h"
#include "user_service.h"

namespace telbill {

class bill_service {
  public:
    bill_service(std::shared_ptr<user_service> user_service, rate rate)
        : user_service_(user_service), rate_(rate)
    {
    }

    std::string add_bill(const std::string& phone, int month, int year, int calls, double data,
                         int messages);

    std::shared_ptr<bill> remove_bill(const std::string& id);

    std::shared_ptr<bill> get_bill(const std::string& id) const;

    std::vector<std::shared_ptr<bill>> get_bills(const std::string& phone) const;

    std::vector<std::shared_ptr<bill>> get_bills() const;

  private:
    std::map<std::string, std::shared_ptr<bill>> bills_map_;
    rate rate_;
    std::shared_ptr<user_service> user_service_;
};

} // namespace telbill

#endif // TELBILL_BILL_SERVICE_H_
