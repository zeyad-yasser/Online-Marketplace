#include "Customer.h"
#include "Seller.h"
#include "Product.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
vector<Product> ReadProductsFile()
{
	vector<Product>vpd;
	string idd, quntt, sellerIdd, namee, categoryy, pricee, avgRate, rscnt, totRate;
	ifstream search("products.txt",ios::in);

   	while (search >> idd >> namee >> pricee >> categoryy >> quntt >> sellerIdd >> totRate >> rscnt >> avgRate)
	{
		int dd = stoi(idd), qn = stoi(quntt),sli = stoi(sellerIdd), ff= stoi(rscnt);
		float pr = stof(pricee), trate = stof(totRate), vrate = stof(avgRate);
   		Product x = Product(dd, namee, pr, qn, sli, categoryy, trate, ff, vrate);
		vpd.push_back(x);
	}
	search.close();
	return vpd;
}
vector<Customer> readCustomersFile()
{
	vector<Customer>ctr;
	string id, Cname, Caddress, CphoneNumber, Cemail,Cpassword, customerCart,fs;
	ifstream Search("Customers.txt");
	while (Search >> id >> Cname >> Caddress >>CphoneNumber>>Cemail>>Cpassword>>customerCart)
	{
		int Cid = stoi(id);
		Customer cust = Customer (Cid, Cname,Caddress,CphoneNumber, Cemail, Cpassword,customerCart);
		ctr.push_back(cust);
	}
	Search.close();
	return ctr;
}
Customer::Customer(){}
Customer::Customer(int Cid, string Cname, string Caddress, string CphoneNumber, string Cemail, string Cpassword, string customerCart)
{
	this->CustomerId = Cid;
	this->name = Cname;
	this->address = Caddress;
	this->phoneNumber = CphoneNumber;
	this->email = Cemail;
	this->password = Cpassword;
	this->cutomerCart = customerCart;
}

int  Customer:: customerLogin(string Cemail, string Cpassword)
{
	vector<Customer>ctr = readCustomersFile();
	for (int i = 0; i < ctr.size(); i++)
	{
		if (ctr[i].email == Cemail && ctr[i].password == Cpassword)
			return 1;
	}
	return 0;
}

void Customer:: addNewCustomer(int Cid, string Cname, string Caddress, string CphoneNumber, string Cemail , string Cpassword, string customerCart)
{
	ofstream putIn("Customers.txt", ios::app);
	putIn << Cid << ' ' << Cname << ' ' <<Caddress<< ' ' << CphoneNumber <<' '<<Cemail<<' '<<Cpassword<<' '<<customerCart<< '\n';
	putIn.close();
}

void Customer::browseByCategoryOrName(string catORName)
{
	vector<Product>vpd;
	vpd = ReadProductsFile();
	for (int i = 0; i < vpd.size(); i++)
	{
		if (vpd[i].category == catORName || vpd[i].name == catORName)
		{
			vpd[i].info();
		}
	}
}

void Customer::setRate(int id, float inRate)
{
	vector<Product>vpd = ReadProductsFile();
	for (int i = 0; i < vpd.size(); i++)
	{
		if (vpd[i].id == id)
		{
			vpd[i].rTime++;
			vpd[i].totalRates += inRate;
			vpd[i].avgRate = (vpd[i].totalRates / vpd[i].rTime);
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

void Customer::display()
{
	vector<Product>vpd;
	vpd = ReadProductsFile();

	for (int i = 0; i < vpd.size(); i++)
	{
		vpd[i].info();
	}

}

void Customer::dispalyCat()
{
	vector<string>catStr;
	vector<Product>vpd;
	vpd = ReadProductsFile();

	for (int i = 0; i < vpd.size(); i++)
	{
		if (find(catStr.begin(), catStr.end(), vpd[i].category) == catStr.end())
			cout << vpd[i].category << endl;
		catStr.push_back(vpd[i].category);
	}
}
void Customer::displayByRate()
{
	vector<Product>vpd = ReadProductsFile();
    set<pair<float, int>>st;
	for (int i = 0; i < vpd.size(); i++)
	{
		st.insert(make_pair( vpd[i].avgRate,vpd[i].id));
	}
	for (auto it = st.rbegin(); it != st.rend(); it++)
	{
		for (int i = 0; i < vpd.size(); i++)
		{
            if(vpd[i].id==it->second)
			{
				vpd[i].info();
			}
		}
	}
}
Customer::~Customer(void){}
