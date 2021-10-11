#include "Bizum.hpp"

Bizum::Bizum() {}

unsigned int    &Bizum::getNumber() {return (number);}

void            Bizum::setNumber(unsigned int &_number) {number = _number;}

Bizum::Bizum(const int &_id, Address* _billing_address, const unsigned int &_number)
{
    id = _id;
    billing_address = _billing_address;
    number = _number;
}

std::string Bizum::show()
{
    std::string showstr;
    showstr = "\tid " + id + " - Bizum Account\n\tBilling address: " + PaymentOption::show() +
    "\n\t" + number;
    return (showstr);
}
