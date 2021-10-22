#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart() {}

std::vector<unsigned long>  &ShoppingCart::getProducts() {return (products);}

void    ShoppingCart::addProduct(unsigned long &ref) {products.push_back(ref);}
