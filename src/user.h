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

#ifndef TELBILL_USER_H_
#define TELBILL_USER_H_

#include <memory>
#include <string>
#include <vector>

#include "bill.h"

namespace telbill {

class user {
  public:
    user(std::string name, std::string phone, std::string city)
        : name_(name), phone_(phone), city_(city), due_(0)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const user& u);

    const std::string& get_phone() const
    {
        return phone_;
    }

    void add_bill(std::shared_ptr<bill> b);

    void remove_bill(std::shared_ptr<bill> b);

    const std::shared_ptr<bill> get_bill(const int& month, const int& year);

    const std::vector<std::shared_ptr<bill>>& get_bills() const
    {
        return bills_;
    }

  private:
    std::string name_;
    std::string phone_;
    std::string city_;
    double due_;
    std::vector<std::shared_ptr<bill>> bills_;
};

} // namespace telbill

#endif // TELBILL_USER_H_
