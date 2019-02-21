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

#include "user_options.h"

#include <iostream>
#include <optional>

#include "user.h"
#include "user_service.h"

void user_options::interact() {
    bool loop = true;
    while (loop) {
        std::cout << "User Options \n";
        std::cout << "1 -> Add A User \n";
        std::cout << "2 -> Display A User \n";
        std::cout << "3 -> Display All Users \n";
        std::cout << "4 -> Remove A User \n";
        std::cout << "_ -> Back to Home \n";

        char option;
        std::cin >> option;

        switch (option) {
        case '1':
            add_user();
            break;
        case '2':
            display_user();
            break;
        case '3':
            display_all_users();
            break;
        case '4':
            remove_user();
            break;
        default:
            loop = false;
            break;
        }
    }
}

void user_options::add_user() {

    std::cout << "Add User \n";

    std::cin.ignore();

    std::string name;
    std::cout << "Name: ";
    getline(std::cin, name);

    std::string phone_number;
    std::cout << "PhoneNumber: ";
    getline(std::cin, phone_number);

    std::string city;
    std::cout << "City: ";
    getline(std::cin, city);

    user user(name, phone_number, city);

    user_service_.add_user(user);

    std::cout << "User Added. \n\n";
}

void user_options::display_user() {
    std::cout << "Display User \n";

    std::cin.ignore();

    std::string phone_number;
    std::cout << "PhoneNumber: ";
    getline(std::cin, phone_number);

    std::optional<user> optional_user = user_service_.get_user(phone_number);

    if (optional_user.has_value()) {
        user user = optional_user.value();
        std::cout << user << "\n\n";
    } else {
        std::cout << "Not Found. \n\n";
    }
}

void user_options::display_all_users() {
    std::cout << "All Users \n";

    std::map<std::string, user> users_map = user_service_.all_users();

    for (std::map<std::string, user>::iterator it = users_map.begin(); it != users_map.end(); it++) {
        std::cout << it->second << "\n";
    }

    std::cout << "That's All Folks. \n\n";
}

void user_options::remove_user() {
    std::cout << "Remove User \n";

    std::cin.ignore();

    std::string phone_number;
    std::cout << "PhoneNumber: ";
    getline(std::cin, phone_number);

    std::optional<user> optional_user = user_service_.remove_user(phone_number);

    if (optional_user.has_value()) {
        user user = optional_user.value();
        std::cout << "Deleted User: " << user << "\n\n";
    } else {
        std::cout << "Not Found. \n\n";
    }
}