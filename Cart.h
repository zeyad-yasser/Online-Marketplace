#pragma once
//#define Customer _declspec(dllexport)
#include"product.h"
#include "Seller.h"
#include "Customer.h"
#include <iostream>
#include<vector>
using namespace std;
class Cart
{
public:
	double totalprice;
	vector<Product> selecteditems;
	Cart();
	Cart(double tp, vector<Product> si);
	void addtocart( string nm, int qunt); 
	void confirmCart();
	void deletAllCart();
	void deletfromcart(string ,int);
	void displayMyCart();
	double totalPrice();
	~Cart(void);
};