#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "customer_node.h"
using namespace std;

customer_data::customer_data(string ccustomer_name, double ccustomer_balance) {
	customer_name = ccustomer_name;
	customer_balance = ccustomer_balance;
	
}