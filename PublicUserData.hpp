#ifndef PUBLICUSERDATA_HPP
# define PUBLICUSERDATA_HPP

class PublicUserData
{
    protected:
        std::string _username;
        int         _reputation;
        PublicUserData();
    public:
        std::string &getUsername();
        void        setUsername(std::string &username);
        int         &getReputation();
        void        increaseReputation();
        void        decreaseReputation();
        PublicUserData(std::string username);
};

#endif // PUBLICUSERDATA_HPP
