#include "PaymentOption.hpp"

PaymentOption::PaymentOption() {}

int &PaymentOption::getId() {return (id);}

void    PaymentOption::setId(int &_id) {id = _id;}

Address* PaymentOption::getBillingAddress() {return (billing_address);}

void    PaymentOption::setBillingAddress(Address* _billing_address) {billing_address = _billing_address;}

PaymentOption::PaymentOption(const int &id, Address* billing_address)
{
    this->id = id;
    this->billing_address = billing_address;
}

std::string PaymentOption::show()
{
    std::string showstr;
    showstr = billing_address->getAddress();
    return (showstr);
}
