#ifndef PRODUCT_HPP
# define PRODUCT_HPP

# include <iostream>
# include <vector>
# include "Review.hpp"

class Product
{
    private:
        std::string             _name;
        std::string             _description;
        unsigned long           _reference;
        float                   _price;
        std::vector<Review*>    _reviews;
        Product();
    public:
        std::string             &getName();
        void                    setName(std::string &name);
        std::string             &getDescription();
        void                    setDescription(std::string &description);
        unsigned long           &getReference();
        void                    setReference(unsigned long &reference);
        float                   &getPrice();
        void                    setPrice(float &price);
        std::vector<Review*>    &getReviews();
        void                    addReview(Review* review);
        Product(std::string &name, std::string &description, unsigned long &reference,
        float &price);
        Product&                operator<<(); //
};

#endif // PRODUCT_HPP
