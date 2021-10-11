#ifndef PRODUCT_HPP
# define PRODUCT_HPP

# include <iostream>
# include <vector>
# include "Review.hpp"

class Product
{
    private:
        std::string             name;
        std::string             description;
        unsigned long           reference;
        float                   price;
        std::vector<Review*>    reviews;
        Product();
    public:
        std::string             &getName();
        void                    setName(std::string &_name);
        std::string             &getDescription();
        void                    setDescription(std::string &_description);
        unsigned long           &getReference();
        void                    setReference(unsigned long &_reference);
        float                   &getPrice();
        void                    setPrice(float &_price);
        std::vector<Review*>    &getReviews();
        void                    addReview(Review* review);
        Product(std::string const &_name, std::string const &_description, unsigned long const &_reference,
        float const &_price);
        std::ostream&           operator<<(std::ostream& stream); //
};

#endif // PRODUCT_HPP
