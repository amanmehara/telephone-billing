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

#include <string>
#include <vector>

class user {
public:
    user(std::string name, std::string phone_number, std::string city)
        : name_(name), phone_number_(phone_number), city_(city) {
    }

    friend std::ostream& operator<<(std::ostream& os, const user& user);

    std::string phone_number() const {
        return phone_number_;
    }

private:
    std::string name_;
    std::string phone_number_;
    double due_;
    std::string city_;
};

#endif // TELBILL_USER_H_
