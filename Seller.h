#pragma once
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
class Seller
{
private:
   int id;
   string name, email,password;
public:
	Seller();
	Seller(int, string, string,string);
	void addNewSeller(int,string,string,string);
	void addProduct(int id, string name, float price, string category, int qunt, int sellerId);
	void deleteProduct(int);
	int  sellerLogin(string, string);
	~Seller();
};

