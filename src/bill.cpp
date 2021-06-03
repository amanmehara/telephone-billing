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

#include "bill.h"

#include <format>
#include <ostream>

namespace telbill {

std::ostream& operator<<(std::ostream& os, const bill& b)
{
    os << std::format(
        "{{'id': '{}', 'calls': '{}', 'data': '{}', 'messages': '{}', 'amount': '{}'}}", b.id_,
        b.calls_, b.data_, b.messages_, b.bill_amount_);
    return os;
}

void bill::compute_bill()
{
    bill_amount_ =
        calls_ * rate_.call_rate() + data_ * rate_.data_rate() + messages_ * rate_.message_rate();
}

} // namespace telbill
