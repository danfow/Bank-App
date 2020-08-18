#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

/*simple node structure that we will place into our bank line*/
struct customer_data{
	customer_data();
	customer_data(string ccustomer_name, double ccustomer_balance);
	string customer_name;
	double customer_balance = 0.0;
	vector<transactions> past_transactions; // this will store a vector of transactions in each node individually so each customer only has access to their tranasction information
	
	

	









};