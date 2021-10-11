#include "Manager.hpp"

// Primera entrega
std::vector<User*>  &Manager::getUsers()
{

}

std::vector<Product*>   &Manager::getProducts()
{

}

Manager::Manager()
{

}

Manager::~Manager()
{

}

bool    Manager::login(std::string &_email, std::string &_password)
{

}

bool    Manager::logout()
{

}

bool    Manager::isLogged()
{

}

User*   Manager::getCurrentUser()
{

}

bool    Manager::addUser(std::string &_username, std::string &_email,
std::string &_password)
{

}

bool    Manager::addAdmin(std::string &_username, std::string &_email,
std::string &_password, unsigned long &_worker_id)
{

}

bool    Manager::eraseCurrentUser()
{

}

bool    Manager::editUsername(std::string &_username)
{

}

bool    Manager::editEmail(std::string &_email)
{

}

bool    Manager::editPassword(std::string &_password)
{

}

bool    Manager::addAddress(std::string &_address, std::string &_city,
std::string &_province, unsigned int &_postal_code)
{

}

bool    Manager::addCreditCard(Address* _billing_address,
unsigned long &_number, std::string &_cardholder)
{

}

bool    Manager::addBizum(Address* _billing_address, unsigned int &_number)
{

}

//Segunda entrega
bool    Manager::addProduct(std::string &_name, std::string &_description,
unsigned long &_reference, float &_price)
{

}

std::vector<PublicUserData*>    Manager::showUsers()
{

}

bool    Manager::makeOrder(std::vector<unsigned long> &_products,
int &_delivery_address, int &_payment_option)
{

}

bool    Manager::createReview(unsigned long &_reference, int &_rating,
std::string &_text)
{

}

std::vector<Review*>    Manager::getReviewsByRating(unsigned long &_reference, int &_rating)
{

}

bool    Manager::upvoteReview(unsigned long &_id)
{

}

bool    Manager::downvoteReview(unsigned long &_id)
{

}

bool    Manager::modifyReviewRating(unsigned long &_id, int &_rating)
{

}

bool    Manager::modifyReviewText(unsigned long &_id, std::string &_text)
{

}

bool    Manager::deleteReview(unsigned long &_id)
{

}

//Tercera entrega
void    Manager::saveToFile(std::string fileAddress)
{

}

void    Manager::loadFromFile(std::string fileAddress)
{

}
