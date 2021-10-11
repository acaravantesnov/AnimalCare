#include "User.hpp"

User::User() {}

User::User(const std::string &_username, const std::string &_email, const std::string &_password)
{
    username = _username;
    email = _email;
    password = _password;
}

bool    User::isAdmin() {return (false);}
