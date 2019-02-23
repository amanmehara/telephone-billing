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

#ifndef TELBILL_RATE_H_
#define TELBILL_RATE_H_

class rate {
  public:
    rate(double call_rate, double data_rate, double message_rate)
        : call_rate_(call_rate), data_rate_(data_rate), message_rate_(message_rate) {
    }

    double call_rate() {
        return call_rate_;
    }

    double data_rate() {
        return data_rate_;
    }

    double message_rate() {
        return message_rate_;
    }

  private:
    double call_rate_;
    double data_rate_;
    double message_rate_;
};

#endif // TELBILL_RATE_H_
