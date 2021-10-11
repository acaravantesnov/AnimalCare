#include "PublicUserData.hpp"

PublicUserData::PublicUserData() {}

std::string &PublicUserData::getUsername() {return (username);}

void    PublicUserData::setUsername(std::string &_username) {username = _username;}

int &PublicUserData::getReputation() {return (reputation);}

void    PublicUserData::increaseReputation() {reputation++;}

void    PublicUserData::decreaseReputation()
{
    if (reputation >= 1)
        reputation--;
}

PublicUserData::PublicUserData(const std::string &_username)
{
    username = _username;
    reputation = 0;
}
