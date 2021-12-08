#include "interface.h"
#include"user.h"
#include "product.h"
#include "address.h"
#include "review.h"
#include "admin.h"
#include "creditcard.h"
#include "bizum.h"
#include "manager.h"
#include "shoppingcart.h"
#include "order.h"
#include<iostream>
#include<string>
using namespace std;


Interface::Interface(){}

void Interface::clearScreen(){system("clear");}

void Interface::welcome(){
    clearScreen();
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                   WELCOME TO ANIMAL CARE ONLINE STORE!                                               "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Date:     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<flush;
    cout << "Time:     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) <<endl<<endl;
}

void Interface::Header(){
    clearScreen();
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                             ANIMAL CARE ONLINE STORE                                                 "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Date:     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<flush;
    cout << "Time:     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) <<endl<<endl<<endl;
}


void Interface::Menu(){
    int seleccion;
    clearScreen();
    welcome();
    cout<<"Menu:        "<<endl;
    cout<<"   1. Create Account"<<endl;
    cout<<"   2. Login" <<endl;
    cout<<"   3. Logout"<<endl;
    cout<<"   4. Go to personal menu"<<endl;
    cout<<"   5. Exit menu"<<endl<<endl;
    cout<<"What do you want to do? Enter the number of your option: "<<flush;
    cin>>seleccion;
    while((seleccion>5 || seleccion<1) || cin.fail()){
        cin.clear();
        cout<<"Please enter a valid option"<<flush;
        cin>>seleccion;
    }
    if(seleccion == 1){
        clearScreen();
        Header();
        createAccountMenu();
    }else if(seleccion == 2){
        clearScreen();
        amILogged();
        this_thread::sleep_for(g_timespan);
        if(logIn()== true){
            cout<<"You are already logged in as:" <<getCurrentUser() <<endl; //CHECK QUE ESTO LO HAGA BIEN_________________________________________
            this_thread::sleep_for(g_timespan);
            clearScreen();
            Menu();
        }
        if(logIn() == false){
            clearScreen();
            Header();
            logIn();
        }else if(seleccion == 3){
            logout();
            this_thread::sleep_for(g_timespan);
            clearScreen();
            welcome();
            Menu();
        }else if(seleccion == 4 ){
            if(logIn() == true){
                clearScreen();
                if(getCurrentUser()->isAdmin() == true){
                    adminMenu();
                }else{
                    userMenu();
                }
            }else{
                cout<<"You have to be logged in in order to access the personal menu"<<endl;
            }
            Menu();
        }else if(seleccion == 5){
            clearScreen();
            exit(0);
        }
    }
}


void Interface::interf(){
    exitMenu = 0;
    clearScreen();
    welcome();
    if(add_Admin() == true){
        while(exitMenu != 1) Menu();
    }
    else{
        clearScreen();
        Header();
        cout <<"Try again later"<<endl;
        this_thread::sleep_for(g_timespan);
    }
    exit(0);
}  //para poder llamarlo desde el main



void Interface::amILogged(){
    if(add_User() == true){
        if(add_Admin() == true){
            if(getCurrentUser()->isAdmin() == true){
                Admin* admin_current = dynamic_cast<Admin*>(getCurrentUser());  /*BIEN PUESTO???? user[current user] es private the manager aqui no podemos hacerlo*********************************************************************************************************************************************************************************/
                if(logIn() == true){
                    cout<<"Admin with worker ID:  " <<admin_current ->getWorkerID() <<" is logged in right now" <<endl;
                }
            }
        }else if(logIn() == true){
            cout<<getCurrentUser() <<" is logged in right now" <<endl;
        }else cout<<"There is no one logged in right now" <<endl;
    }
    if(add_User() == false && add_Admin() == false && logIn() == false){
        cout<<"No one is logged in because there are no created accounts";
    }
}


bool Interface::logIn(){
    string email, password;
    cout<<"Enter your email: "<<endl;
    cin>>email;
    while(email.string::find("@")>email.string::length()&&email.string::find(".")>email.string::length()){/*leeria bien? que haya un@ y un . para acepatrlo como un email_______@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22________________________________*/
        cin.clear();
        cout<<"Introduce a valid email";
        cin>>email;
    }
    cout<<"Enter your password: " <<endl;
    cin>>password;
    if(login(email,password) == true){
        cout<<"Logged in successfully";
        this_thread::sleep_for(g_timespan);
        adminMenu();
        if(getCurrentUser()->isAdmin() == true){
            clearScreen();
        }else{
            userMenu();
        }
        return(true);
    }
    return(false);
}



void Interface::userHeader(){
    clearScreen();
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                       USER MENU                                                      "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout << "Date:     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<flush;
    cout << "Time:     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) <<endl<<endl;
    cout <<"Username: " <<getCurrentUser()->getUsername()<<endl;
    cout<<"Email: " <<getCurrentUser()->getEmail()<<endl;
    /*SI tiene oRDERS QUE LAS PRINTEE?? O LO DE SHOPPING CART SI LO HACEMOS------------------------------------------------------------------------------------------------------------------*/
}

void Interface::loggedUser(){
    userHeader();
    userMenu();
}

void Interface::adminHeader(){
    clearScreen();
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                       ADMIN MENU                                                      "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout<<"Date:     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<flush;
    cout<<"Time:     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) <<endl<<endl;
    cout <<"Username: " <<getCurrentUser()->getUsername()<<endl;
    Admin* admin_current = dynamic_cast<Admin*>(getCurrentUser()); //COMO ANTES; ESTA BIEN??___________________________________________________________________________________________
    cout<<"Worker ID: " <<admin_current ->getWorkerID()<<endl;
    cout<<"Email: " <<getCurrentUser()->getEmail()<<endl<<endl;
}

void Interface::loggedAdmin(){
    adminHeader();
    adminMenu();
}


void Interface::userMenu(){
    exitUserMenu = 0;
    clearScreen();
    while(exitUserMenu!=1){
        userHeader();
        loggedUser();
        cout<<"1. Make Order"<<flush<<endl;
        cout<<"2. See current orders"<<flush<<endl;
        cout<<"3. See Shopping Cart"<<flush<<endl;
        cout<<"4. Modify own reviews"<<flush<<endl;
        cout<<"5. Delete own reviews"<<flush<<endl<<endl;
        cout<<"6. Change Username"<<flush<<endl;
        cout<<"7. Change Email"<<flush<<endl;
        cout<<"8. Change Password"<<flush<<endl<<endl;
        cout<<"9. Addresses"<<flush<<endl;
        cout<<"10. Payment Options"<<flush<<endl;
        cout<<"11. Logout"<<flush<<endl<<endl;
        cout<<"12. Go to Main Menu"<<flush<<endl;
        cout<<"13. Exit"<<flush<<endl<<endl;
        cout<<"Choose the option you want to do: "<<flush;
        int i;
        cin>>i;
        while(i>14 || i<1|| cin.fail()){
            cin.clear();
            cout<<"Please enter a valid option"<<flush;
            cin>>i;
        }
        if(i == 1){
            clearScreen();
            loggedUser();
            while(exitMakeOrderMenu != 1){
                placeOrderMenu();
            }exitMakeOrderMenu = 0;
        }else if (i == 2){
            clearScreen();
            loggedUser();
            if(getProducts().size()>0){
                cout<<"Your products: "<<endl;
                for(long unsigned int i = 0; i<sizeof(getProducts()); i++){
                    cout<<*getProducts()[i]<<endl;
                }
            }else{
                cout<<"There are no current orders"<<endl;
                clearScreen();
            }
            userMenu();
        }else if(i == 3){//-------------------------------------------------________________________________________________________CON GET CART();

        }else if(i ==4){
            clearScreen();
            loggedUser();
            while(exitEditReviewMenu != 1){
                editReviewMenu();
            }
            exitEditReviewMenu=0;
            userMenu();

        }else if(i ==5){

        }else if(i ==6){

        }else if(i ==7){

        }else if(i ==8){

        }else if(i ==9){

        }else if(i ==10){

        }else if(i ==11){
            clearScreen();
            logout();
            Menu();
        }else if(i ==12){
            clearScreen();
            Menu();
        }else if(i ==13){
            clearScreen();
            exit(0);
        }
    }
}


void Interface::productMenu(){
    clearScreen();
    Header();
    int welldone = 0;
    string text;
    int rating;
    long unsigned long numprod;
    long unsigned long index;
    exitProductMenu = 0;
    while(exitProductMenu != 1){
        cout<<"1. Create Review"<<flush<<endl;
        cout<<"2. Get Reviews by Rating"<<flush<<endl;
        cout<<"3. Modify own reviews"<<flush<<endl;
        cout<<"4. Vote on review"<<flush<<endl;
        cout<<"5. Delete Review"<<flush<<endl;
        cout<<"6. Go to Main Menu"<<flush<<endl;
        cout<<"7. Go to personal Menu" <<flush<<endl;
        cout<<"8. Exit"<<flush<<endl<<endl;
        cout<<"Choose the option you want to do: "<<flush;
        int i;
        cin>>i;
        while(i>8 || i<1 || cin.fail()){
            cin.clear();
            cout<<"Please enter a valid option"<<flush;
            cin>>i;
        }
        if(i == 1){
            clearScreen();
            Header();
            cout<<"";
            if(getCurrentUser()->getOrders().size()>0){
                cout<<"YOUR PRODUCTS: "<<endl<<endl;
                for(long unsigned int j = 0; j<sizeof(getProducts()); j++){
                    index = j+1;
                    cout<<index <<*getProducts()[j]<<endl;
                    cout<<"Choose the product you wish to review by entering the number at its left: "<<flush;
                    cin>>numprod;
                    while(numprod<1 || numprod>index || cin.fail()){
                        cin.clear();
                        cout<<"Please enter a valid option"<<flush;
                        cin>>numprod;
                    }
                }
                cout<<"What will you rate this product, you can give it 1-5 stars"<<flush;
                cin>>rating;
                while(rating<1 || rating>5 || cin.fail()){
                    cin.clear();
                    cout<<"Please enter a valid rating"<<flush;
                    cin>>rating;
                }
                while(rating>1 && rating<5){
                    cout<<"Write your review: "<<endl;
                    std::getline(std::cin >> std::ws, text);
                    for(long unsigned int l; sizeof(getCurrentUser()->getOrders()); l++){
                        for(long unsigned int m; sizeof(getCurrentUser()->getOrders()[l]->getProducts()); m++){
                            if(getCurrentUser()->getOrders()[l]->getProducts()[m] == getProducts()[index-1]->getReference()){//index-1 = j, es el producto del que va a poner una review
                                createReview(getProducts()[index-1]->getReference(), rating, text);
                                welldone = 1;
                            }
                        }
                    }
                }
            }else if (welldone == 0){
                cout<<"Reminder that you can only create a review for products you have"<<endl;
                productMenu();
               }
        }else if(i == 2){
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){
                adminHeader();
            }else{
                userHeader();
            }
            int welldone = 0;
            if(sizeof (getProducts())>0){
                cout<<"YOUR PRODUCTS: "<<endl<<endl;
                for(long unsigned int j = 0; j<sizeof(getProducts()); j++){
                    index = j+1;
                    cout<<index <<*getProducts()[j]<<endl;
                }
                cout<<"REVIEWS: "<<endl<<endl;
                for(long unsigned int k = 0; k<sizeof(getReviewsByRating(getProducts()[index-1]->getReference(),rating)); k++){
                    cout<<"Id: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getID()<<endl;
                    cout<<"Rating: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getRating()<<endl;
                    cout<<"Text: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getText()<<endl;
                    cout<<"Author: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getAuthor()<<endl;
                    cout<<"Votes: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getVotes()<<endl;
                    cout<<"Date: "<<getReviewsByRating(getProducts()[index-1]->getReference(), rating)[k]->getDate()<<endl;
                }
                cout<<"Press 1 to exit into the product menu, press any other key to go back to the main menu";
                int exit;
                cin>>exit;
                if(exit!=1){
                    Menu();
                }else if(exit ==1){
                    productMenu();
                }
            }
        }else if(i == 3){
            clearScreen();
            editReviewMenu();

        }else if(i == 4){
            clearScreen();
            voteReviewMenu();

        }else if(i == 5){
            unsigned long int id;
            int done = 0;
            clearScreen();
            Header();
            cout<<"Introduce the ID of the review you wish to delete: ";
            cin>>id;
            while(cin.fail()){
                cin.clear();
                cout<<"Please enter a valid id number"<<endl;
                cin>>id;
            }
            for(long unsigned int j = 0; j< sizeof(getProducts()); j++){
                for(long unsigned int k = 0; k< sizeof(getProducts()[j]->getReviews()); k++){
                    if(id == getProducts()[j]->getReviews()[j]->getID()){
                        deleteReview(id);
                        cout<<"Review deleted correctly";
                        done = 1;
                    }
                }

            }
            if(done == 0){
                cout<<"There was an issue deleting the review"<<endl;
                productMenu();
            }

        }else if(i == 6){
            clearScreen();
            Menu();
        }else if(i == 7){
            if(logIn() == true){
                clearScreen();
                if(getCurrentUser()->isAdmin() == true){
                    adminMenu();
                }else{
                    userMenu();
                }
            }else{
                cout<<"You have to be logged in in order to access the personal menu"<<endl;
            }
            cout<<"Do you want to log in and enter the personal menu? if so, press 1, if you want to go back to the Product Menu, press any other key";
            int opt;
            cin>> opt;
            if(opt == 1){
                logIn();
                clearScreen();
                if(logIn() == true){
                    clearScreen();
                    if(getCurrentUser()->isAdmin() == true){
                        adminMenu();
                    }else{
                        userMenu();
                    }
                }
            }else if(opt!=1){
                productMenu();
            }
        }else if (i == 8){
            clearScreen();
            exit(0);
        }
    }
}


void Interface::adminMenu(){
    clearScreen();
    loggedAdmin();
    exitAdminMenu = 0;
    string name;
    string description;
    unsigned long reference;
    long unsigned int index;
    int rating = -1;
    float price;
    while(exitAdminMenu != 1){
        loggedAdmin();
        cout<<"1. Add Product"<<flush<<endl;
        cout<<"2. Show users"<<flush<<endl;
        cout<<"3. Save to file"<<flush<<endl;
        cout<<"4. Load from file"<<flush<<endl<<endl;
        cout<<"5. Make Order"<<flush<<endl;
        cout<<"6. Create Review"<<flush<<endl;
        cout<<"7. Modify Review"<<flush<<endl;
        cout<<"8. Delete Review"<<flush<<endl<<endl;
        cout<<"9. Edit Username"<<flush<<endl;
        cout<<"10. Edit Email"<<flush<<endl;
        cout<<"11. Edit Password"<<flush<<endl;
        cout<<"12. Addresses"<<flush<<endl;
        cout<<"13. Payment Options"<<flush<<endl;
        cout<<"14. Go to Main Menu"<<flush<<endl;
        cout<<"15. Logout"<<flush<<endl;
        cout<<"16. Exit"<<flush<<endl<<endl;
        cout<<"Choose the option you want to do: "<<flush;
        int i;
        cin>>i;
        while(i>16 || i<1 || cin.fail()){
            cin.clear();
            cout<<"Please enter a valid option"<<flush;
            cin>>i;
        }
        if(i == 1){

        }else if(i == 2){

        }else if(i == 3){

        }else if(i == 4){

        }else if(i == 5){
            placeOrderMenu();
        }else if(i == 6){

        }else if(i == 7){

        }else if(i == 8){

        }else if(i == 9){

        }else if(i == 10){

        }else if(i == 11){

        }else if(i == 12){

        }else if(i == 13){

        }else if(i == 14){
            logout();
            this_thread::sleep_for(g_timespan);
            Menu();
        }else if(i == 15){
            logout();
            Menu();
        }else if(i ==16){
            clearScreen();
            exit(0);
        }
    }
    Menu();
}


void Interface::createAccountMenu(){
    clearScreen();
    Header();
    cout<<"What do you want to add: [1]Admin         [2]User";
    int seleccion;
    cin >>seleccion;
    while(!cin.good()){/*__________________________________________________________________________________________________________________________________CHECK SI BIEN*/
        cin.clear();
        cout<<"Please enter 1 to create an Admin or 2 to create a User"<<flush;
        cin>>seleccion;
    }
    if(seleccion == 1)add_Admin();
    if(seleccion == 2)add_User();
}


void Interface::orderMenu(int _address, int _payment){
    clearScreen();
    Header();
    long unsigned int prod = 0;
    cout<<"1. Add Product to Cart "<<flush<<endl;
    cout<<"2. Place Order"<<flush<<endl;
    cout<<"3. Go to Main Menu"<<flush<<endl;
    cout<<"4. Go to personal Menu" <<flush<<endl;
    cout<<"5. Exit"<<flush<<endl<<endl;
    cout<<"Choose the option you want to do: "<<flush;
    int i;
    cin>>i;
    while(i>5 || i<1 || cin.fail()){
        cin.clear();
        cout<<"Please enter a valid option"<<flush;
        cin>>i;
    }
    if(i == 1){
        cout<<"Choose the product: ";
        cin>> prod;
        if((getProducts().size()>=1)&&(prod>=1)&&(prod <= getProducts().size())){//si existen productos
            getCurrentUser()->getCart()->addProduct(getProducts()[prod-1]->getReference());
            cout<<"Product added to the shopping cart";
            this_thread::sleep_for(g_timespan);
            if(getCurrentUser()->isAdmin() == true){
                adminMenu();
            }else{
                userMenu();
            }
        }
    }else if(i == 2){
        if(getCurrentUser()->getCart()->getProducts().size()>0){
            makeOrder(getCurrentUser()->getCart()->getProducts(), _address, _payment);
            cout<<"Order placed correctly";
            this_thread::sleep_for(g_timespan);
            if(getCurrentUser()->isAdmin() == true){
                adminMenu();
            }else{
                userMenu();
            }
        }else{
            cout<<"There are no products to buy, add some and try again"<<endl;
            this_thread::sleep_for(g_timespan);
            if(getCurrentUser()->isAdmin() == true){
                adminMenu();
            }else{
                userMenu();
            }
        }
    }else if(i == 3){
        Menu();
    }else if(i == 4){
        if(logIn() == true){
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){
                adminMenu();
            }else{
                userMenu();
            }
        }else{
            cout<<"You have to be logged in in order to access the personal menu"<<endl;
            this_thread::sleep_for(g_timespan);
            Menu();
        }
    }else if (i == 5){
        clearScreen();
        exit(0);
    }
    Menu();
}


bool Interface::add_Admin(){
    clearScreen();
    Header();
    string username, email, password;
    unsigned long worker_id;
    cout<<"Introduce a username: "<<flush;
    cin >>username;
    cout<<"Introduce an email: "<<flush;
    cin >>email;
    while(email.string::find("@")>email.string::length() && email.string::find(".")>email.string::length()){/*COMO PONER ESTO BIEN; PASA LO MISMO EN FILE_______@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22________________________________*/
        cin.clear();
        cout<<"Introduce a valid email";
        cin>>email;
    }
    cout<<"Introduce a password"<<flush;
    cin>>password;
    worker_id = static_cast<unsigned long>(rand());
    all_worker_id.push_back(worker_id);
    if(addAdmin(username,email,password,worker_id) == true){
        cout<<"Admin created correctly"<<endl;
        return(true);
        this_thread::sleep_for(g_timespan);
    }
    return false;
}


bool Interface::add_User(){
    clearScreen();
    Header();
    string username, email, password;
    cout<<"Introduce a username: "<<flush;
    cin >>username;
    cout<<"Introduce an email: "<<flush;
    cin >>email;
    while(email.string::find("@")>email.string::length()){/*COMO PONER ESTO BIEN; PASA LO MISMO EN FILE_______________________________________*/
        cin.clear();
        cout<<"Introduce a valid email";
        cin>>email;
    }
    cout<<"Introduce a password"<<flush;
    cin>>password;
    if(addUser(username, email, password) == true){
        cout<<"User created correctly"<<endl;
        return(true);
        clearScreen();
        Header();
        Menu();
    }else {
        cout<<"There was an issue creating the user";
        add_User();
    }
    return(false);
}


void Interface::editReviewMenu(){
    clearScreen();
    Header();















    Menu();
}

void Interface::voteReviewMenu(){
    clearScreen();
    Header();

}


void Interface::paymentMenu(){
    clearScreen();
    if(getCurrentUser()->isAdmin() == true){//Simplemente el header pero que enseñe la info que corresponda
        adminHeader();
    }else{
        userHeader();
    }
    cout<<endl<<"1. Add Payment Method"<<endl;
    cout<<"2. Go to Main Menu"<<flush<<endl;
    cout<<"3. Go to personal Menu" <<flush<<endl;
    cout<<"4. Exit"<<flush<<endl<<endl;
    cout<<"Choose the option you want to do: "<<flush;
    int seleccion;
    cin>>seleccion;
    while(seleccion>4 || seleccion<1 || cin.fail()){
        cin.clear();
        cout<<"Please enter a valid option"<<flush;
        cin>>seleccion;
    }
    if(seleccion == 1){
        cout<<"You can either enter a [1]credit card or a [2]bizum number, press the corresponding number of what you wish to enter: "<<flush;
        int sel2;
        cin>>sel2;
        while(seleccion>2 || seleccion<1 || cin.fail()){
            cin.clear();
            cout<<"Please enter a valid option"<<flush;
            cin>>seleccion;
        }
        if(sel2 == 1){
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){//Simplemente el header pero que enseñe la info que corresponda
                adminHeader();
            }else{
                userHeader();
            }
            cout<<"CREDIT CARD: "<<endl<<endl;
            cout<<"Number: ";
            long unsigned int ccnumber;
            cin>> ccnumber;
            while(cin.fail()){
                cin.clear();
                cout<<"Please enter a valid option"<<flush;
                cout<<"Number: ";
                cin>>ccnumber;
            }
            cout<<"Cardholder: ";
            string cardholder;
            cin>>cardholder;
            while(cin.fail()){
                cin.clear();
                cout<<"Please enter a valid option"<<flush;
                cout<<"Cardholder: ";
                cin>>cardholder;
            }
            cout<<"Billing Address: ";
            Address* ptr;
            long unsigned int bill_address;
            if(sizeof(getCurrentUser()->getAddresses()) == 0){
                cout<<"There are no addresses created, if you wish to create one, press 1, if you wish to go back to the main menu press 2: ";
                int sel3;
                cin >>sel3;
                while(sel3>2 || sel3<1 || cin.fail()){
                    cin.clear();
                    cout<<"Please enter a valid option"<<flush;
                    cin>>sel3;
                }
                if(sel3 == 1){
                    addressMenu();
                }
                if(sel3 == 2){
                    Menu();
                }
            }else if(sizeof(getCurrentUser()->getAddresses()) > 0){
                cout<<"These are your addresses: "<<endl;
                for(long unsigned int i =0; sizeof(getCurrentUser()->getAddresses());i++){
                    cout<<i+1<<". "<<getCurrentUser()->getAddresses()[i]->show()<<endl;
                }
                cout<<"Select one of the following addresses by introducing the number at the left of the address: "<<flush;
                unsigned long index;
                cin>>index;
                while(cin.fail()||index>sizeof(getCurrentUser()->getAddresses())){
                    cin.clear();
                    cout<<"Please enter a valid option"<<flush;
                    cin>>index;
                }
                if((bill_address<=sizeof(getCurrentUser()->getAddresses()))&&bill_address>0){
                    ptr = getCurrentUser()->getAddresses()[bill_address-1];
                }
                addCreditCard(ptr, ccnumber, cardholder);
            }
        }
        if(sel2 == 2){
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){//Simplemente el header pero que enseñe la info que corresponda
                adminHeader();
            }else{
                userHeader();
            }
            cout<<"BIZUM: "<<endl<<endl;
            cout<<"Billing Address: "<<endl;
            Address* ptr;
            int phonenumber;
            long unsigned int bill_address;
            if(sizeof(getCurrentUser()->getAddresses()) == 0){
                cout<<"There are no addresses created, if you wish to create one, press 1, if you wish to go back to the main menu press 2: ";
                int sel3;
                cin >>sel3;
                while(sel3>2 || sel3<1 || cin.fail()){
                    cin.clear();
                    cout<<"Please enter a valid option"<<flush;
                    cin>>sel3;
                }
                if(sel3 == 1){
                    addressMenu();
                }
                if(sel3 == 2){
                    Menu();
                }
            }else if(sizeof(getCurrentUser()->getAddresses()) > 0){
                cout<<"These are your addresses: "<<endl;
                for(long unsigned int i =0; sizeof(getCurrentUser()->getAddresses());i++){
                    cout<<i+1<<". "<<getCurrentUser()->getAddresses()[i]->show()<<endl;
                }
                cout<<"Select one of the following addresses by introducing the number at the left of the address: "<<flush;
                unsigned long index;
                cin>>index;
                while(cin.fail()||index>sizeof(getCurrentUser()->getAddresses())){
                    cin.clear();
                    cout<<"Please enter a valid option"<<flush;
                    cin>>index;
                }
                if((bill_address<=sizeof(getCurrentUser()->getAddresses()))&&bill_address>0){
                    ptr = getCurrentUser()->getAddresses()[bill_address-1];
                }
                if(bill_address <= sizeof(getCurrentUser()->getAddresses())){
                    cout<<"Phone number: ";

                    cin>>phonenumber;
                    while(cin.fail()){
                        cin.clear();
                        cout<<"Please enter a valid phone number"<<flush;
                        cin>>phonenumber;
                    }
                }
            }
            addBizum(ptr, phonenumber);
        }
    }else if(seleccion == 2){
        clearScreen();
        Menu();
    }else if(seleccion == 3){
        if(getCurrentUser()->isAdmin() == true){//Simplemente el header pero que enseñe la info que corresponda
            adminMenu();
        }else{
            userMenu();
        }
    }else if(seleccion == 4){
        exitPaymentMenu = 1;
    }
    Menu();
}


void Interface::addressMenu(){
    string address, province, city;
    unsigned int postal_code;
    int id;
    clearScreen();
    if(getCurrentUser()->isAdmin() == true){//Simplemente el header pero que enseñe la info que corresponda
        adminHeader();
    }else{
        userHeader();
    }
    cout<<endl<<"1. Add Address"<<endl;
    cout<<"2. View Registered addresses"<<endl;
    cout<<"3. Go to Main Menu"<<flush<<endl;
    cout<<"4. Go to personal Menu" <<flush<<endl;
    cout<<"5. Exit"<<flush<<endl<<endl;
    cout<<"Choose the option you want to do: "<<flush;
    int seleccion;
    cin>>seleccion;
    while(seleccion>5 || seleccion<1 || cin.fail()){
        cin.clear();
        cout<<"Please enter a valid option"<<flush;
        cin>>seleccion;
    }if(seleccion == 1){
        clearScreen();
        if(getCurrentUser()->isAdmin() == true){
            adminHeader();
        }else{
            userHeader();
        }
        cout<<"Address: ";
        getline(cin>>ws,address);
        cout<<endl<<"Postal Code: ";
        cin>>postal_code;
        while(cin.fail()){
            cout<<"Postal codes only include numbers, try again please"<<endl;
            cout<<"Postal Code: ";
            cin>>postal_code;
        }
        cout<<endl<<"City: ";
        getline(cin>>ws,city);
        cout<<endl<<"Province: ";
        getline(cin>>ws,province);
        id = rand();
        getCurrentUser()->getAddresses().push_back(new Address(id, address, city, province, postal_code));
        addressMenu();
    }if(seleccion == 2){
        if(sizeof(getCurrentUser()->getAddresses())>0){
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){
                adminHeader();
            }else{
                userHeader();
            }
            cout<<"YOUR REGISTERED ADDRESSES: "<<endl<<endl;
            for(long unsigned int i=0; i<sizeof(sizeof(getCurrentUser()->getAddresses()));i++){
                cout<<i+1<<". Id: "<<getCurrentUser()->getAddresses()[i]->getId()<<flush<<" Address: "<<getCurrentUser()->getAddresses()[i]->show()<<endl;
            }
        }else{
            clearScreen();
            if(getCurrentUser()->isAdmin() == true){
                adminHeader();
            }else{
                userHeader();
            }
            cout<<endl<<endl;
            cout<<"You have no registered addresses"<<endl;
            this_thread::sleep_for(g_timespan);
            this_thread::sleep_for(g_timespan);
            addressMenu();
        }
    }if(seleccion == 3){
        Menu();

    }if(seleccion == 4){
        if(getCurrentUser()->isAdmin() == true){
            adminMenu();
        }else{
            userMenu();
        }
    }if(seleccion == 5){
        exitAddressMenu = 1;
    }
    Menu();
}


void Interface::placeOrderMenu(){
    clearScreen();
    Header();
    int sel2;
    int seleccion;
    if(getCurrentUser()->getAddresses().size() == 0 || getCurrentUser()->getPaymentOptions().size() ==0){
        cout<<"In order to place your order please add your address and payment information"<<endl;
        cout<<"What information are you missing? Please type in 1 for Address information, 2 for Payment information"<<endl;
        int seleccion;
        while(cin.fail()|| seleccion <1 || seleccion >2){
            cout<<"Please enter a valid option: " ;
            cin>>seleccion;
        }
        if(seleccion == 1){
            clearScreen();
            Header();
            addressMenu();
        }
        if(seleccion == 2){
            clearScreen();
            Header();
            paymentMenu();
        }
    }
    else{
        getCurrentUser()->getCart() = new ShoppingCart();
        cout<<"\tADDRESSES:"<<endl<<endl;
        for(long unsigned int i = 0; i<getCurrentUser()->getAddresses().size();i++){
            cout<<i+1<<". -"<<getCurrentUser()->getAddresses()[i]->show()<<flush;
            cout<<", -ID: " <<getCurrentUser()->getAddresses()[i]->getId()<<endl<<endl;
            cout<<"Which address do you want your order delivered to, enter the corresponding number: ";
            cin>>seleccion;
            while(cin.fail()){
                cout<<"Please enter a valid option: " ;
                cin>>seleccion;
            }
        }
        cout<<"\tPAYMENT OPTIONS:"<<endl<<endl;
        for(long unsigned int j = 0; j<getCurrentUser()->getPaymentOptions().size();j++){
            cout<<j+1<<". -"<<getCurrentUser()->getPaymentOptions()[j]->show()<<endl;
            cout<<"Choose you want to pay for your order: "<<endl;
            cin>>sel2;
            while(cin.fail()){
                cout<<"Please enter a valid option: " ;
                cin>>sel2;
            }
        }
        this_thread::sleep_for(g_timespan);
        clearScreen();
        Header();
        if(getProducts().size()>0){
            cout<<"PRODUCTS: "<<endl<<endl;
            for(long unsigned long i = 0; i<getProducts().size(); i++){
                cout<<getProducts()[i]<<endl;
            }
            this_thread::sleep_for(g_timespan);
            exitPlaceOrderMenu = 0;
            while(exitPlaceOrderMenu != 1){
                int _add = seleccion - 1;
                int _paym = sel2 - 1;
                orderMenu(_add, _paym);
            }
        }else{
            cout<<"No products chosen" <<endl;
            this_thread::sleep_for(g_timespan);
            exitMakeOrderMenu = 1;
        }
    }
    Menu();
}






