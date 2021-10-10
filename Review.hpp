#ifndef REVIEW_HPP
# define REVIEW_HPP

# include <ctime>
# include <string>
# include "PublicUserData.hpp"
# include "User.hpp"


class Review : public User
{
    private:
        unsigned long   _id;
        std::time_t     _date;
        int             _rating;
        std::string     _text;
        int             _votes;
        PublicUserData* _author;
        Review();
    public:
        unsigned long   &getId();
        std::time_t     &getDate();
        void            setDate(std::time_t &date);
        int             &getRating();
        void            setRating(int &rating);
        std::string     &getText();
        void            setText(std::string &text);
        int             &getVotes();
        void            incrementVotes();
        void            decrementVotes();
        PublicUserData  getAuthor();
        Review(unsigned long id, int rating, std::string text, PublicUserData* author);
        std::string     show();
};

#endif // REVIEW_HPP
