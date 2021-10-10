#ifndef ORDER_HPP
# define ORDER_HPP

# include <vector>
# include <ctime>

class Order
{
    private:
        unsigned long               _reference;
        std::vector<unsigned long>  _products;
        std::time_t                 _date; //= std::time(0)
        int                         _delivery_address;
        int                         _payment_option;
        float                       _total;
        Order();
    public:
        unsigned long               &getReference();
        void                        setReference(unsigned long &reference);
        std::time_t                 &getTime();
        void                        setTime(std::time_t &date);
        int                         &getDeliveryAddress();
        void                        setDeliveryAddress(int &delivery_address);
        int                         &getPaymentOption();
        void                        setPaymentOption(int &payment_option);
        float                       &getTotal();
        void                        setTotal(float &total);
        std::vector<unsigned long>  &getProducts();
        void                        addProduct(unsigned long &newProduct);
        Order(unsigned long &reference, std::vector<unsigned long> &products,
        int &delivery_address, int &payment_option, float &total);
        Order(unsigned long &reference, int &delivery_address, int &payment_option);
};

#endif // ORDER_HPP
