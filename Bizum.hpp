#ifndef BIZUM_HPP
# define BIZUM_HPP

# include "PaymentOption.hpp"

class Bizum : public PaymentOption
{
    private:
        unsigned int    number;
        Bizum();
    public:
        unsigned int    &getNumber();
        void            setNumber(unsigned int &_number);
        Bizum(int const &id, Address* billing_address, unsigned int const &number);
        std::string     show();
};

#endif // BIZUM_HPP
