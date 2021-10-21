#include "Order.hpp"

Order::Order() {}

unsigned long   &Order::getReference() {return (reference);}

void    Order::setReference(unsigned long &_reference) {reference = _reference;}

std::time_t &Order::getTime() {return (date);}

void    Order::setTime(std::time_t &_date) {date = _date;}

int &Order::getDeliveryAddress() {return (delivery_address);}

void    Order::setDeliveryAddress(int &_delivery_address) {delivery_address = _delivery_address;}

int &Order::getPaymentOption() {return (payment_option);}

void    Order::setPaymentOption(int &_payment_option) {payment_option = _payment_option;}

float   &Order::getTotal() {return (total);}

void    Order::setTotal(float &_total) {total = _total;}

std::vector<unsigned long>  &Order::getProducts() {return (products);}

void    Order::addProduct(unsigned long &_newProduct) {getProducts().push_back(_newProduct);}

Order::Order(const unsigned long &reference, const std::vector<unsigned long> &products,
const int &delivery_address, const int &payment_option, const float &total)
{
    this->reference = reference;
    this->products = products;
    this->delivery_address = delivery_address;
    this->payment_option = payment_option;
    this->total = total;
    date = time_t(0);
}

Order::Order(const unsigned long &reference, const int &delivery_address, const int &payment_option)
{
    this->reference = reference;
    this->delivery_address = delivery_address;
    this->payment_option = payment_option;
    date = time_t(0);
}
