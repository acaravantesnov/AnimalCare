#ifndef BIZUM_HPP
# define BIZUM_HPP

# include "PaymentOption.hpp"

class Bizum : public PaymentOption
{
    private:
        unsigned int    _number;
        Bizum();
    public:
        unsigned int    &getNumber();
        void            setNumber(unsigned int number);
        Bizum(int id, Address* billing_address, unsigned int number);
};

#endif // BIZUM_HPP
