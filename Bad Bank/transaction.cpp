#include <iostream>
#include <string>
#include <vector>
#include "customer_node.h"
#include "transaction.h"
#include <stack>
using namespace std;



transactions::transactions(int user_transaction, double user_amount) {
	transaction_type = user_transaction;
	transaction_amount = user_amount;
	transaction_ID = rand(); // each transaction ID should be unique 


}