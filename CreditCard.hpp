#ifndef CREDITCARD_HPP
# define CREDITCARD_HPP

# include "PaymentOption.hpp"
# include <string>

class CreditCard : public PaymentOption
{
    private:
        unsigned long   number;
        std::string     cardholder;
        CreditCard();
    public:
        unsigned long   &getNumber();
        void            setNumber(unsigned long &_number);
        std::string     &getCardholder();
        void            setCardholder(std::string &_cardholder);
        CreditCard(int const &_id, Address* &_billing_address, unsigned long const &_number,
        std::string const &_cardholder);
        std::string show();
};

#endif // CREDITCARD_HPP
