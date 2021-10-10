#include "Review.hpp"

Review::Review() {}

unsigned long   &Review::getId() {return (_id);}

std::time_t &Review::getDate() {return (_date);}

void    Review::setDate(std::time_t &date) {_date = date;}

int &Review::getRating() {return (_rating);}

void    Review::setRating(int &rating) {_rating = rating;}

std::string &Review::getText() {return (_text);}

void    Review::setText(std::string &text) {_text = text;}

int &Review::getVotes() {return (_votes);}

void    Review::incrementVotes() {_votes++;}

void    Review::decrementVotes() {_votes--;}

PublicUserData  Review::getAuthor() {return (_author);}

Review::Review(unsigned long id, int rating, std::string text, PublicUserData* author)
{
    _id = id;
    _rating = rating;
    _text = text;
    _author = author;
    _date = time_t(0);
    _votes = 0;
}

std::string Review::show()
{
    std::string str;
    str = '\t' + _rating + " starts on " + _date + " by " + _username + " \t" + _text +
    '\t' + _votes + " votes";
    return (str);
}
