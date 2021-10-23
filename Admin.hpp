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
        Admin(std::string const &username, std::string const &email, std::string const &password,
        unsigned long const &worker_id);
};

#endif // ADMIN_HPP
