#include "CreditCard.hpp"

CreditCard::CreditCard() {}

unsigned long   &CreditCard::getNumber() {return (number);}

void            CreditCard::setNumber(unsigned long &_number) {number = _number;}

std::string     &CreditCard::getCardholder() {return (cardholder);}

void            CreditCard::setCardholder(std::string &_cardholder) {cardholder = _cardholder;}

CreditCard::CreditCard(const int &_id, Address* billing_address, const unsigned long &number,
const std::string &cardholder)
{
    this->id = id;
    this->billing_address = billing_address;
    this->number = number;
    this->cardholder = cardholder;
}

std::string CreditCard::show()
{
    std::string showstr;
    showstr = "\tid " + std::to_string(id) + " - Credit Card:\n\tBilling address: " + PaymentOption::show() +
    "\n\t" + std::to_string(number) + " - " + cardholder;
    return (showstr);
}
