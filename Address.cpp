#include "Address.hpp"

Address::Address() {}

int &Address::getId() {return (id);}

void    Address::setId(int &_id) {id = _id;}

std::string &Address::getAddress() {return (address);}

void    Address::setAddress(std::string &_address) {address = _address;}

std::string &Address::getCity() {return (city);}

void        Address::setCity(std::string &_city) {city = _city;}

std::string &Address::getProvince() {return (province);}

void        Address::setProvince(std::string &_province) {province = _province;}

unsigned int &Address::getPostalCode() {return (postal_code);}

void        Address::setPostalCode(unsigned int &_postal_code) {postal_code = _postal_code;}

Address::Address(const int &id, const std::string &address, const std::string &city, const std::string &province,
const unsigned int &postal_code)
{
    this->id = id;
    this->address = address;
    this->city = city;
    this->province = province;
    this->postal_code = postal_code;
}

std::string Address::show()
{
    std::string addressStr;
    addressStr = address + ", " + city + ", " + province + ", " + std::to_string(postal_code);
    return (addressStr);
}
