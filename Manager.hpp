#ifndef MANAGER_HPP
# define MANAGER_HPP

# include "User.hpp"
# include "Product.hpp"
# include "Admin.hpp"
# include "Address.hpp"
# include "CreditCard.hpp"

class Manager
{
    private:
        std::vector<User*>      _users;
        std::vector<Product*>   _products;
        int                     _current_user;
    public:
        std::vector<User*>              &getUsers();
        std::vector<Product*>           &getProducts();
        Manager();
        ~Manager();
        bool                            login(std::string &email, std::string &password);
        bool                            logout();
        bool                            isLogged();
        User*                           getCurrentUser();
        bool                            addUser(std::string &username, std::string &email,
        std::string &password);
        bool                            addAdmin(std::string &username, std::string &email,
        std::string &password, unsigned long &worker_id);
        bool                            eraseCurrentUser();
        bool                            editUsername(std::string &username);
        bool                            editEmail(std::string &email);
        bool                            editPassword(std::string &password);
        bool                            addAddress(std::string address, std::string city,
        std::string province, unsigned int postal_code);
        bool                            addCreditCard(Address* billing_address,
        unsigned long number, std::string cardholder);
        bool                            addBizum(Address* billing_address, unsigned int number);

        //Segunda entrega
        bool                            addProduct(std::string name, std::string description,
        unsigned long reference, float price);
        std::vector<PublicUserData*>    showUsers();
        bool                            makeOrder(std::vector<unsigned long> products,
        int delivery_address, int payment_option);
        bool                            createReview(unsigned long reference, int rating,
        std::string text);
        std::vector<Review*>            getReviewsByRating(unsigned long reference, int rating);
        bool                            upvoteReview(unsigned long id);
        bool                            downvoteReview(unsigned long id);
        bool                            modifyReviewRating(unsigned long id, int rating);
        bool                            modifyReviewText(unsigned long id, std::string text);
        bool                            deleteReview(unsigned long id);

        //Tercera entrega
        void                            saveToFile(std::string fileAddress);
        void                            loadFromFile(std::string fileAddress);
};

#endif // MANAGER_HPP
