#include "Admin.hpp"

Admin::Admin() {}

Admin::Admin(const std::string &_username, const std::string &_email, const std::string &_password,
const unsigned long &_worker_id)
{
    username = _username;
    email = _email;
    password = _password;
    worker_id = _worker_id;
}

void    Admin::isAdmin() {return (true);}
