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







           //
        CancelMybuy:
    cartt.deletAllCart();
    if (flagCust == 1)
    {
     KeepBrowsing:
        system("cls");
        cout << "\n";
        cout << " 1- Browse By Category....\n 2- Browse By Name.... \n 3- Display by rate... \n 4- Logout ..."<<endl;
        int x; cin >> x;

        if (x == 1)
        {
            system("cls");
            cout << "\n";
            ctr.dispalyCat();
            cout << "Enter the name of choosen category..... "<<endl;
            string  cat; cin >> cat;
            system("cls");
            cout << " Your are in \" "<<cat<<" \" Category .... \n\n" << endl;
            ctr.browseByCategoryOrName(cat);
            cout << "\n\nEnter the name of choosen Product AND it's Quantity..... \n  " << endl;
            char out = '1';
            while (out != '0') {
                string name;
                int qunt; cin >> name >> qunt;
                cartt.addtocart(name, qunt);
                cout << " If you you want to add more products press '1' , If you done Press '0' .....";
                cin >> out;
            }

            confirm:
            system("cls");
            cout << " Your Cart is : ....\n" << endl;
            cartt.displayMyCart();
            cout << "--------------------------------------------" << endl;
            cout <<  "\n \n  1- Confirm  your Broducts .... \n  2- Delelte Product from your cart ....  \n  3- Browsing .... \n  4- Cancel your buy .... \n" << endl;
            cout << " Choose a number  " ;
            char choo; cin >> choo;
            if (choo == '1')
            {
                system("cls");
                cartt.confirmCart();
                cartt.displayMyCart();
                cout << "-------------------------------------\n" << endl;
                cout << " Your Total Price Is : "; cout << cartt.totalPrice() << " $"<<endl;
                cout << " \nPress any key to continue....";
                char stop; cin >> stop;
            }
            else if (choo == '2')
            {
                string name; int id;
                system("cls ");
                cout << " Your Cart is : ....\n\n" << endl;
                cartt.displayMyCart();
                cout << "Enter the name of the product do you want to delete AND it's ID ...... \n" << endl;
                cin >> name >> id;
                cartt.deletfromcart(name,id);
                cout << " You deleted your items  successfully Now Your cart is ....." << endl;
                cartt.displayMyCart();
                cout << " Press any key to contiue ...." << endl;
                char stop; cin >> stop;
                goto confirm;

            }
            else if (choo == '3')
            {
                goto KeepBrowsing;
            }
            else
            {
                goto CancelMybuy;
            }
            char  innn;
            cout << " Press Enter to continue.... "<<endl;
            char stop; cin >> stop;
        }


        else if (x == 2)
        {
            system("cls");
            cout << "\n";
            ctr.display();
            cout << "\n\nEnter the Name ..... of choosen Product AND it's Quantity..... \n \n " ;
            char out = '1';
            while (out != '0') {
                string name;
                int qunt; cin >> name >> qunt;
                cartt.addtocart(name, qunt);
                cout << " 1- to countinue 2- if you done .... ";
                cin >> out;
            }

            confirmProducts:
            system("cls");
            cout << " Your Cart is : ....\n" << endl;
            cartt.displayMyCart();
            cout << "--------------------------------------------" << endl;
            cout << "\n \n  1- Confirm  your Broducts .... \n  2- Delelte Product from your cart ....  \n  3- Browsing .... \n  4- Cancel your buy .... \n" << endl;
            cout << " Choose a number  ";
            char choo; cin >> choo;
            if (choo == '1')
            {
                system("cls");
                cartt.confirmCart();
                cartt.displayMyCart();
                cout << "-------------------------------------\n" << endl;
                cout << " Your Total Price Is : "; cout << cartt.totalPrice() << "$" << endl;
                cout << " \nPress any key to continue....";
                char stop; cin >> stop;
            }
            else if (choo == '2')
            {
                string name; int id;
                system("cls ");
                cout << " Your Cart is : ....\n\n" << endl;
                cartt.displayMyCart();
                cout << "Enter the name of the product do you want to delete AND it's ID ...... \n" << endl;
                cin >> name >> id;
                cartt.deletfromcart(name, id);
                cout << " You deleted your items  successfully Now Your cart is ....." << endl;
                cartt.displayMyCart();
                cout << " Press any key to contiue ...." << endl;
                char stop; cin >> stop;
                goto confirmProducts;

            }
            else if (choo == '3')
            {
                goto KeepBrowsing;
            }
            else
            {
                goto CancelMybuy;
            }
            char  innn;
            cout << " Press Enter to continue.... " << endl;
            char stop; cin >> stop;
        }


        else if (x==3)
        {
        system("cls");
        cout << "\n";
        ctr.displayByRate();
        cout << "\n\nEnter the Name ..... of choosen Product AND it's Quantity..... \n \n ";
        char out = '1';
        while (out != '0') {
            string name;
            int qunt; cin >> name >> qunt;
            cartt.addtocart(name, qunt);
            cout << " 1- to continue 2- if you done .... ";
            cin >> out;
        }

        confirmRateProducts:
        system("cls");
        cout << " Your Cart is : ....\n" << endl;
        cartt.displayMyCart();
        cout << "--------------------------------------------" << endl;
        cout << "\n \n  1- Confirm  your Broducts .... \n  2- Delelte Product from your cart ....  \n  3- Browsing .... \n  4- Cancel your buy .... \n" << endl;
        cout << " Choose a number  ";
        char choo; cin >> choo;
        if (choo == '1')
        {
            system("cls");
            cartt.confirmCart();
            cartt.displayMyCart();
            cout << "-------------------------------------\n" << endl;
            cout << " Your Total Price Is : "; cout << cartt.totalPrice() << "$" << endl;
            cout << " \nPress any key to continue....";
            char stop; cin >> stop;
        }
        else if (choo == '2')
        {
            string name; int id;
            system("cls ");
            cout << " Your Cart is : ....\n\n" << endl;
            cartt.displayMyCart();
            cout << "Enter the name of the product do you want to delete AND it's ID ...... \n" << endl;
            cin >> name >> id;
            cartt.deletfromcart(name, id);
            cout << " You deleted your items  successfully Now Your cart is ....." << endl;
            cartt.displayMyCart();
            cout << " Press any key to continue ...." << endl;
            char stop; cin >> stop;
            goto confirmRateProducts;

        }
        else if (choo == '3')
        {
            goto KeepBrowsing;
        }
        else
        {
            goto CancelMybuy;
        }
        char  innn;
        cout << " Press Enter to continue.... " << endl;
        char stop; cin >> stop;
        }
        else if (x == 4)
        {
        goto mainn;
        }


    }
        ///////////////////
    if (flagSeller == 1)
    {

    }


    }

}
