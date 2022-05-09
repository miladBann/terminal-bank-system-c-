#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>

char response32;

int main() {

	int count = 1;

	std::map <std::string, int> acc1 = {
		{"user id", 212595250},
		{"pin", 1111},
		{"balance", 2000},
		{"acc_num", count}
	};

	std::map <std::string, int> acc2 = {
		{"user id", 362548963},
		{"pin", 2222},
		{"balance", 1000},
		{"acc_num", count += 1}
	};

	//making the current account whitch is a map public
	std::map <std::string, int> crr_acc;

	std::vector <std::map <std::string, int>> accounts = { acc1, acc2 };

	std::cout << "please type your id:   ";
	int id;
	std::cin >> id;

	std::cout << "please type your pin:   ";
	int pin;
	std::cin >> pin;



	//lambda function
	auto main_menu = []() {
		std::cout << "Welcome, please choose a service: \n" << "0 create account   " << "1 delete account   " << "2 account info" << std::endl;
		std::cout << "3 deposite money   " << "4 withdraw money   " << "5 transfer money" << "\n \n" << std::endl;
	};

	auto main_app = [&]() {

		bool end = false;

		while (end == false) {

			int response1;
			std::cin >> response1;

			if (response1 == 0) {
				std::system("cls");

				std::cout << "you chose to create an account. \n" << std::endl;

				int new_id;
				int new_pin;
				int new_balance{ 0 };

				std::cout << "please type the new id:   ";
				std::cin >> new_id;

				std::cout << "please type a pin:   ";
				std::cin >> new_pin;

				count += 1;

				std::map <std::string, int> new_acc = {
					{"user id", new_id},
					{"pin", new_pin},
					{"balance", new_balance},
					{"acc_num", count}
				};

				accounts.push_back(new_acc);

				std::cout << " \naccount created successfuly! this is your account info: \n" << std::endl;

				for (auto item : new_acc) {
					std::cout << item.first << " - " << item.second << std::endl;
				}

				// after this we need to ask the user if he wants to exit or return to the menu 
				
				std::cout << "\nwant onther service? y or n: ";
				std::cin >> response32;

				if (response32 == 'n') {
					std::system("cls");
					std::cout << "thanks for choosing us :)" << std::endl;
					end = true;
				}
				else if (response32 == 'y') {
					std::system("cls");
					main_menu();
				}

			}
			else if (response1 == 1) {
				std::system("cls");
				std::cout << "you chose to delete an account." << std::endl;

				int id_to_delete;
				std::cout << "\nplease type the id of the account you want to delete:  ";
				std::cin >> id_to_delete;

				int pin_to_delete;
				std::cout << "please type the pin of the account you want to delete:  ";
				std::cin >> pin_to_delete;

				bool found = false;
				for (auto acc : accounts) {
					if (acc["user id"] == id_to_delete && acc["pin"] == pin_to_delete) {
						found = true;
						acc["user id"] = 0;
						acc["pin"] = 0;
						acc["balance"] = 0;
						std::cout << "\naccount deleted successfully" << std::endl;

						std::cout << "\nwant onther service? y or n: ";
						std::cin >> response32;

						if (response32 == 'n') {
							std::system("cls");
							std::cout << "thanks for choosing us :)" << std::endl;
							end = true;
						}
						else if (response32 == 'y') {
							std::system("cls");
							main_menu();
						}

						break;
					}	
				}
				if (found == false) {
					std::system("cls");
					std::cout << "no such account was found!" << std::endl;
					end = true;
				}
			}
			else if (response1 == 2) {
				std::system("cls");
				std::cout << "you chose to view the current account info" << std::endl;

				for (auto acc : accounts) {
					if (acc["user id"] == id && acc["pin"] == pin) {
						std::cout << "\nyour id is: " << id << std::endl;
						std::cout << "your pin is: " << pin << std::endl;
						std::cout << "your balance is: " << acc["balance"] << std::endl;
					}
				}

				std::cout << "\nwant onther service? y or n: ";
				std::cin >> response32;

				if (response32 == 'n') {
					std::system("cls");
					std::cout << "thanks for choosing us :)" << std::endl;
					end = true;
				}
				else if (response32 == 'y') {
					std::system("cls");
					main_menu();
				}
			}
			else if (response1 == 3) {
				std::system("cls");
				std::cout << "you chose to deposit money to your account." << std::endl;

				std::cout << "\nplease insert the amount of money you want to deposit:   ";
				int amount;
				std::cin >> amount;

				crr_acc["balance"] += amount;
				
				std::cout << "\nprocessing..." << std::endl;
				std::cout << "your account balance is now: " << crr_acc["balance"] << std::endl;

				std::cout << "\nwant onther service? y or n: ";
				std::cin >> response32;

				if (response32 == 'n') {
					std::system("cls");
					std::cout << "thanks for choosing us :)" << std::endl;
					end = true;
				}
				else if (response32 == 'y') {
					std::system("cls");
					main_menu();
				}
						
			}
			else if (response1 == 4) {
				std::system("cls");
				std::cout << "you chose to withdraw money." << std::endl;

				std::cout << "\nplease insert the amount of money to withdraw:   ";
				int amount;
				std::cin >> amount;

				crr_acc["balance"] -= amount;

				std::cout << "\nprocessing..." << std::endl;
				std::cout << "your account balance is now: "<< crr_acc["balance"] << std::endl;

				std::cout << "\nwant onther service? y or n: ";
				std::cin >> response32;

				if (response32 == 'n') {
					std::system("cls");
					std::cout << "thanks for choosing us :)" << std::endl;
					end = true;
				}
				else if (response32 == 'y') {
					std::system("cls");
					main_menu();
				}
			}
			else if (response1 == 5) {
				std::system("cls");
				std::cout << "you chose to transfer money." << std::endl;

				int acc_num, acc_id, amount;

				std::cout << "\nplease insert the target account number:   ";
				std::cin >> acc_num;

				std::cout << "please insert the target account id:   ";
				std::cin >> acc_id;

				std::cout << "please insert the amount to transfer:   ";
				std::cin >> amount;

				for (auto acc : accounts) {
					if (acc["user id"] == acc_id && acc["acc_num"] == acc_num) {
						auto target_acc = acc;

						crr_acc["balance"] -= amount;
						target_acc["balance"] += amount;

						std::cout << "\nprocessing..." << std::endl;
						std::cout << "your account balance now is: " << crr_acc["balance"] << std::endl;
						std::cout << "target account balance now is: " << target_acc["balance"] << std::endl;

						std::cout << "\nwant onther service? y or n: ";
						std::cin >> response32;

						if (response32 == 'n') {
							std::system("cls");
							std::cout << "thanks for choosing us :)" << std::endl;
							end = true;
						}
						else if (response32 == 'y') {
							std::system("cls");
							main_menu();
						}

						break;
					}
				}

			}
		}
		
	};

	

	bool ended1 = false;
	for (auto account : accounts) {
		if (ended1 == true) {
			break;
		}
		for (auto info : account) {
			crr_acc = account;
			if (account["user id"] == id && account["pin"] == pin) {
				std::system("cls");
				ended1 = true;
				main_menu();
				main_app();
				break;
			}
			else
			{
				std::system("cls");
				std::cout << "wrong credentials, please try again." << std::endl;
				ended1 = true;
				break;
			}
		}
	}

	return 0;
}
	