#include "User.hpp"

User::User() {}

User::User(const std::string &username, const std::string &email, const std::string &password)
{
    this->username = username;
    this->email = email;
    this->password = password;
}

bool    User::isAdmin() {return (false);}
