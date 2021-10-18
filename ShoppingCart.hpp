#ifndef SHOPPINGCART_HPP
# define SHOPPINGCART_HPP

# include <vector>

class ShoppingCart
{
    private:
        std::vector<unsigned long>  products;
    public:
        ShoppingCart();
        std::vector<unsigned long>  &getProducts();
        void                        addProduct(unsigned long &ref);
};

#endif // SHOPPINGCART_HPP
