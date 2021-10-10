#include "Admin.hpp"

Admin::Admin() {}

Admin::Admin(std::string username, std::string email, std::string password,
unsigned long worker_id)
{
    _username = username;
    _email = email;
    _password = password;
    _worker_id = worker_id;
}
