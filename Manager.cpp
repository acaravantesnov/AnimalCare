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
    users.push_back(new User(_username, _email, _password));
}

bool    Manager::addAdmin(std::string &_username, std::string &_email,
std::string &_password, unsigned long &_worker_id)
{
    users.push_back(new Admin(_username, _email, _password, _worker_id));
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
        users[current_user]->addresses.push_back(new Address(users[current_user]->addresses.size() - 1, _address, _city, _province, _postal_code));
        return (true);
    }
    return (false);
}

bool    Manager::addCreditCard(Address* _billing_address,
unsigned long &_number, std::string &_cardholder)
{
    if (isLogged() == true)
    {
        users[current_user]->payment_options.push_back(new CreditCard(users[current_user]->payment_options.size() - 1,_billing_address, _number, _cardholder));
        return (true);
    }
    return (false);
}

bool    Manager::addBizum(Address* _billing_address, unsigned int &_number)
{
    if (isLogged() == true)
    {
        users[current_user]->payment_options.push_back(new Bizum(users[current_user]->payment_options.size() - 1,_billing_address, _number));
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
    std::vector<PublicUserData*>    data;
    if ((isLogged() == true) && (users[current_user]->isAdmin() == true))
    {
        for(int i = 0; i < users.size(); i++)
            data[i] = users[i]->PublicUserData;
        return (data);
    }
    return ();
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
