#include "Product.hpp"

Product::Product() {}

std::string &Product::getName() {return (name);}

void    Product::setName(std::string &_name) {name = _name;}

std::string &Product::getDescription() {return (description);}

void    Product::setDescription(std::string &_description) {description = _description;}

unsigned long   &Product::getReference() {return (reference);}

void    Product::setReference(unsigned long &_reference) {reference = _reference;}

float   &Product::getPrice() {return (price);}

void    Product::setPrice(float &_price) {price = _price;}

std::vector<Review*>    &Product::getReviews() {return (reviews);}

void    Product::addReview(Review* review)
{
    review = new Review;
    //
}

Product::Product(const std::string &_name, const std::string &_description,const unsigned long &_reference,
const float &_price)
{
    name = _name;
    description = _description;
    reference = _reference;
    price = _price;
}

Product::Product&   operator<<()
{
    //
}
