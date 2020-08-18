#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

//simple structure that will go into each customer_data past_transactions vector so each node will have their own individual transaction list
struct transactions {
	int transaction_type = 0; // 1 for deposit, 2 for withdrawl
	double transaction_amount = 0;
	int transaction_ID = rand(); // using rand to make sure transactions ID's are unique among customers
	
	transactions(int user_transaction, double user_amount);
	

	








};