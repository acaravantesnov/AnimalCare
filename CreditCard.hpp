#ifndef CREDITCARD_HPP
# define CREDITCARD_HPP

# include "PaymentOption.hpp"
# include <string>

class CreditCard : public PaymentOption
{
    private:
        unsigned long   _number;
        std::string     _cardholder;
        CreditCard();
    public:
        unsigned long   &getNumber();
        void            setNumber(unsigned long &number);
        std::string     &getCardholder();
        void            setCardholder(std::string &cardholder);
        CreditCard(int id, Address* billing_address, unsigned long number,
        std::string cardholder);
        std::string show();
};

#endif // CREDITCARD_HPP
