#include "Review.hpp"

Review::Review() {}

unsigned long   &Review::getId() {return (id);}

std::time_t &Review::getDate() {return (date);}

void    Review::setDate(std::time_t &_date) {date = _date;}

int &Review::getRating() {return (rating);}

void    Review::setRating(int &_rating) {rating = _rating;}

std::string &Review::getText() {return (text);}

void    Review::setText(std::string &_text) {text = _text;}

int &Review::getVotes() {return (votes);}

void    Review::incrementVotes() {votes++;}

void    Review::decrementVotes() {votes--;}

PublicUserData  Review::getAuthor() {return (author);}

Review::Review(const unsigned long &_id, const int &_rating, const std::string &_text, PublicUserData* _author)
{
    id = _id;
    rating = _rating;
    text = _text;
    author = _author;
    date = time_t(0);
    votes = 0;
}

std::string Review::show()
{
    std::string showstr;
    showstr = '\t' + rating + " starts on " + date + " by " + author->username + " \t" + text +
    '\t' + votes + " votes";
    return (showstr);
}
