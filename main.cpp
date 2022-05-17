#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Seller.h"
#include "Cart.h"
#include "Product.h"
#include "Customer.h"
using namespace std;


void _register(string username,string password)
{
        ofstream putIn("data.txt", ios::app);
    putIn << username << ' ' << password << '\n';
    putIn.close();
       
}


bool isLoggedIn(string email, string password)
{
    string  em, ps;
    bool found = 0;
    ifstream isIn("data.txt");

    while (isIn >> em >> ps)
    {
        if (email == em && password == ps) {
            found = 1;
        }
    }
    isIn.close();
    if (found)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    while (true)
    {

        Seller sel;
        Customer ctr;
        Cart cartt;
        int flagCust = 1, flagSeller = 0;
        system("cls");
        mainn:
        //cout << " Are You a Seller or a Customer ? \n \n 1-Seller.. \n 2-Customer..\n" << endl;
        //int IsSellerLoggedin = 0, isCustomerLoggenin = 0;
        //// Seller or Customer loGin 
        //int x; cin >> x;
        //if (x == 1)
        //{
        //    //11 Seller Reg 
        //    system("cls");
        //    cout << " Do you want to register or login ? \n\n 1-Register \n 2-Login " << endl;
        //    int y; cin >> y;
        //    if (y == 1)
        //    {
        //        string email, pass;
        //        system("cls");
        //        cout << " please enter your E-mail" << endl;
        //        cin >> email;
        //        cout << " please enter your password" << endl;
        //        cin >> pass;
        //        cout << " please enter your ID" << endl;
        //        int id; cin >> id;
        //        cout << " please enter your Name" << endl;
        //        string name; cin >> name;
        //        sel.addNewSeller(id, name, email, pass); //ddddddddddd




        //    }
        //    if (y == 2)
        //    {
        //        // Seller LOgin 
        //        string email, pass;
        //        system("cls");
        //        cout << " please enter your E-mail" << endl;
        //        cin >> email;
        //        cout << " please enter your password" << endl;
        //        cin >> pass;


        //        if (sel.sellerLogin(email, pass))
        //        {
        //            system("cls");
        //            cout << " you loggedin successfully.\n Press any key to continue...." << endl;
        //            flagSeller = 1;
        //            char stop; cin >> stop;
        //        }
        //        else
        //        {
        //            system("cls");
        //            cout << " Invalid UserName or Password " << endl;
        //            char stop; cin >> stop;
        //            goto mainn;
        //            
        //        }
        //    }





        //}
        //else if (x == 2)
        //{

        //    system("cls");
        //    cout << " Do you want to register or login ? \n\n 1-Register \n 2-Login " << endl;
        //    int y; cin >> y;
        //    if (y == 1)
        //    {
        //        system("cls");
        //        string  name, address, phoneNumber, email, password, cutomerCart;
        //        int CustomerId;
        //        cout << "please enter your ID" << endl;
        //        cin >> CustomerId;
        //        cout << "please enter your Name" << endl;
        //        cin >> name;
        //        cout << "please enter your address" << endl;
        //        cin >> address;
        //        cout << "please enter your phone number " << endl;
        //        cin >> phoneNumber;
        //        cout << "please enter your E-mail" << endl;
        //        cin >> email;
        //        cout << "please enter your password" << endl;
        //        cin >> password;
        //        cout << "please enter your customer cart" << endl;
        //        cin >> cutomerCart;
        //        ctr.addNewCustomer(CustomerId,name, address, phoneNumber, email, password, cutomerCart);
        //    }
        //    else if (y == 2)
        //    {
        //        // Customer LOgin 
        //        string email, pass;
        //        system("cls");
        //        cout << " please enter your E-mail" << endl;
        //        cin >> email;
        //        cout << " please enter your password" << endl;
        //        cin >> pass;


        //        if (ctr.customerLogin(email, pass))
        //        {
        //            system("cls");
        //            cout << " you loggedin successfully.\n Press any key to continue...." << endl;
        //            flagCust = 1;
        //            char stop; cin >> stop;
        //        }
        //        else
        //        {
        //            system("cls");
        //            cout << " Invalid UserName or Password " << endl;
        //            char stop; cin >> stop;
        //            goto mainn;
        //        }
        //    }


        //}
    //
    if (flagCust == 1)
    {
        here:
        cout << " 1-Browse By Category....\n 2-Browse By Name.... \n 3-Display by rate... \n 4-back..."<<endl;
        int x; cin >> x;

        if (x == 1)
        {  
            system("cls");
            ctr.dispalyCat();
            cout << " enter the name of choosen category..... "<<endl;
            string  cat; cin >> cat;
            ctr.browseByCategoryOrName(cat);
            cout << " enter the name of choosen Product AND it's Quantity..... " << endl;
            string name;
            int qunt; cin >> name>>qunt;
            cartt.deletAllCart();
            cartt.addtocart(name, qunt);
            cout <<  " If you want to confirm  your Broducts press '1' .... \n Press '2' to delelte Product from your cart.....  \n  Press Any key to Exit .... \n" << endl;
            char choo; cin >> choo;
            if (choo == '1')
            {
                cartt.confirmCart();
                cout<<cartt.totalPrice()<<endl;
                cout << " Press any key to continue....";
                char stop; cin >> stop;
            }
            else if (choo == '2')
            {
                string name; int id;
                cout << " Enter the name of the product do you want to delete AND it's ID ...... \n" << endl;
                cin >> name >> id;
                cartt.deletfromcart(name,id);
                cout << " You deleted your items  successfully...." << endl;
                cout << " Press any key to contiue ...." << endl;
                char stop; cin >> stop;
                
            }
            if (choo)
            {
                goto here;
            }
            char  innn; 
            cout << " press Enter to continue.... "<<endl;
            

            char stop; cin >> stop;

             

        }
        else if (x == 2)
        {
            system("cls");
            ctr.display();
            cout << " enter the name of choosen Product AND it's Quantity..... " << endl;
            string name;
            int qunt; cin >> name >> qunt;
            cartt.deletAllCart();
            cartt.addtocart(name, qunt);
            cout << " If you want to confirm  your Broducts press '1' ....  \n Else Press Any key to continue.... \n" ;
            char choo; cin >> choo;
            if (choo == '1')
            {

                cartt.confirmCart();
                cout << cartt.totalPrice() << endl;
                cout << " Press any key to continue....";
                char stop; cin >> stop;
                
            }
            else if (choo)
            {
                goto here;
            }
            char  innn;
            cout << " press Enter to continue.... " << endl;


         }

        else if (x==3) 
        {

        }
        else if (x == 4)
        {
        }

              
    }
        ///////////////////
    if (flagSeller == 1)
    {

    }
   

    }

}

