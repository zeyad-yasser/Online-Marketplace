#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Seller.h"
#include "Cart.h"
#include "Product.h"
#include "Customer.h"
using namespace std;



int main()
{
    while (true)
    {

        Seller slr;
        Customer ctr;
        Cart cartt;
        int flagCust = 0;
        int flagSeller = 0;
        system("cls");
    mainn:
        system("cls");
        cout << " \n\n---------------------- Welcome to Online marketplace ----------------------\n\n ";
        cout << " Are You a Seller or a Customer ? \n \n 1-Seller.. \n 2-Customer..\n" << endl;

        cout << "\n Choose a Number : ";
        // Seller or Customer loGin
        int m; cin >> m;






        if (m == 1)
        {
            //11 Seller Reg
            system("cls");
        in:
            cout << " Do you want to register or login  as a Seller ? \n\n 1-Register \n 2-Login " << endl;
            cout << "\n Choose a Number : ";
            int y; cin >> y;
            if (y == 1)
            {
                string email, pass;
                system("cls");
                cout << " ------------------------ ( FILL IN THE  FORM ) ------------------------\n";
                cout << " please enter your ID :"; int id; cin >> id;
                cout << " please enter your Name : "; string name; cin >> name;

                cout << " please enter your E-mail to register as a seller :";
                cin >> email;
                cout << " please enter your password :";
                cin >> pass;

                slr.addNewSeller(id, name, email, pass); //ddddddddddd
            }
            if (y == 2)
            {
                // Seller LOgin
                string email, pass;
                system("cls");
                cout << " please enter your E-mail as a Seller :";
                cin >> email;
                cout << " please enter your password :";
                cin >> pass;
                if (slr.sellerLogin(email, pass))
                {
                    system("cls");
                    cout << " You loggedin Successfully .   \n\n Press any key to continue ...." << endl;
                    flagSeller = 1;
                    char stop; cin >> stop;
                }
                else
                {
                    system("cls");
                    cout << endl;
                    cout << " Invalid UserName or Password " << endl;
                    cout << " \nPress any key to continue ....";
                    char stop; cin >> stop;
                    goto mainn;

                }
            }
            else {
                cout << "\n You Entered INVALID number please try again. \n ";
                goto in;

            }


            if (flagSeller == 1)
            {
            sell:
                system("cls");
                cout << " \n ------------------------------- ( WELCOME ) -------------------------------\n\n";
                cout << "\n 1- Add New Product. \n 2- Delete Product. \n 3- Logout." << endl;
                cout << "\n Choose a Number : ";
                char in; cin >> in;
                if (in == '1')
                {
                    char out = '1';
                    while (out != '2') {
                        cout << " Enter Product's ID : "; int id; cin >> id;
                        cout << " Enter Proudct's Name : "; string name; cin >> name;
                        cout << " Enter Proudct's Price : "; float Price; cin >> Price;
                        cout << " Enter Proudct's Category : "; string Cat; cin >> Cat;
                        cout << " Enter Proudct's Quantity : "; int qunt; cin >> qunt;
                        cout << " Enter Proudct's SellerID : "; int sellerId; cin >> sellerId;
                        slr.addProduct(id, name, Price, Cat, qunt, sellerId);
                        cout << "\n product added Successfully. \n ";

                    labb:
                        cout << "\n\n 1- To continue 2- if you done .... ";
                        cin >> out;

                        if (out != '2' && out != '1')
                        {
                            cout << "\n You Entered INVALID number please try again. aaaa \n ";
                            goto labb;


                        }
                    }
                    if (out == '2')
                    {
                        goto sell;
                    }




                }
                else if (in == '2')
                {
                    cout << " Enter ID of the Product : "; int DLTid; cin >> DLTid;
                    slr.deleteProduct(DLTid);
                    cout << " Product Deleted  Successfully : \n";

                    goto sell;

                }
                else if (in == '3')
                {
                    cout << "\n You loggedout Successfully .\n ";
                    goto mainn;

                }


                else {
                    cout << "\n You Entered INVALID number please try again .\n ";

                    goto sell;
                }

            }



        }







        else if (m == 2)
        {




            system("cls");
        inn:
            cout << " Do you want to register or login as a Customer ? \n\n 1-Register \n 2-Login " << endl;
            cout << "\n Choose a Number .... ";
            int y; cin >> y;
            if (y == 1)
            {
                cout << " ------------------------ ( FILL IN THE  FORM ) ------------------------\n";
                string email, pass, address, phoneNum;
                system("cls");
                cout << " Please enter your ID :"; int id; cin >> id; cout << endl;
                cout << " Please enter your Name : "; string name; cin >> name; cout << endl;
                cout << " Please enter your Address : "; cin >> address; cout << endl;
                cout << " Please enter your Phone number : "; cin >> phoneNum; cout << endl;
                cout << " Please enter your E-mail to register as a customer :"; cin >> email; cout << endl;
                cout << " Please enter your Password :"; cin >> pass; cout << endl;
                ctr.addNewCustomer(id, name, address, phoneNum, email, pass, "CustCart"); //ddddddddddd
            }
            if (y == 2)
            {
                //Customer Login
                string email, pass;
                system("cls");
                cout << " Please enter your E-mail as a Customer : "; cin >> email; cout << endl;
                cout << " Please enter your Password : "; cin >> pass; cout << endl;

                if (ctr.customerLogin(email, pass))
                {
                    system("cls");
                    cout << " You loggedin successfully.\n\n Press any key to continue ...." << endl;
                    flagCust = 1;
                    char stop; cin >> stop;
                }
                else
                {
                    system("cls");
                    cout << " Invalid UserName or Password." << endl;
                    cout << " \nPress any key to continue ....";
                    char stop; cin >> stop;
                    goto mainn;

                }


            }

            else {
                cout << " \n  You Entered INVALID number please try again .\n ";
                goto inn;
            }



        CancelMybuy:
            cartt.deletAllCart();
            if (flagCust == 1)
            {
            KeepBrowsing:
                system("cls");
            ui:
                cout << "\n";
                cout << " \n ------------------------------- ( Wellcome ) -------------------------------\n\n";
                cout << " 1- Browse By Category....\n 2- Browse By Name.... \n 3- Display by rate... \n 4- Logout ..." << endl;
                cout << "\n Choose a Number : ";
                int x; cin >> x;
                //1-Browse By Category
                if (x == 1)
                {
                    system("cls");
                    cout << "\n";
                    cout << "\n --------------------- ( Choose a Category ) --------------------- \n";
                    ctr.dispalyCat();
                    cout << "Enter the name of choosen category : ";
                    string  cat; cin >> cat;
                    cout << endl;
                    system("cls");
                    cout << "\n ------------------------ ( Your are in \" " << cat << " \" Category ) ------------------------\n\n" << endl;
                    ctr.browseByCategoryOrName(cat);
                    cout << "\n--------------------------------------------------";
                    cout << "\n\n  Enter Product's Name & Quantity....\n \n --------------------------------------------------\n \n ";
                    char out = '1';
                    while (out != '2') {
                        string name;
                        int qunt;
                        cout << " Enter Product's Name : "; cin >> name; cout << endl;
                        cout << " Enter Product's Quantity : "; cin >> qunt; cout << endl;
                        cartt.addtocart(name, qunt);
                        char rt;
                    rate:
                        cout << " 1- Set Rate to this Product \n 2- Skip Rating \n "; cin >> rt;
                        if (rt == '1')
                        {
                            cout << "\n--------------------------------------------------";
                            int CRid; float Crate;
                            cout << endl;
                            cout << " Please enter the id of the product you want to rate : "; cin >> CRid;
                            cout << endl;
                            cout << " Your rate is : "; cin >> Crate;
                            ctr.setRate(CRid, Crate);

                            cout << "\n You have added a rate successfully Press any key to countinue..."; char stop; cin >> stop;
                        }
                        else if (rt == '2')

                        {
                            goto skipRating;
                        }
                        else {

                            cout << "Please Enter a right number..... \n\n";
                            cout << " Press any key to continue\n";
                            goto  rate;
                        }
                    skipRating:
                        cout << " \n1- To continue  2-if you done  ";
                        cin >> out;
                        if (out != '1' && out != '2')
                        {
                            cout << " Please enter a right number ....\n\n";
                            cout << " Press any key to continue\n\n";
                            char stop; cin >> stop;
                            goto skipRating;
                        }
                        cout << "\n \n --------------------------------------------------\n \n ";
                        cout << endl << endl;
                    }

                confirm:
                    system("cls");
                    cout << " Your Cart is : \n" << endl;
                    cartt.displayMyCart();
                    cout << "--------------------------------------------" << endl;
                zw:
                    cout << "\n \n  1- Confirm  your Products .... \n  2- Delete Product from your Cart ....  \n  3- Keep Browsing .... \n  4- Cancel your Purchase .... \n" << endl;
                    cout << "\n Choose a Number .... ";
                    char choo; cin >> choo;
                    if (choo == '1')
                    {
                        system("cls");
                        cartt.confirmCart();
                        cartt.displayMyCart();
                        cout << "-------------------------------------\n" << endl;
                        cout << " Your Total Price Is : "; cout << cartt.totalPrice() << " $" << endl;
                        cout << " \nPress any key to continue....";
                        char stop; cin >> stop;
                    }
                    else if (choo == '2')
                    {
                        string name; int id;
                        system("cls ");
                        cout << " Your Cart is : ....\n\n" << endl;
                        cartt.displayMyCart();
                        cout << "Enter the name of the product you want to delete AND it's ID ...... \n" << endl;
                        cin >> name >> id;
                        cartt.deletfromcart(name, id);
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
                    else if (choo == '4')
                    {
                        cout << "canceled Successfully.\n ";
                        goto CancelMybuy;
                    }

                    else {
                        cout << "\n You Entered INVALID number please try again kkkk \n";
                        goto zw;
                    }

                }
                //2- Browse By Name

                else if (x == 2)
                {
                    system("cls");
                    cout << "\n";
                    ctr.display();
                    cout << "\n\n  Enter Product's Name & Quantity \n \n --------------------------------------------------\n \n ";
                    char out = '1';
                    while (out != '2') {
                        string name;
                        int qunt;
                        cout << " Enter Product's Name : "; cin >> name; cout << endl;
                        cout << " Enter Product's Quantity : "; cin >> qunt; cout << endl;
                        cartt.addtocart(name, qunt);
                        char rt;
                    ratee:
                        cout << " 1- Set Rate to this Product \n 2- Skip Rating \n "; cin >> rt;
                        if (rt == '1')
                        {
                            cout << "\n--------------------------------------------------";
                            int CRid; float Crate;
                            cout << endl;
                            cout << " Please enter the id of the product you want to rate : "; cin >> CRid;
                            cout << endl;
                            cout << " Your rate is : "; cin >> Crate;
                            ctr.setRate(CRid, Crate);

                            cout << "\n You have added a rate successfully Press any key to countinue..."; char stop; cin >> stop;
                        }
                        else if (rt == '2')

                        {
                            goto skipRatingg;
                        }
                        else {

                            cout << "Please Enter a right number..... \n\n";
                            cout << " Press any key to continue\n";
                            goto  ratee;
                        }
                    skipRatingg:
                        cout << " \n1- To continue  2-if you done : ";
                        cin >> out;
                        if (out != '1' && out != '2')
                        {
                            cout << " Please enter a right number ....\n\n";
                            cout << " Press any key to continue\n\n";
                            char stop; cin >> stop;
                            goto skipRatingg;
                        }
                        cout << "\n \n --------------------------------------------------\n \n ";
                        cout << endl << endl;
                    }

                confirmProducts:
                    system("cls");
                    cout << " Your Cart is : \n" << endl;
                    cartt.displayMyCart();
                    cout << "--------------------------------------------" << endl;
                zw1:
                    cout << "\n \n  1- Confirm  your Products .... \n  2- Delelte Product from your cart ....  \n  3- Keep Browsing .... \n  4- Cancel your Purchase .... \n" << endl;
                    cout << "\n Choose a Number .... ";
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
                        cout << " Your Cart is : \n\n" << endl;
                        cartt.displayMyCart();
                        cout << " Enter the name of the product you want to delete AND it's ID : " << endl;
                        cout << " Enter Product's Name : "; cin >> name;
                        cout << " Enter Product's ID : "; cin >> id;
                        cartt.deletfromcart(name, id);

                        cout << " You deleted your items  successfully Now Your cart is : " << endl;
                        cartt.displayMyCart();
                        cout << " Press any key to contiue ...." << endl;
                        char stop; cin >> stop;
                        goto confirmProducts;

                    }
                    else if (choo == '3')
                    {
                        goto KeepBrowsing;
                    }
                    else if (choo == '4')
                    {
                        cout << "canceled Successfully.\n ";
                        goto CancelMybuy;
                    }

                    else {
                        cout << "\n You Entered INVALID number please try again kkkk \n";
                        goto zw1;
                    }
                    cout << " Press Enter to continue.... " << endl;
                    char stop; cin >> stop;
                }
                //3- Display by rate

                else if (x == 3)
                {  system("cls");
                    cout << "\n";
                    ctr.displayByRate();
                    cout << "\n\n  Enter Product's Name &  Quantity \n \n --------------------------------------------------\n \n ";
                    char out = '1';
                    while (out != '2') {
                        string name;
                        int qunt;
                        cout << " Enter Product's Name : "; cin >> name; cout << endl;
                        cout << " Enter Product's Quantity : "; cin >> qunt; cout << endl;
                        cartt.addtocart(name, qunt);
                        char rt;
                    rateee:
                        cout << " 1- Set Rate to this Product \n 2- Skip Rating \n "; cin >> rt;
                        if (rt == '1')
                        {
                            cout << "\n--------------------------------------------------";
                            int CRid; float Crate;
                            cout << endl;
                            cout << " Please enter the id of the product you want to rate ... "; cin >> CRid;
                            cout << endl;
                            cout << " Your rate is ... "; cin >> Crate;
                            ctr.setRate(CRid, Crate);

                            cout << "\n You have added a rate successfully Press any key to countinue..."; char stop; cin >> stop;
                        }
                        else if (rt == '2')

                        {
                            goto skipRatinggg;
                        }
                        else {

                            cout << "Please Enter a right number \n\n";
                            cout << " Press any key to continue...\n";
                            goto  rateee;
                        }
                    skipRatinggg:
                        cout << " \n1- To continue  : \n 2-if you done :  ";
                        cin >> out;
                        if (out != '1' && out != '2')
                        {
                            cout << " Please enter a right number ....\n\n";
                            cout << " Press any key to continue...\n\n";
                            char stop; cin >> stop;
                            goto skipRatinggg;
                        }
                        cout << "\n \n --------------------------------------------------\n \n ";
                        cout << endl << endl;
                    }
                confirmRateProducts:
                    system("cls");
                    cout << " Your Cart is : \n" << endl;
                    cartt.displayMyCart();
                    cout << "--------------------------------------------" << endl;
                zw2:
                    cout << "\n \n  1- Confirm  your Products .... \n  2- Delelte Product from your cart ....  \n  3- Browsing .... \n  4- Cancel your Purchase .... \n" << endl;
                    cout << "\n Choose a Number  ";
                    char choo; cin >> choo;
                    if (choo == '1')
                    {    system("cls");
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
                        // system("cls");
                        cout << " Your Cart is : \n\n" << endl;
                        cartt.displayMyCart();
                        cout << "Enter the name of the product you want to delete AND it's ID ...... \n" << endl;
                        cin >> name >> id;
                        cartt.deletfromcart(name, id);
                        cout << " You deleted your items  successfully Now Your cart is ....." << endl;
                        cartt.displayMyCart();
                        cout << " Press any key to contiue ...." << endl;
                        char stop; cin >> stop;
                        goto confirmRateProducts;
                    }
                    else if (choo == '3')
                    {
                        goto KeepBrowsing;
                    }
                    else if (choo == '4')
                    {
                        cout << "canceled Successfully.\n ";
                        goto CancelMybuy;
                    }

                    else {
                        cout << "\n You Entered INVALID number please try again kkkk \n";
                        goto zw2;
                    }
                    //// char  innn;
                    //cout << " Press Enter to continue.... " << endl;
                    //char stop; cin >> stop;

                    ////4-logout


                }
                else if (x == 4) {

                    cout << "\n You loggedout Successfully.\n ";
                    goto mainn;

                }



                else {
                    cout << "\n You Entered INVALID number please try again \n";
                    goto ui;
                }
            }



        }
        else {
            cout << "\n You Entered INVALID number please try again \n";
            goto  mainn;
        }
    }
}
