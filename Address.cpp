#include "Address.hpp"

Address::Address() {}

int &Address::getId() {return (_id);}

void    Address::setId(int &id) {_id = id;}

std::string &Address::getAddress() {return (_address);}

void    Address::setAddress(std::string &address) {_address = address;}

std::string &Address::getCity() {return (_city);}

void        Address::setCity(std::string &city) {_city = city;}

std::string &Address::getProvince() {return (_province);}

void        Address::setProvince(std::string &province) {_province = province;}

std::string &Address::getPostalCode() {return (_postal_code);}

void        Address::setPostalCode(std::string &postal_code) {_postal_code = postal_code;}

Address::Address(int id, std::string address, std::string city, std::string province,
std::string postal_code)
{
    _id = id;
    _address = address;
    _city = city;
    _province = province;
    _postal_code = postal_code;
}

std::string Address::show()
{
    std::string addressStr;
    addressStr = _address + ' ' + _city + ' ' + _province + ' ' + _postal_code;
    return (addressStr);
}
