#ifndef PRIVATEUSERDATA_H
#define PRIVATEUSERDATA_H
#include <iostream>
#include <vector>
#include "address.h"
#include "paymentoption.h"
#include "order.h"
#include "shoppingcart.h"
using namespace std;

class PrivateUserData{
/** ATRIBUTES*/
protected:
    string email;
    string password;
    vector <Address*> addresses;
    vector <PaymentOption*> payment_options;
    vector <Order*> orders;
    ShoppingCart* cart;
/** METHODS*/
    PrivateUserData();
public:
    PrivateUserData(string email, string password);
    string getEmail();
    string getPassword();
    void setEmail(string email);
    void setPassword(string password);
    vector <Address*> getAddresses();
    vector <PaymentOption*> getPaymentOptions();
    vector <Order*> getOrders();
    ShoppingCart* getCart();
};

#endif // PRIVATEUSERDATA_H
