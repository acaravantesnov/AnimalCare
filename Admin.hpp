#ifndef ADMIN_HPP
# define ADMIN_HPP

# include "User.hpp"

class Admin : public User
{
    protected:
        unsigned long   worker_id;
    private:
        Admin();
    public:
        bool    isAdmin();
        Admin(std::string const &_username, std::string const &_email, std::string const &_password,
        unsigned long const &_worker_id);
};

#endif // ADMIN_HPP
