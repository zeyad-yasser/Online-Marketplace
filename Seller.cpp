#include "Seller.h"
#include "Product.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

vector<Product> readProductsFile()
{
	vector<Product>vpd;
	string idd, quntt, sellerIdd, namee, categoryy, pricee, avgRate, rscnt, totRate;
	ifstream search("products.txt", ios::in);
	int ii = 0, line = 0;

	while (search >> idd >> namee >> pricee >> categoryy >> quntt >> sellerIdd >> totRate >> rscnt >> avgRate)
	{
		int dd = stoi(idd), qn = stoi(quntt), sli = stoi(sellerIdd), ff = stoi(rscnt);
		float pr = stof(pricee), trate = stof(totRate), vrate = stof(avgRate);
	
		Product x = Product(dd, namee, pr, qn, sli, categoryy, trate, ff, vrate);
		vpd.push_back(x);
	}
	search.close();
	return vpd;
}
vector<Seller> readSellersFile()
{
	vector<Seller>slr;
	string idd, Sname, Smail, password,fs;
	ifstream Search("Sellers.txt");
	while (Search>> idd >> Sname >> Smail>>password)
	{
		int dd = stoi(idd);
		Seller se = Seller(dd, Sname, Smail,password);
		slr.push_back(se);
	}
	Search.close();
	return slr;
}
Seller ::Seller(){}
Seller::Seller(int id, string name, string email,string password)
{
	this->id = id;
	this->name = name;
	this->email = email;
	this->password = password;
}

void Seller::addProduct(int id, string name, float price, string category, int qunt, int sellerId)
{


    	//(int id, string name, float price,  int qunt,int sellerId,string category,float totRate,int cnt,float avgRatee )
	ofstream putIn("products.txt", ios::app);
	
	putIn << id << ' ' << name << ' ' << price << ' ' << category << ' ' << qunt << ' ' << sellerId << ' ' << 0 << ' ' << 0 << ' ' << 0 << endl;
	putIn.close();

}

void Seller::addNewSeller(int id, string Sname, string Smail,string password)
{
    ofstream putIn("Sellers.txt", ios::app);
    putIn << id<< ' ' << Sname<< ' '<<Smail<<' '<<password<<'\n';
    putIn.close();
}

int  Seller::sellerLogin(string Smail, string password)
{
	vector<Seller>slr = readSellersFile();
	for (int i = 0; i < slr.size(); i++)
	{
		if (slr[i].email == Smail && slr[i].password == password) 
					return 1;
		
	}
	return 0;
}

void Seller::deleteProduct(int id)
{
	vector<Product>vpd = readProductsFile();

	for (int i = 0; i < vpd.size(); i++)
	{
		if (vpd[i].id == id)
		{
			vpd.erase(vpd.begin() + i);
			break;
		}
	}

	fstream reIn;
	reIn.open("products.txt", ios::out);
	for (int i = 0; i < vpd.size(); i++)
	{
    		reIn << vpd[i].id << ' ' << vpd[i].name << ' ' << vpd[i].price << ' ' << vpd[i].category << ' ' << vpd[i].qunt << ' ' << vpd[i].sellerId << ' ' << vpd[i].totalRates << ' ' << vpd[i].rTime << ' ' << vpd[i].avgRate << endl;
	}
	reIn.close();
}

Seller::~Seller(void){}
