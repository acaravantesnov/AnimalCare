#include "Bizum.hpp"

Bizum::Bizum() {}

unsigned int    &Bizum::getNumber() {return (number);}

void            Bizum::setNumber(unsigned int &_number) {number = _number;}

Bizum::Bizum(const int &id, Address* billing_address, const unsigned int &number)
{
    this->id = id;
    this->billing_address = billing_address;
    this->number = number;
}

std::string Bizum::show()
{
    std::string showstr;
    showstr = "\tid " + std::to_string(id) + " - Bizum Account:\n\tBilling address: " + PaymentOption::show() +
    "\n\t" + std::to_string(number);
    return (showstr);
}
