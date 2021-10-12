#ifndef REVIEW_HPP
# define REVIEW_HPP

# include <ctime>
# include <string>
# include "PublicUserData.hpp"
# include "User.hpp"


class Review
{
    private:
        unsigned long   id;
        std::time_t     date;
        int             rating;
        std::string     text;
        int             votes;
        PublicUserData* author;
        Review();
    public:
        unsigned long   &getId();
        std::time_t     &getDate();
        void            setDate(std::time_t &_date);
        int             &getRating();
        void            setRating(int &_rating);
        std::string     &getText();
        void            setText(std::string &_text);
        int             &getVotes();
        void            incrementVotes();
        void            decrementVotes();
        PublicUserData* getAuthor();
        Review(unsigned long const &_id, int const &_rating, std::string const &_text, PublicUserData* _author);
        std::string     show();
};

#endif // REVIEW_HPP
