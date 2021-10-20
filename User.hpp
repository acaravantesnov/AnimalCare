#ifndef USER_HPP
# define USER_HPP

# include "PrivateUserData.hpp"
# include "PublicUserData.hpp"

class   User : public PrivateUserData, public PublicUserData
{
    public:
        User(std::string const &_username, std::string const &_email, std::string const &_password);
        virtual ~User() {}
        virtual bool    isAdmin();
    protected:
        User();
};

#endif // USER_HPP
