#pragma once
#include "Product.h"
#include "Seller.h"
#include <iostream>
#include <string>
using namespace std;
class Customer
{
public:
	int CustomerId;
	string name, address, phoneNumber, email, cutomerCart,password;

	Customer();
	Customer(int, string, string, string, string, string,string);
	void addNewCustomer(int, string, string, string, string, string, string);
	int  customerLogin(string, string);
	void setRate(int, float);
    void browseByCategoryOrName(string);
	void dispalyCat();
	void display();

	~Customer(void);

};

