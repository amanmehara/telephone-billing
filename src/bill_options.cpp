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

#include "bill_options.h"

#include <iostream>

#include "bill_service.h"

namespace telbill {

void bill_options::interact()
{
    bool loop = true;
    while (loop) {
        std::cout << "Bill Options \n";
        std::cout << "1 -> Add A Bill \n";
        std::cout << "2 -> Display A Bill \n";
        std::cout << "3 -> Display All Bills For A User \n";
        std::cout << "4 -> Display All Bills \n";
        std::cout << "_ -> Back to Home \n";
        char option;
        std::cin >> option;
        switch (option) {
        case '1':
            add_bill();
            break;
        case '2':
            display_bill();
            break;
        case '3':
            display_user_bills();
            break;
        case '4':
            display_all_bills();
            break;
        default:
            loop = false;
            break;
        }
    }
}

void bill_options::add_bill()
{
    std::cout << "Add Bill \n";
    std::cin.ignore();
    std::string phone;
    std::cout << "Phone: ";
    getline(std::cin, phone);
    int month;
    std::cout << "Bill Month: ";
    std::cin >> month;
    int year;
    std::cout << "Bill Year: ";
    std::cin >> year;
    int calls;
    std::cout << "Calls: ";
    std::cin >> calls;
    double data;
    std::cout << "Data: ";
    std::cin >> data;
    int messages;
    std::cout << "Messages: ";
    std::cin >> messages;
    bill_service_->add_bill(phone, month, year, calls, data, messages);
    std::cout << "Bill Added. \n\n";
}

void bill_options::display_bill()
{
    std::cout << "Display Bill \n";
    std::cin.ignore();
    std::string id;
    std::cout << "Id: ";
    getline(std::cin, id);
    auto b = bill_service_->get_bill(id);
    if (b != nullptr) {
        std::cout << *b << "\n\n";
    }
    else {
        std::cout << "Not Found. \n\n";
    }
}

void bill_options::display_user_bills()
{
    std::cout << "User Bills \n";
    std::cin.ignore();
    std::string phone;
    std::cout << "Phone: ";
    getline(std::cin, phone);
    for (const auto& b : bill_service_->get_bills(phone)) {
        std::cout << *b << "\n";
    }
    std::cout << "That's All Folks. \n\n";
}

void bill_options::display_all_bills()
{
    std::cout << "All Bills \n";
    for (const auto& b : bill_service_->get_bills()) {
        std::cout << *b << "\n";
    }
    std::cout << "That's All Folks. \n\n";
}

} // namespace telbill
