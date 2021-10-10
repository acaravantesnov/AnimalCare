#include "PublicUserData.hpp"

PublicUserData::PublicUserData() {}

std::string &PublicUserData::getUsername() {return (_username);}

void    PublicUserData::setUsername(std::string &username) {_username = username;}

int &PublicUserData::getReputation() {return (_reputation);}

void    PublicUserData::increaseReputation() {_reputation++;}

void    PublicUserData::decreaseReputation()
{
    if (_reputation >= 1)
        _reputation--;
}

PublicUserData::PublicUserData(std::string username)
{
    _username = username;
    _reputation = 0;
}
