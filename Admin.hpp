#ifndef ADMIN_HPP
# define ADMIN_HPP

# include "User.hpp"

class Admin : public User
{
    protected:
        unsigned long   _worker_id;
    private:
        Admin();
    public:
        Admin(std::string username, std::string email, std::string password,
        unsigned long worker_id);
};

#endif // ADMIN_HPP
