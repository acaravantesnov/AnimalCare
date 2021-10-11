#ifndef PAYMENTOPTION_HPP
# define PAYMENTOPTION_HPP

# include "Address.hpp"
# include <string>

class PaymentOption
{
    protected:
        int         id;
        Address*    billing_address;
        PaymentOption();
    public:
        int                     &getId();
        void                    setId(int &_id);
        Address*                getBillingAddress();
        void                    setBillingAddress(Address* _billing_address);
        PaymentOption(int const &_id, Address* _billing_address);
        virtual std::string     show() = 0;
};

#endif // PAYMENTOPTION_HPP
