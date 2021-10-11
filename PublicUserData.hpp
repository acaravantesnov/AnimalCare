#ifndef PUBLICUSERDATA_HPP
# define PUBLICUSERDATA_HPP

# include <string>

class PublicUserData
{
    protected:
        std::string username;
        int         reputation;
        PublicUserData();
    public:
        std::string &getUsername();
        void        setUsername(std::string &_username);
        int         &getReputation();
        void        increaseReputation();
        void        decreaseReputation();
        PublicUserData(std::string const &_username);
};

#endif // PUBLICUSERDATA_HPP
