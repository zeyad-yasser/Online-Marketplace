#include "Product.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

Product::Product() {}
Product::Product(int id, string name, float price,  int qunt,int sellerId,string category,float totRate,int cnt,float avgRatee ){

	this->id = id;
	this->name = name;
	this->price = price;
	this->category = category;
	this->qunt = qunt;
	this->sellerId = sellerId;
	this->totalRates = totRate;
	this->avgRate = avgRatee;
	this->rTime = cnt;
}
//------------------------------------//

void Product::setId(int id)
{
	this->id = id;
}
void Product::setName(string name)
{
	this->name= name;
}
void Product::setPrice(float price)
{
	this->price = price;
}
void Product::setCategory(string category)
{
	this->category = category;
}
void Product::setQunt(int qunt)
{
	this->qunt = qunt;
}
void Product::setSellerId(int sellerId)
{
	this->sellerId = sellerId;
}

//------------------------------------//


void Product::info ()
{
	cout<<this->id<<" "<< this->name <<" "<<this->price <<" "<<this->qunt<<" "<<this->sellerId<<" "<<this->category<<" "<<this->avgRate<<endl;
}

void Product::infoForCustomer()
{
	cout << this->id << " " << this->name << " " << this->price << " "  <<  " " <<  " Rate " << this->avgRate << endl;
}



Product::~Product(void){}
