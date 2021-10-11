#ifndef MANAGER_HPP
# define MANAGER_HPP

# include "User.hpp"
# include "Product.hpp"
# include "Admin.hpp"
# include "Address.hpp"
# include "CreditCard.hpp"
# include <cstdlib>

class Manager
{
    private:
        std::vector<User*>      users;
        std::vector<Product*>   products;
        int                     current_user;
    public:
        std::vector<User*>              &getUsers();
        std::vector<Product*>           &getProducts();
        Manager();
        ~Manager();
        bool                            login(std::string &_email, std::string &_password);
        bool                            logout();
        bool                            isLogged();
        User*                           getCurrentUser();
        bool                            addUser(std::string &_username, std::string &_email,
        std::string &_password);
        bool                            addAdmin(std::string &_username, std::string &_email,
        std::string &_password, unsigned long &_worker_id);
        bool                            eraseCurrentUser();
        bool                            editUsername(std::string &_username);
        bool                            editEmail(std::string &_email);
        bool                            editPassword(std::string &_password);
        bool                            addAddress(std::string &_address, std::string &_city,
        std::string &_province, unsigned int &_postal_code);
        bool                            addCreditCard(Address* _billing_address,
        unsigned long &_number, std::string &_cardholder);
        bool                            addBizum(Address* _billing_address, unsigned int &_number);

        //Segunda entrega
        bool                            addProduct(std::string &_name, std::string &_description,
        unsigned long &_reference, float &_price);
        std::vector<PublicUserData*>    showUsers();
        bool                            makeOrder(std::vector<unsigned long> &_products,
        int &_delivery_address, int &_payment_option);
        bool                            createReview(unsigned long &_reference, int &_rating,
        std::string &_text);
        std::vector<Review*>            getReviewsByRating(unsigned long &_reference, int &_rating);
        bool                            upvoteReview(unsigned long &_id);
        bool                            downvoteReview(unsigned long &_id);
        bool                            modifyReviewRating(unsigned long &_id, int &_rating);
        bool                            modifyReviewText(unsigned long &_id, std::string &_text);
        bool                            deleteReview(unsigned long &_id);

        //Tercera entrega
        void                            saveToFile(std::string fileAddress);
        void                            loadFromFile(std::string fileAddress);
};

#endif // MANAGER_HPP
