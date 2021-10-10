#ifndef USER_HPP
# define USER_HPP

# include <iostream>
# include "PrivateUserData.hpp"
# include "PublicUserData.hpp"

class   User : public PrivateUserData, PublicUserData
{
    public:
        User(std::string username, std::string email, std::string password);
        virtual bool    isAdmin();
    protected:
        User();
};

#endif // USER_HPP
