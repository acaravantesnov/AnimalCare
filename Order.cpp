#include "Order.hpp"

Order::Order() {}

unsigned long   &Order::getReference() {return (_reference);}

void    Order::setReference(unsigned long &reference) {_reference = reference;}

std::time_t &Order::getTime() {return (_date);}

void    Order::setTime(std::time_t &date) {_date = date;}

int &Order::getDeliveryAddress() {return (_delivery_address);}

void    Order::setDeliveryAddress(int &delivery_address) {_delivery_address = delivery_address;}

int &Order::getPaymentOption() {return (_payment_option);}

void    Order::setPaymentOption(int &payment_option) {_payment_option = payment_option;}

float   &Order::getTotal() {return (_total);}

void    Order::setTotal(float &total) {_total = total;}

std::vector<unsigned long>  &Order::getProducts() {return (_products);}

void    Order::addProduct(unsigned long &newProduct) {}

Order::Order(unsigned long &reference, std::vector<unsigned long> &products,
int &delivery_address, int &payment_option, float &total)
{
    _reference = reference;
    _products = products;
    _delivery_address = delivery_address;
    _payment_option = payment_option;
    _total = total;
    _date = time_t(0);
}

Order::Order(unsigned long &reference, int &delivery_address, int &payment_option)
{
    _reference = reference;
    _delivery_address = delivery_address;
    _payment_option = payment_option;
    _date = time_t(0);
}
