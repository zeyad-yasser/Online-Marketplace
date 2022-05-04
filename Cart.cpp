#include "product.h"
#include "Cart.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


vector<Product> readProductsFFile()
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
vector<Product> readCartFile()
{
	vector<Product>vpd;
	string idd, quntt, sellerIdd, namee, categoryy, pricee, avgRate, rscnt, totRate;
	ifstream search("Cart.txt", ios::in);
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
Cart::Cart() {}
Cart::Cart(double tp, vector<Product> si)
{
	selecteditems = si;
	totalprice = tp;
}

void Cart::addtocart(string name, int qunt)
{
	vector<Product>vpd = readProductsFFile();

	for (int i = 0; i < vpd.size(); i++)
	{
		if (vpd[i].name == name && vpd[i].qunt >= qunt)
		{
			fstream reIn;
			reIn.open("Cart.txt", ios::app);
			reIn << vpd[i].id << ' ' << vpd[i].name << ' ' << vpd[i].price << ' ' << vpd[i].category << ' ' << qunt << ' ' << vpd[i].sellerId << ' ' << vpd[i].totalRates << ' ' << vpd[i].rTime << ' ' << vpd[i].avgRate << endl;
			reIn.close();
		}

	}
}

void Cart::confirmCart()
{
  //you need to  decrease qunt of products in the system 

}

 void  Cart::deletfromcart(string name,int id)
{	
	 vector<Product>vpd = readCartFile();
	 int sz= vpd.size();
	 for (int i = 0; i < vpd.size(); i++)
	 {
		 if (vpd[i].name == name && vpd[i].id == id)
		 {
			 vpd.erase(vpd.begin() + i);
			 break;
		 }

	 }
     
	 if (vpd.size() == sz)
	 {
		 cout << " Make sure you have entered a vaild name  AND id" << endl;
	 }
	 else
	 {
			 fstream reIn;
			 reIn.open("Cart.txt", ios::out);
		 for (int i = 0; i < vpd.size(); i++)
		 {
		    reIn << vpd[i].id << ' ' << vpd[i].name << ' ' << vpd[i].price << ' ' << vpd[i].category << ' ' <<vpd[i].qunt << ' ' << vpd[i].sellerId << ' ' << vpd[i].totalRates << ' ' << vpd[i].rTime << ' ' << vpd[i].avgRate << endl;
		 }
			 reIn.close();
	 }

 
}
double Cart::totalPrice()
{
	double totPrice = 0;
	vector<Product>vpd = readCartFile();
	for (int i = 0; i < vpd.size(); i++)
	{
		totPrice += ((vpd[i].price) * (vpd[i].qunt));
	}
	return totPrice;
}
void   Cart::displayMyCart()
{
	vector <Product> vpd = readCartFile();
	for (int i = 0; i < vpd.size(); i++)
	{
		cout << vpd[i].qunt<< ' ' << vpd[i].name<<' ' << vpd[i].price << ' ' << vpd[i].category << ' ' <<endl;
    }
}
Cart::~Cart(void) {}
