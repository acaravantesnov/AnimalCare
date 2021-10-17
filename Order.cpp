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

void    Order::addProduct(unsigned long &_newProduct) {products.push_back(new _newProduct);}

Order::Order(const unsigned long &_reference, const std::vector<unsigned long> &_products,
const int &_delivery_address, const int &_payment_option, const float &_total)
{
    reference = _reference;
    products = _products;
    delivery_address = _delivery_address;
    payment_option = _payment_option;
    total = _total;
    date = time_t(0);
}

Order::Order(const unsigned long &_reference, const int &_delivery_address, const int &_payment_option)
{
    reference = _reference;
    delivery_address = _delivery_address;
    payment_option = _payment_option;
    date = time_t(0);
}
