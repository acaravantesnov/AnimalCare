#include "Admin.hpp"

Admin::Admin() {}

Admin::Admin(const std::string &username, const std::string &email, const std::string &password,
const unsigned long &worker_id)
{
    this->username = username;
    this->email = email;
    this->password = password;
    this->worker_id = worker_id;
}

bool    Admin::isAdmin() {return (true);}

