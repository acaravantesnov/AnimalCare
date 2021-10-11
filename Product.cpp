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

void    Product::addReview(Review* review) {reviews.push_back(review);}

Product::Product(const std::string &_name, const std::string &_description,const unsigned long &_reference,
const float &_price)
{
    name = _name;
    description = _description;
    reference = _reference;
    price = _price;
}

std::ostream&   Product::operator<<(std::ostream& stream)
{
    stream << reference << " - " << name << '\n' << description << '\n' << price;
    if (reviews.size() == 0)
        return (stream);
    stream << "\n\t-- User reviews --\n";
    for(int i = 0; i < reviews.size(); i++)
        stream << "\t" << reviews[i] << "\n\t----\n";
    return (stream);
}
