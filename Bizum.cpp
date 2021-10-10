#include "Bizum.hpp"

Bizum::Bizum() {}

unsigned int    &Bizum::getNumber() {return (_number);}

void            Bizum::setNumber(unsigned int number) {_number = number;}

Bizum(int id, Address* billing_address, unsigned int number);
