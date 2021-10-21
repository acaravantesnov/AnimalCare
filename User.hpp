#ifndef USER_HPP
# define USER_HPP

# include "PrivateUserData.hpp"
# include "PublicUserData.hpp"

class   User : public PrivateUserData, public PublicUserData
{
    public:
        User(std::string const &username, std::string const &email, std::string const &password);
        virtual ~User() {}
        virtual bool    isAdmin();
    protected:
        User();
};

#endif // USER_HPP
