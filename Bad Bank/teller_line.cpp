#include <iostream>
#include <string>
#include "transaction.h"
#include "customer_node.h"
#include "teller_line.h"
#include <stack>
using namespace std;

stack<customer_data> bank_line::Bank_line;
vector<customer_data> bank_line::bank_database;

void bank_line::add_customer() {
	
	cout << "Before adding customer to line we need some info!" << endl;

	cout << "What is the customer's name? ";
	string uuser_name;
	getline(cin, uuser_name);
	bool in_database = 0; // bool to show if customer already in database or not
	cout << "User name is " << uuser_name << endl;
	for (int i = 0; i < bank_database.size(); i++) {
		if (bank_database.at(i).customer_name == uuser_name) {
			cout << "customer in database already. no more info needed" << endl; // dont want to prompt user to enter balance information we already have in the bank database
			customer_data customer(uuser_name, 0);
			Bank_line.push(customer);
			in_database = 1;
			
		}

	}

	if (in_database == 0) {
		cout << "Enter current balance of customer" << endl;
		double user_balance = 0;
		cin >> user_balance;
		customer_data customer(uuser_name, user_balance);
		Bank_line.push(customer); // adding customer to the bank line
		bank_database.push_back(customer); // adding the customer to the bank database as well since this is there first time at the bank
		cout << "added customer to database!" << endl;
		
	
	}

	/*for (int i = 0; i < bank_database.size(); i++) {
		cout << bank_database.at(i).customer_name<< endl;
		

	}*/
	

	

	

	
	


	
	
	
	


	

}


void bank_line::process_customer() {

	cout << "Processing customer at the end of the line who just arrived! Excellent service!" << endl;
	cout << "Will this be a deposit or a withdrawl?" << endl;
	cout << "0: Deposit" << endl;
	cout << "1: Withdrawl" << endl;

	int cust_tran_type = 9;

	cin >> cust_tran_type;

	//checking to ensure user does not choose and invalid option
	while (cust_tran_type != 1 && cust_tran_type != 0) {
		cout << "invalid choice please try again" << endl;
		cout << "0: Deposit" << endl;
		cout << "1: Withdrawl" << endl;
		cin >> cust_tran_type;
		
	}

	

	//deposits
	if (cust_tran_type == 0) {

		customer_data temp = Bank_line.top();
		string customer_name = temp.customer_name;
		int ccustomer_balance = 0;
		for (int i = 0; i < bank_database.size(); i++) {
			if (bank_database.at(i).customer_name == customer_name) {
				ccustomer_balance = bank_database.at(i).customer_balance;
				
			}
		}
		
		cout << "What is the amount you would like to deposit in " << customer_name << endl;
		double uuser_deposit = 0;
		cin >> uuser_deposit;

		while (uuser_deposit < 0) {
			cout << "deposit cannot be negative. please try again!" << endl;
			cin >> uuser_deposit;
		}
		

		for (int i = 0; i < bank_database.size(); i++) {
			if (bank_database.at(i).customer_name == customer_name) {
				bank_database.at(i).customer_balance = bank_database.at(i).customer_balance + uuser_deposit;
				cout << "New balance for " << customer_name <<  "s" << " account is " << bank_database.at(i).customer_balance << endl;
				transactions temp_tran(1, uuser_deposit);
				bank_database.at(i).past_transactions.push_back(temp_tran); // create a withdrawl transaction and add it to this customer's past transactions


			}
		}

		

		Bank_line.pop(); // customer has been served so we want to remove them from the line

	}

	//withdrawls
	if (cust_tran_type == 1) {
		customer_data temp = Bank_line.top();
		string customer_name = temp.customer_name;
		double ccustomer_balance = 0;
		for (int i = 0; i < bank_database.size(); i++) {
			if (bank_database.at(i).customer_name == customer_name) { //retrieving customer balance from the database
				ccustomer_balance = bank_database.at(i).customer_balance;

			}
		}
		
		cout << "What is the amount you would like to withrawl from " << customer_name << "'s account?" << endl;
		double user_withdrawl = 0;
		cin >> user_withdrawl;
		while (user_withdrawl > ccustomer_balance) { // ensuring user does not withdrawl more money than they have in their account
			cout << "cannot withdrawl more money than in customer balance. Please try again" << endl;
			cout << "Current balance is " << ccustomer_balance << endl;
			cin >> user_withdrawl;
		}

		for (int i = 0; i < bank_database.size(); i++) {
			if (bank_database.at(i).customer_name == customer_name) {
				bank_database.at(i).customer_balance = bank_database.at(i).customer_balance - user_withdrawl; // remove user specified amount of money from customer in line by accessing bank_database
				cout << "New balance for " << customer_name << "'s account it " << bank_database.at(i).customer_balance << endl;
				transactions temp_tran(2, user_withdrawl);
				bank_database.at(i).past_transactions.push_back(temp_tran); // create a deposit transaction and add it to this customer's past transactions


			}
		}

		
		
		

		
		Bank_line.pop(); // customer has been served so remove from line

		

	}

	
	

}



void bank_line::display_next_customer() { // simple function to display next customer to be served and line size after 5 customers have been served

	cout << "Five customers processed!" << endl;
	cout << "The size of the line is " << Bank_line.size() << endl;
	cout << "The size of the bank database is " << bank_database.size() << endl;
	
	if (Bank_line.size() == 0) { // we won't want to try to access elements that don't exists as that will cause issues.
		cout << "No customers currently in line!" << endl;
	}

	else {
		customer_data temp = Bank_line.top();
		string customer_name = temp.customer_name;
		cout << customer_name << "Will be served next!" << endl;
	}

}

void bank_line::get_past_trans() {
	bool found = 0; // bool that we will flag if the customer asked about exists in the database
	cout << "What customer do you want to look up transaction history for? " << endl;
	string customer_name;
	getline(cin, customer_name);
	for (int i = 0; i < bank_database.size(); i++) { // this double for loop just iterates through each customer_node in the bank database until it finds desired customer and ouputs their transaction history
		if (customer_name == bank_database.at(i).customer_name) {
			found = 1; // customer does exists so lets pull up the transaction history for the user
			for (int j = 0; j < bank_database.at(i).past_transactions.size(); j++) {
				cout << "Transaction ID:" << bank_database.at(i).past_transactions.at(j).transaction_ID << endl;
				int transaction_type = bank_database.at(i).past_transactions.at(j).transaction_type;
				if (transaction_type == 1) {
					cout << "Type: Deposit ";
				}
				else {
					cout << "Type: Withdrawl ";
				}

				cout << "Amount $ " << bank_database.at(i).past_transactions.at(j).transaction_amount << endl;
			}

			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
	}

	if (found == 0) {
		cout << "Sorry name not found in database" << endl;
	}
	






}