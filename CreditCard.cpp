#include "CreditCard.hpp"

CreditCard::CreditCard() {}

unsigned long   &CreditCard::getNumber() {return (number);}

void            CreditCard::setNumber(unsigned long &_number) {number = _number;}

std::string     &CreditCard::getCardholder() {return (cardholder);}

void            CreditCard::setCardholder(std::string &_cardholder) {cardholder = _cardholder;}

CreditCard::CreditCard(const int &_id, Address* _billing_address, const unsigned long &_number,
const std::string &_cardholder)
{
    id = _id;
    billing_address = _billing_address;
    number = _number;
    cardholder = _cardholder;
}

std::string CreditCard::show()
{
    std::string showstr;
    showstr = "\tid " + id + " - Credit Card:\nBilling address: " + PaymentOption::show() +
    '\t' + number + " - " + cardholder;
    return (info);
}
