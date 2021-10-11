#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(){}

PrivateUserData::PrivateUserData(const std::string &_email, const std::string &_password)
{
    email = _email;
    password = _password;
}

std::string &PrivateUserData::getEmail() {return(email);}

void    PrivateUserData::setEmail(std::string &_email) {email = _email;}

std::string &PrivateUserData::getPassWord() {return(password);}

void    PrivateUserData::setPassword(std::string &_password) {password = _password;}

std::vector<Address*>   &PrivateUserData::getAddresses() {return (addresses);}

std::vector<PaymentOption*> &PrivateUserData::getPaymentOptions() {return (payment_options);}

std::vector<Order*> &PrivateUserData::getOrders() {return (orders);}
