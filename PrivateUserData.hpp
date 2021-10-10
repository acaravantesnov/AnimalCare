#ifndef PRIVATEUSERDATA_HPP
# define PRIVATEUSERDATA_HPP

# include <iostream>
# include <vector>
# include "Address.hpp"
# include "PaymentOption.hpp"

class PrivateUserData
{
    protected:
        std::string                 _email;
        std::string                 _password;
        std::vector<Address*>       _addresses;
        std::vector<PaymentOption*> _payment_options;
        std::vector<Order*>         _orders;
        PrivateUserData();
        PrivateUserData(std::string email, std::string password);
    public:
        std::string                     &getEmail();
        void                            setEmail(std::string &email);
        std::string                     &getPassWord();
        void                            setPassword(std::string &password);
        std::vector<Address*>           &getAdress();
        std::vector<PaymentOption*>     &getPaymentOption();
        std::vector<Order*>             &getOrder();
};

#endif // PRIVATEUSERDATA_HPP
