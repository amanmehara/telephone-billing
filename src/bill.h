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

#ifndef TELBILL_BILL_H_
#define TELBILL_BILL_H_

#include <format>
#include <stdexcept>
#include <string>
#include <vector>

#include "rate.h"

namespace telbill {

class bill {
  public:
    bill(std::string phone, int month, int year, int calls, double data, int messages, rate rate)
        : phone_(phone), calls_(calls), data_(data), messages_(messages), rate_(rate)
    {
        if (month < 1 || month > 12) {
            std::invalid_argument("Month outside range.");
        }
        if (year < 0 || year > 9999) {
            std::invalid_argument("Year outside range.");
        }
        id_ = std::format("{:04d}#{:02d}#{}", year, month, phone);
        compute_bill();
    }

    friend std::ostream& operator<<(std::ostream& os, const bill& b);

    void compute_bill();

    const std::string& get_phone() const
    {
        return phone_;
    }

    const int& get_bill_month() const
    {
        return month_;
    }

    const int& get_bill_year() const
    {
        return year_;
    }

    const std::string& get_id() const
    {
        return id_;
    }

  private:
    std::string id_;
    std::string phone_;
    int month_;
    int year_;
    int calls_;
    double data_;
    int messages_;
    double bill_amount_;
    rate rate_;
};

} // namespace telbill

#endif // TELBILL_BILL_H_
