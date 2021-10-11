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

std::string &Address::getPostalCode() {return (postal_code);}

void        Address::setPostalCode(std::string &_postal_code) {postal_code = _postal_code;}

Address::Address(const int &_id, const std::string &_address, const std::string &_city, const std::string &_province,
const std::string &_postal_code)
{
    id = _id;
    address = _address;
    city = _city;
    province = _province;
    postal_code = _postal_code;
}

std::string Address::show()
{
    std::string addressStr;
    addressStr = address + ' ' + city + ' ' + province + ' ' + postal_code;
    return (addressStr);
}
