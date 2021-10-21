#ifndef ORDER_HPP
# define ORDER_HPP

# include <vector>
# include <ctime>

class Order
{
    private:
        unsigned long               reference;
        std::vector<unsigned long>  products;
        std::time_t                 date;
        int                         delivery_address;
        int                         payment_option;
        float                       total;
        Order();
    public:
        unsigned long               &getReference();
        void                        setReference(unsigned long &_reference);
        std::time_t                 &getTime();
        void                        setTime(std::time_t &_date);
        int                         &getDeliveryAddress();
        void                        setDeliveryAddress(int &_delivery_address);
        int                         &getPaymentOption();
        void                        setPaymentOption(int &_payment_option);
        float                       &getTotal();
        void                        setTotal(float &_total);
        std::vector<unsigned long>  &getProducts();
        void                        addProduct(unsigned long &_newProduct);
        Order(unsigned long const &reference, std::vector<unsigned long> const &products,
        int const &delivery_address, int const &payment_option, float const &total);
        Order(unsigned long const &reference, int const &delivery_address, int const &payment_option);
};

#endif // ORDER_HPP
