#pragma once
#include <iostream>
using namespace std;
class Product
{
public:

	int id,qunt,sellerId,rTime;
	string name, category;
	float price,avgRate,totalRates;
	void infoForCustomer();
	Product(void);
	Product(int, string,float,string, int,int,float);
	Product(int id, string name, float price, int qunt, int sellerId, string category,float,int,float);
	void setId(int);
	void setQunt(int);
	void setSellerId(int);
	void setName(string);
	void setCategory(string);
	void setPrice(float);
	//------------------------------------/
	void info();
	~Product(void);
};

