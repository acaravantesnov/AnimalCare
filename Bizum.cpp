#include "Bizum.hpp"

Bizum::Bizum() {}

unsigned int    &Bizum::getNumber() {return (number);}

void            Bizum::setNumber(unsigned int &_number) {number = _number;}

Bizum(const int &_id, Address* _billing_address, const unsigned int &_number);
