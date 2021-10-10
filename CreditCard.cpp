#include "CreditCard.hpp"

CreditCard::CreditCard() {}

unsigned long   &CreditCard::getNumber() {return (_number);}

void            CreditCard::setNumber(unsigned long &number) {_number = number;}

std::string     &CreditCard::getCardholder() {return (_cardholder);}

void            CreditCard::setCardholder(std::string &cardholder) {_cardholder = cardholder;}

CreditCard::CreditCard(int id, Address* billing_address, unsigned long number,
std::string cardholder)
{
    _id = id;
    _billing_address = billing_address;
    _number = number;
    _cardholder = cardholder;
}

std::string CreditCard::show()
{
    std::string info;
    info = "\tid " + _id + " - Credit Card:\nBilling address: " + PaymentOption::show() +
    '\t' + _number + " - " + _cardholder;
    return (info);
}
