//#include <bits/stdc++.h>
#include <iostream>
#include<cmath>
#include "Seller.h"
#include "Product.h"
#include "Customer.h"

#include "Cart.h"
#include <vector>
#include <algorithm>
#include "Cart.h"
using namespace std;
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define mod 1000000007
#define MAX 9999999999
#define el '\n'
#define EL '\n'
#define s size()
#define ll long long
#define ld long double
#define f(a, b, c) for (ll a = b; a < c; a++)
#define fr(a, b, c) for (ll a = b; a >= c; a--)
#define pb push_back
#define pf push_front
#define p push
#define pi 3.14159265358979323846
#define reed freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define mk(arr, n, type) type *arr = new type[n];
///////////////////////////////////////////////////
bool sortbysecdesc(const pair<int, int> &a,
                    const pair<int, int> &b)
{
  return a.second > b.second;
}
//////////////////////////////////////////////////
bool sortbysec(const pair<int, int> &a,const pair<int, int> &b)
{
  return (a.second < b.second);
}
///////////////////////////////////////////////////
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
void MOLLTO()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*
    
*/
vector<int>myFunction()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    return v;
}
int main()
{
    //MOLLTO(); 

  
    Seller seller;
    Product pp;
    Customer cs;
    Cart ct;
    cout<<"Total Price : "<<ct.totalPrice()<<endl;
           system("pause");
}
 