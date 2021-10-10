#include "Manager.hpp"

// Primera entrega
Manager::Manager()
{

}

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

bool    Manager::login(std::string &email, std::string &password)
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

bool    Manager::addUser(std::string &username, std::string &email,
std::string &password)
{

}

bool    Manager::addAdmin(std::string &username, std::string &email,
std::string &password, unsigned long &worker_id)
{

}

bool    Manager::eraseCurrentUser()
{

}

bool    Manager::editUsername(std::string &username)
{

}

bool    Manager::editEmail(std::string &email)
{

}

bool    Manager::editPassword(std::string &password)
{

}

bool    Manager::addAddress(std::string address, std::string city,
std::string province, unsigned int postal_code)
{

}

bool    Manager::addCreditCard(Address* billing_address,
unsigned long number, std::string cardholder)
{

}

bool    Manager::addBizum(Address* billing_address, unsigned int number)
{

}

//Segunda entrega
bool    Manager::addProduct(std::string name, std::string description,
unsigned long reference, float price)
{

}

std::vector<PublicUserData*>    Manager::showUsers()
{

}

bool    Manager::makeOrder(std::vector<unsigned long> products,
int delivery_address, int payment_option)
{

}

bool    Manager::createReview(unsigned long reference, int rating,
std::string text)
{

}

std::vector<Review*>    Manager::getReviewsByRating(unsigned long reference, int rating)
{

}

bool    Manager::upvoteReview(unsigned long id)
{

}

bool    Manager::downvoteReview(unsigned long id)
{

}

bool    Manager::modifyReviewRating(unsigned long id, int rating)
{

}

bool    Manager::modifyReviewText(unsigned long id, std::string text)
{

}

bool    Manager::deleteReview(unsigned long id)
{

}

//Tercera entrega
void    Manager::saveToFile(std::string fileAddress)
{

}

void    Manager::loadFromFile(std::string fileAddress)
{

}
