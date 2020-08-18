#pragma once
#include <iostream>
#include <string>
#include "transaction.h"
#include "customer_node.h"
#include <stack>
#include <string>
using namespace std;

struct bank_line {
	/*These variables must be static to allow the stack and vector to be shared among all instances of customer_data*/
	static stack<customer_data> Bank_line; // this is a stack to ensure last customer to arrive will be served first
	static vector<customer_data> bank_database; //this vector serves as a database so we can keep track of past bank customers and so we can keep track of their transaction history, account balance etc.

	void add_customer(); // add new customer to the stack (bank_line)
	void process_customer(); // deposit or withdrawl from customer account and add reference to transaction in the vector past_transactions.
	void display_next_customer(); /*After every five customers are processed
								  display, the size of the stack and the name of the 
								  customer who will be served  next*/
	void get_past_trans(); //get past transactions of customer from bank database

	
	





};