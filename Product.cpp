#include "Product.hpp"

Product::Product() {}

std::string &Product::getName() {return (_name);}

void    Product::setName(std::string &name) {_name = name;}

std::string &Product::getDescription() {return (_description);}

void    Product::setDescription(std::string &description) {_description = description;}

unsigned long   &Product::getReference() {return (_reference);}

void    Product::setReference(unsigned long &reference) {_reference = reference;}

float   &Product::getPrice() {return (_price);}

void    Product::setPrice(float &price) {_price = price;}

std::vector<Review*>    &Product::getReviews() {return (_reviews);}

void    Product::addReview(Review* review)
{
    review = new Review;
    //
}

Product::Product(std::string &name, std::string &description, unsigned long &reference,
float &price)
{
    _name = name;
    _description = description;
    _reference = reference;
    _price = price;
}

Product::Product&   operator<<()
{
    //
}
