#ifndef PRIVATEUSERDATA_HPP
# define PRIVATEUSERDATA_HPP

# include <iostream>
# include <vector>
# include "Address.hpp"
# include "PaymentOption.hpp"
# include "Order.hpp"
# include "ShoppingCart.hpp"

class PrivateUserData
{
    protected:
        std::string                 email;
        std::string                 password;
        std::vector<Address*>       addresses;
        std::vector<PaymentOption*> payment_options;
        std::vector<Order*>         orders;
        ShoppingCart*               cart;
        PrivateUserData();
    public:
        PrivateUserData(std::string const &_email, std::string const &_password);
        std::string                     &getEmail();
        void                            setEmail(std::string &_email);
        std::string                     &getPassWord();
        void                            setPassword(std::string &_password);
        std::vector<Address*>           &getAddresses();
        std::vector<PaymentOption*>     &getPaymentOptions();
        std::vector<Order*>             &getOrders();
        ShoppingCart*                   &getCart();
};

#endif // PRIVATEUSERDATA_HPP
