#include "privateuserdata.h"
#include <iostream>
#include <vector>
#include "address.h"
#include "paymentoption.h"
#include "order.h"
using namespace std;

PrivateUserData::PrivateUserData(){
    email = "Empty";
    password = "Empty";
}

PrivateUserData::PrivateUserData(string email, string password){
    this->email = email;
    this->password = password;
}

string PrivateUserData::getEmail(){
    return email;
}

string PrivateUserData::getPassword(){
    return password;
}

void PrivateUserData::setEmail(string email){
    this->email = email;
}

void PrivateUserData::setPassword(string password){
    this->password = password;
}

vector <Address*> PrivateUserData::getAddresses(){
    return addresses;
}

vector <PaymentOption*> PrivateUserData::getPaymentOptions(){
    return payment_options;
}

vector <Order*> PrivateUserData::getOrders(){
    return orders;
}

ShoppingCart* PrivateUserData::getCart(){
    return cart;
}
