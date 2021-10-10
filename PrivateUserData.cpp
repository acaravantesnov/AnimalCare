#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(){}

PrivateUserData::PrivateUserData(std::string email, std::string password)
{
    _email = email;
    _password = password;
}

std::string &PrivateUserData::getEmail() {return(_email);}

void    PrivateUserData::setEmail(std::string &email) {_email = email;}

std::string &PrivateUserData::getPassWord() {return(_password);}

void    PrivateUserData::setPassword(std::string &password) {_password = password;}

std::vector<Address*>           &getAdress();
std::vector<PaymentOption*>     &getPaymentOption();
std::vector<Order*>             &getOrder();
