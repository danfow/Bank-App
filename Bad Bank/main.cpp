/*Colin McNish
CS303
Project 1
4/21/2020
*/
#include <iostream>
#include <string>
#include "teller_line.h"
using namespace std;






int main() {
	srand(time(NULL)); // seed to make the transaction ID's actually random
	bank_line bank; //initilizing bank class to be able to call our bank functions

	int user_choice = 10; // int to control what choice the user wants from main menu. initially 10 so we can enter loop
	int customers_served = 0; //variable to cont how many customers have been processed
	while (user_choice != 0) {  // while loop for main menu
		cout << "Hello welcome to the bank telling app." << endl;
		cout << "0: Quit" << endl;
		cout << "1: Add new customer to line" << endl;
		cout << "2: Process customer who just arrived(how efficient!)" << endl;
		cout << "3: Look up past customer transactions" << endl;
		cin >> user_choice;
		cin.ignore(1, '\n'); // buffer here allows the name collection to work correctly when add_customer is called

		if (user_choice != 0 && user_choice != 1 && user_choice != 2 && user_choice != 3) {
			cout << "Sorry invalid entry, try again!" << endl;
		}

		if (user_choice == 1) {
			bank.add_customer();

		}

		else if (user_choice == 2) {
			if (bank.Bank_line.size() != 0) { // if the bank line is empty we dont want to access null data
				bank.process_customer();
				customers_served += 1;

			}

			if (customers_served == 5) {
				bank.display_next_customer();
				customers_served = 0;

			}

			

			else if (bank.Bank_line.size() == 0){
				cout << "Sorry no customers currently in line, add more before processing" << endl;
			}

		}

		else if (user_choice == 3) {
			bank.get_past_trans();

		}

		




	}

	

	return 0;
}