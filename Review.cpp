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

PublicUserData*  Review::getAuthor() {return (author);}

Review::Review(const unsigned long &id, const int &rating, const std::string &text, PublicUserData* author)
{
    this->id = id;
    this->rating = rating;
    this->text = text;
    this->author = author;
    date = time_t(0);
    votes = 0;
}

std::string Review::show()
{
    std::string showstr;
    showstr = '\t' + std::to_string(rating) + " starts on " + std::to_string(date) + " by " + getAuthor()->getUsername() + " \t" + text +
    '\t' + std::to_string(votes) + " votes";
    return (showstr);
}
