#include "user_options.h"

#include <iostream>
#include <stdbool.h>

#include "user.h"
#include "user_manager.h"

using namespace std;

void UserOptions::Interact() {

	bool loop = true;
	while (loop) {

		cout << "User Options \n";
		cout << "1 -> Add A User \n";
		cout << "2 -> Display A User \n";
		cout << "3 -> Display All Users \n";
		cout << "4 -> Remove A User \n";
		cout << "_ -> Back to Home \n";

		int option;
		cin >> option;

		switch (option) {
		case 1:
			AddUser();
			break;
		case 2:
			DisplayUser();
			break;
		case 3:
			DisplayAllUsers();
			break;
		case 4:
			RemoveUser();
			break;
		default:
			loop = false;
			break;
		}

	}

}

void UserOptions::AddUser() {

	cout << "Add User \n";

	cin.ignore();

	string name;
	cout << "Name: ";
	getline(cin, name);
	
	string phone_number;
	cout << "PhoneNumber: ";
	getline(cin, phone_number);
	
	string city;
	cout << "City: ";
	getline(cin, city);
	
	string pin_code;
	cout << "PinCode: ";
	getline(cin, pin_code);

	User user(name, phone_number, city, pin_code);

	user_manager_.AddUser(user);

	cout << "User Added. \n\n";
}

void UserOptions::DisplayUser() {

}

void UserOptions::DisplayAllUsers() {

}

void UserOptions::RemoveUser() {

}