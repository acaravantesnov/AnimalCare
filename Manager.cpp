#include "Manager.hpp"

// Primera entrega
std::vector<User*>  &Manager::getUsers() {return (users);}

std::vector<Product*>   &Manager::getProducts() {return (products);}

Manager::Manager()
{
    current_user = -1;
}

Manager::~Manager(){}

bool    Manager::login(std::string &_email, std::string &_password)
{
    if (isLogged() == true)
        return (false);
    for(int i = 0; i < users.size(); i++)
    {
        if ((users[i]->getEmail() == _email) && (users[i]->getPassWord() == _password))
        {
            current_user = i;
            return (true);
        }
    }
    return (false);
}

bool    Manager::logout()
{
    if (isLogged() == false)
        return (false);
    current_user = -1;
    return (true);
}

bool    Manager::isLogged()
{
    if (current_user != -1)
        return (true);
    return (false);
}

User*   Manager::getCurrentUser()
{
    if (current_user != -1)
        return (users[current_user]);
    return (nullptr);
}

bool    Manager::addUser(std::string &_username, std::string &_email,
std::string &_password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if ((users[i]->getUsername() == _username) || (users[i]->getEmail() == _email))
            return (false);
    }
    users.push_back(new User(_username, _email, _password));
    return (true);
}

bool    Manager::addAdmin(std::string &_username, std::string &_email,
std::string &_password, unsigned long &_worker_id)
{
    for (int i = 0; i < users.size(); i++)
    {
        if ((users[i]->getUsername() == _username) || (users[i]->getEmail() == _email))
            return (false);
    }
    users.push_back(new Admin(_username, _email, _password, _worker_id));
    return (true);
}

bool    Manager::eraseCurrentUser()
{
    if (isLogged() == true)
    {
        delete users[current_user];
        return (true);
    }
    return (false);
}

bool    Manager::editUsername(std::string &_username)
{
    if (isLogged() == true)
    {
        users[current_user]->setUsername(_username);
        return (true);
    }
    return (false);
}

bool    Manager::editEmail(std::string &_email)
{
    if (isLogged() == true)
    {
        users[current_user]->setEmail(_email);
        return (true);
    }
    return (false);
}

bool    Manager::editPassword(std::string &_password)
{
    if (isLogged() == true)
    {
        users[current_user]->setPassword(_password);
        return (true);
    }
    return (false);
}

bool    Manager::addAddress(std::string &_address, std::string &_city,
std::string &_province, unsigned int &_postal_code)
{
    if (isLogged() == true)
    {
        users[current_user]->getAddresses().push_back(new Address(users[current_user]->getAddresses().size(), _address, _city, _province, _postal_code));
        return (true);
    }
    return (false);
}

bool    Manager::addCreditCard(Address* _billing_address,
unsigned long &_number, std::string &_cardholder)
{
    if (isLogged() == true)
    {
        users[current_user]->getPaymentOptions().push_back(new CreditCard(users[current_user]->getPaymentOptions().size(), _billing_address, _number, _cardholder));
        return (true);
    }
    return (false);
}

bool    Manager::addBizum(Address* _billing_address, unsigned int &_number)
{
    if (isLogged() == true)
    {
        users[current_user]->getPaymentOptions().push_back(new Bizum(users[current_user]->getPaymentOptions().size(), _billing_address, _number));
        return (true);
    }
    return (false);
}

//Segunda entrega
bool    Manager::addProduct(std::string &_name, std::string &_description,
unsigned long &_reference, float &_price)
{
    if ((isLogged() == true) && (users[current_user]->isAdmin() == true))
    {
        products.push_back(new Product(_name, _description, _reference, _price));
        return (true);
    }
    return (false);
}

std::vector<PublicUserData*>    Manager::showUsers()
{
    std::vector<PublicUserData*> data;
    PublicUserData* ptr;
    if ((isLogged() == true) && (users[current_user]->isAdmin() == true))
    {
        for(int i = 0; i < users.size(); i++)
        {
            ptr = users[i];
            data[i] = ptr;
        }
    }
    return (data);
}

bool    Manager::makeOrder(std::vector<unsigned long> &_products,
int &_delivery_address, int &_payment_option)
{
    unsigned long ref = (unsigned long)rand();
    float   total = 0;
    if (isLogged() == true)
    {
        for(int i = 0; i < _products.size(); i++)
        {
            for(int j = 0; j < products.size(); j++)
            {
                if (_products[j] == products[i]->getReference())
                    total += products[i]->getPrice();
            }
        }
    }
    else
        return (false);
    if (users[current_user]->isAdmin() == true)
        total = total - (total * 0.075);
    users[current_user]->getOrders().push_back(new Order(ref, _products, _delivery_address, _payment_option, total));
    return (true);
}

bool    Manager::createReview(unsigned long &_reference, int &_rating,
std::string &_text)
{
    unsigned long id = (unsigned long)rand;
    if (isLogged() == true)
    {
        for (int i = 0; i < users[current_user]->getOrders().size(); i++)
        {
            for (int j = 0; j < users[current_user]->getOrders()[i]->getProducts().size(); j++)
            {
                if (_reference == users[current_user]->getOrders()[i]->getProducts()[j])
                {
                    for(int k = 0; k < products.size(); k++)
                    {
                        if (_reference == products[k]->getReference())
                        {
                            products[k]->getReviews().push_back(new Review(id, _rating, _text, users[current_user]));
                            return (true);
                        }
                    }
                }
            }
        }
    }
    return (false);
}

std::vector<Review*>    Manager::getReviewsByRating(unsigned long &_reference, int &_rating)
{
    std::vector<Review*> filter;
    Review* ptr = nullptr;
    for (int i = 0; i < products.size(); i++)
    {
        if (_reference == products[i]->getReference())
        {
            for (int j = 0; j < products[i]->getReviews().size(); j++)
            {
                if (_rating == products[i]->getReviews()[j]->getRating())
                {
                    ptr = products[i]->getReviews()[j];
                    filter.push_back(ptr);
                }
            }
        }
    }
    return (filter);
}

bool    Manager::upvoteReview(unsigned long &_id)
{
    for (int i = 0; i < products.size(); i++)
    {
        for (int j = 0; j < products[i]->getReviews().size(); j++)
        {
            if ((_id == products[i]->getReviews()[j]->getId()) && (products[i]->getReviews()[j]->getAuthor()->getUsername() != users[current_user]->getUsername()))
            {
                products[i]->getReviews()[j]->incrementVotes();
                products[i]->getReviews()[j]->getAuthor()->increaseReputation();
                return (true);
            }
        }
    }
    return (false);
}

bool    Manager::downvoteReview(unsigned long &_id)
{
    for (int i = 0; i < products.size(); i++)
    {
        for (int j = 0; j < products[i]->getReviews().size(); j++)
        {
            if ((_id == products[i]->getReviews()[j]->getId()) && (products[i]->getReviews()[j]->getAuthor()->getUsername() != users[current_user]->getUsername()))
            {
                products[i]->getReviews()[j]->decrementVotes();
                products[i]->getReviews()[j]->getAuthor()->decreaseReputation();
                return (true);
            }
        }
    }
    return (false);
}

bool    Manager::modifyReviewRating(unsigned long &_id, int &_rating)
{
    if (isLogged() == false)
        return (false);
    for (int i = 0; i < products.size(); i++)
    {
        for (int j = 0; j < products[i]->getReviews().size(); j++)
        {
            if ((products[i]->getReviews()[j]->getId() == _id) && (products[i]->getReviews()[j]->getAuthor()->getUsername() == users[current_user]->getUsername()))
            {
                products[i]->getReviews()[j]->setRating(_rating);
                return (true);
            }
        }
    }
    return (false);
}

bool    Manager::modifyReviewText(unsigned long &_id, std::string &_text)
{
    if (isLogged() == false)
        return (false);
    for (int i = 0; i < products.size(); i++)
    {
        for (int j = 0; j < products[i]->getReviews().size(); j++)
        {
            if ((products[i]->getReviews()[j]->getId() == _id) && (products[i]->getReviews()[j]->getAuthor()->getUsername() == users[current_user]->getUsername()))
            {
                products[i]->getReviews()[j]->setText(_text);
                return (true);
            }
        }
    }
    return (false);
}

bool    Manager::deleteReview(unsigned long &_id)
{
    if (isLogged() == false)
        return (false);
    for (int i = 0; i < products.size(); i++)
    {
        for (int j = 0; j < products[i]->getReviews().size(); j++)
        {
            if (products[i]->getReviews()[j]->getAuthor()->getUsername() == users[current_user]->getUsername())
            {
                delete products[i]->getReviews()[j];
                return (true);
            }
        }
    }
    return (false);
}

//Tercera entrega
void    Manager::saveToFile(std::string fileAddress)
{

}

void    Manager::loadFromFile(std::string fileAddress)
{

}