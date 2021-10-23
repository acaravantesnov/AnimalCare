#include "Interface.hpp"

interface::interface() {}

void    interface::header()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << R"(
      /\_/\  (
     ( ^.^ ) _)
       \"/  (
     ( | | )
    (__d b__)
    )" << '\n';
}

void    interface::headerLoggedUser()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "\t\t--- USER ---" << std::endl;
    std::cout << "\t UserName: " << getCurrentUser()->getUsername() << std::endl;
    std::cout << "\t Email: " << getCurrentUser()->getEmail() << std::endl;
}

void    interface::headerLoggedAdmin()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "\t\t--- ADMIN ---" << std::endl;
    std::cout << "\t UserName: " << getCurrentUser()->getUsername() << std::endl;
    std::cout << "\t Email: " << getCurrentUser()->getEmail() << std::endl;
    std::cout << "\t Worker Id: " << getCurrentWorker_Id() << std::endl;
}

std::vector<unsigned long> &interface::getWorker_Ids() {return (worker_ids);}

unsigned long   interface::getCurrentWorker_Id()
{
    for (long unsigned int i = 0; i < getUsers().size(); i++)
    {
        if (getUsers()[i]->getEmail() == getCurrentUser()->getEmail())
                return (getWorker_Ids()[i]);
    }
    return (0);
}

void    interface::clearscreen() {system("clear");}

void    interface::wellcome()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "| Welcome to AnimalCare!                         |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

bool    interface::Ilogin()
{
    std::string email, password;
    std::cout << "\n  Email: "; std::cin >> email;
    std::cout << "  Password: "; std::cin >> password;
    if (login(email, password) == true)
    {
        std::cout << "\n  Successful login!" << std::endl;
        std::this_thread::sleep_for(g_timespan);
        if (getCurrentUser()->isAdmin() == true)
            adminMenu();
        else
            userMenu();
        return (true);
    }
    else
    {
        std::cout << "\n  Unsuccessful login :-(" << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
    return (false);
}

bool    interface::IaddAdmin()
{
    std::string username;
    std::string email;
    std::string password;
    unsigned long worker_id;
    std::cout << "\n  Username: "; std::cin >> username;
    std::cout << "  Email: "; std:: cin >> email;
    while (email.std::string::find("@") > email.std::string::length())
    {
        std::cin.clear();
        std::cout << "  Invalid Email, try again\n  Email: "; std:: cin >> email;
    }
    std::cout << "  Password: "; std::cin >> password;
    worker_id = static_cast<unsigned long>(rand());
    worker_ids.push_back(worker_id);
    if (addAdmin(username, email, password, worker_id) == true)
    {
        std::cout << "\n  Created Admin! \n" << std::endl;
        std::this_thread::sleep_for(g_timespan);
        return (true);
    }
    else
        std::cout << "\n  Wrong Admin creation (Username or email already existing?)" << std::endl;
    std::this_thread::sleep_for(g_timespan);
    return (false);
}

bool    interface::Icreateacc()
{
    std::string username, email, password, option;
    std::cout << "  [Admin] or [User]? "; std::cin >> option;
    if ((option == "Admin") || (option == "admin") || (option == "ADMIN"))
        IaddAdmin();
    else if ((option == "User") || (option == "user") || (option == "USER"))
    {
        std::cout << "\n  Username: "; std::cin >> username;
        std::cout << "  Email: "; std:: cin >> email;
        while (email.std::string::find("@") > email.std::string::length())
        {
            std::cin.clear();
            std::cout << "  Invalid Email, try again\n  Email: "; std:: cin >> email;
        }
        std::cout << "  Password: "; std::cin >> password;
        if (addUser(username, email, password) == true)
            std::cout << "\n  Created User!" << std::endl;
        else
            std::cout << "\n  Wrong User creation (Username or email already existing?)" << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
    else
        std::cout << "  Introduce a valid command!" << std::endl;
    return (false);
}

void    interface::orderMenu(int _address, int _payment)
{
    long unsigned int prod = 0;
    std::cout << "\n  1. Add product to cart" << std::endl;
    std::cout << "  2. Make order" << std::endl;
    std::cout << "  3. Exit" << std::endl;
    std::cout << "\n  Select a valid option: "; std::cin >> opt;
    if (opt == "1")
    {
        std::cout << "\n  Which product? "; std::cin >> prod;
        if ((getProducts().size() >= 1) && (prod >= 1) && (prod <= getProducts().size()))
        {
            getCurrentUser()->getCart()->addProduct(getProducts()[prod - 1]->getReference());
            std::cout << "  Added product to Shopping Cart." << std::endl;
            std::this_thread::sleep_for(g_timespan);
            clearscreen();
            header();
        }
    }
    else if (opt == "2")
    {
        if (getCurrentUser()->getCart()->getProducts().size() > 0)
        {
            makeOrder(getCurrentUser()->getCart()->getProducts(), _address, _payment);
            std::cout << "  Order made!" << std::endl;
            std::this_thread::sleep_for(g_timespan);
            exitorderMenu = 1;
            exitmakeorderMenu = 1;
        }
        else
            std::cout << "  No products on cart, try again later!" << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
    else if (opt == "3")
    {
        exitorderMenu = 1;
        exitmakeorderMenu = 1;
    }
}

void    interface::uodMenu()
{
    unsigned long id;
    int ok = 0;
    std::cout << "\n  Review id: "; std::cin >> id;
    for (long unsigned int i = 0; i < getProducts().size(); i++)
    {
        for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
        {
            if (getProducts()[i]->getReviews()[j]->getId() == id)
                ok = 1;
        }
    }
    if (ok == 0)
        exituodMenu = 1;
    else
    {
        std::cout << "\n  Up or Down vote review?" << std::endl;
        std::cout << "  1. Upvote" << std::endl;
        std::cout << "  2. Downvote" << std::endl;
        std::cout << "\n  Select a valid option: "; std::cin >> opt;
        if (opt == "1")
        {
            if (upvoteReview(id) == true)
                std::cout << "\n  Review votes changed!" << std::endl;
        }
        else if (opt == "2")
        {
            if (downvoteReview(id) == true)
                std::cout << "\n  Review votes changed!" << std::endl;
        }
        else
            std::cout << "\n  Review votes remain unchanged.." << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
}

void    interface::modifyrevMenu()
{
    unsigned long reference;
    std::string option;
    int rating;
    std::string text;
    std::cout << "\n  Review id: "; std::cin >> reference;
    std::cout << "  Modify [Rating], [Text], or [Both]? "; std::cin >> option;
    if ((option == "Rating") || (option == "rating") || (option == "RATING"))
    {
        std::cout << "\n  New Rating [0 - 5]: "; std::cin >> rating;
        for (long unsigned int i = 0; i < getProducts().size(); i++)
        {
            for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
            {
                if (getProducts()[i]->getReviews()[j]->getId() == reference)
                {
                    if ((modifyReviewRating(reference, rating) == true) && (rating >= 0) && (rating <= 5))
                        std::cout << "\n  Successfully changed review rating!" << std::endl;
                    else
                        std::cout << "\n  Wrong review id or invalid rating [0-5]" << std::endl;
                }
            }
        }
    }
    else if ((option == "Text") || (option == "text") || (option == "TEXT"))
    {
        std::cout << "\n  New Text: "; std::cin >> text;
        for (long unsigned int i = 0; i < getProducts().size(); i++)
        {
            for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
            {
                if (getProducts()[i]->getReviews()[j]->getId() == reference)
                {
                    if (modifyReviewText(reference, text) == true)
                        std::cout << "\n  Successfully changed review text!" << std::endl;
                    else
                        std::cout << "\n  Wrong review id" << std::endl;
                }
            }
        }
    }
    else if ((option == "Both") || (option == "both") || (option == "BOTH"))
    {
        std::cout << "\n  New Rating [0 - 5]: "; std::cin >> rating;
        std::cout << "\n  New Text: "; std::cin >> text;
        for (long unsigned int i = 0; i < getProducts().size(); i++)
        {
            for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
            {
                if ((getProducts()[i]->getReviews()[j]->getId() == reference) && (rating >= 0) && (rating <= 5))
                {
                    modifyReviewRating(reference, rating);
                    modifyReviewText(reference, text);
                }
                else
                    std::cout << "\n  Wrong review id or invalid rating [0-5]" << std::endl;
            }
        }
    }
    else
        std::cout << "  Introduce a valid command!" << std::endl;
    std::this_thread::sleep_for(g_timespan);
}

void    interface::addressMenu()
{
    std::string address, province, city;
    unsigned int postal_code;
    int id;
    if (getCurrentUser()->getAddresses().size() > 0)
    {
        std::cout << "*------------------------------------------------*" << std::endl;
        for (long unsigned int i = 0; i < getCurrentUser()->getAddresses().size(); i++)
            std::cout << i + 1 << ".- id: " << getCurrentUser()->getAddresses()[i]->getId() << " " <<
            getCurrentUser()->getAddresses()[i]->show() << std::endl;
        std::cout << "*------------------------------------------------*" << std::endl;
    }
    std::cout << "\n  1. Add address" << std::endl;
    std::cout << "  2. Exit" << std::endl;
    std::cout << "\n  Select a valid option: "; std::cin >> opt;
    if (opt == "1")
    {
        clearscreen();
        header();
        std::cout << "\n  Address: "; std::getline(std::cin >> std::ws, address);
        std::cout << "  Postal code: "; std::cin >> postal_code;
        while (!std::cin.good())
        {
            std::cout << "  ERROR: Introduce numeric value\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "  Postal code: "; std::cin >> postal_code;
        }
        std::cout << "  City: "; std::getline(std::cin >> std::ws, city);
        std::cout << "  Province: "; std::getline(std::cin >> std::ws, province);
        id = rand();
        getCurrentUser()->getAddresses().push_back(new Address(id, address, city, province, postal_code));
        exitaddressMenu = 1;
    }
    else if (opt == "2")
        exitaddressMenu = 1;
}

void    interface::paymentMenu()
{
    std::string cardholder;
    long unsigned int billing_addressi;
    unsigned int number;
    unsigned long creditnumber;
    Address* ptr;
    clearscreen();
    if (getCurrentUser()->isAdmin() == true)
        headerLoggedAdmin();
    else
        headerLoggedUser();
    if (getCurrentUser()->getPaymentOptions().size() > 0)
    {
        std::cout << "*------------------------------------------------*" << std::endl;
        for (long unsigned int i = 0; i < getCurrentUser()->getPaymentOptions().size(); i++)
           std::cout << i + 1 << ".- " << getCurrentUser()->getPaymentOptions()[i]->show() << std::endl;
        std::cout << "*------------------------------------------------*" << std::endl;
    }
    std::cout << "\n  1. Add payment option" << std::endl;
    std::cout << "  2. Exit" << std::endl;
    std::cout << "\n  Select a valid option: "; std::cin >> opt;
    if (opt == "1")
    {
        clearscreen();
        if (getCurrentUser()->isAdmin() == true)
            headerLoggedAdmin();
        else
            headerLoggedUser();
        std::cout << "\n  1. Bizum" << std::endl;
        std::cout << "  2. Credit Card" << std::endl;
        std::cout << "  3. Exit" << std::endl;
        std::cout << "\n  Select a valid option: "; std::cin >> opt;
        if (((opt == "1") || (opt == "2")) && (getCurrentUser()->getAddresses().size() > 0))
        {
            std::cout << "*------------------------------------------------*" << std::endl;
            for (long unsigned int i = 0; i < getCurrentUser()->getAddresses().size(); i++)
                std::cout << i + 1 << ".-  " << getCurrentUser()->getAddresses()[i]->show() << std::endl;
            std::cout << "*------------------------------------------------*" << std::endl;
            std::cout << "\n  Select Billing address [Index]: "; std::cin >> billing_addressi;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "\n  Select Billing address [Index]: "; std::cin >> billing_addressi;
            }
            if ((billing_addressi <= getCurrentUser()->getAddresses().size()) && (billing_addressi > 0))
                ptr = getCurrentUser()->getAddresses()[billing_addressi - 1];
        }
        if (getCurrentUser()->getAddresses().size() == 0)
        {
            std::cout << "\n  No addresses created!" << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if ((opt == "1") && (billing_addressi > 0) && (billing_addressi <= getCurrentUser()->getAddresses().size()))
        {
            clearscreen();
            header();
            std::cout << "  Phone number: "; std::cin >> number;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Phone number: "; std::cin >> number;
            }
            addBizum(ptr, number);
        }
        else if (opt == "2")
        {
            clearscreen();
            header();
            std::cout << "  Credit card number: "; std::cin >> creditnumber;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Credit card number: "; std::cin >> creditnumber;
            }
            std::cout << "  Cardholder: "; std::cin >> cardholder;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Cardholder: "; std::cin >> cardholder;
            }
            addCreditCard(ptr, creditnumber, cardholder);
        }
    }
    else if (opt == "2")
        exitpaymentMenu = 1;
}

void    interface::userMenu()
{
    int rating;
    std::string text;
    long unsigned int index;
    int ex;
    exitUserMenu = 0;
    while (exitUserMenu != 1)
    {
        clearscreen();
        headerLoggedUser();
        std::cout << std::endl;
        std::cout << "  1. Make order                                   " << std::endl;
        std::cout << "  2. Create review                                " << std::endl;
        std::cout << "  3. Get reviews by rating                        " << std::endl;
        std::cout << "  4. Up/Downvote review                           " << std::endl;
        std::cout << "  5. Modify review                                " << std::endl;
        std::cout << "  6. Delete review                                " << std::endl;
        std::cout << "\n  -- Profile options --                         " << std::endl;
        std::cout << "  7. Edit Username                                " << std::endl;
        std::cout << "  8. Edit Email                                   " << std::endl;
        std::cout << "  9. Edit Password                                " << std::endl;
        std::cout << "  10. View/Add addresses                          " << std::endl;
        std::cout << "  11. View/Add payment options                    " << std::endl;
        std::cout << "  12. Logout                                      " << std::endl;
        std::cout << std::endl;
        opt = "";
        std::cin.clear();
        std::cout << "  Choose a valid option: "; std::cin >> opt;
        if (opt == "1") //Make order
        {
            clearscreen();
            headerLoggedUser();
            while (exitmakeorderMenu != 1)
                makeorderMenu();
            exitmakeorderMenu = 0;
        }
        else if (opt == "2") //Create review
        {
            clearscreen();
            headerLoggedAdmin();
            if (getCurrentUser()->getOrders().size() > 0)
            {
                std::cout << "\n*------------------------------------------------*" << std::endl;
                for (long unsigned int i = 0; i < getProducts().size(); i++)
                    std::cout << *getProducts()[i] << std::endl;
                std::cout << "*------------------------------------------------*" << std::endl;
                do
                {
                    std::cout << "\n  Select a valid index: "; std::cin >> index;
                }while (index > getProducts().size());
                do
                {
                    std::cout << "  Rating [0-5]: "; std::cin >> rating;
                    while (!std::cin.good())
                    {
                        std::cout << "  ERROR: Introduce numeric value\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "  Rating [0-5]: "; std::cin >> rating;
                    }
                }while (rating > 5);
                std::cout << "  Introduce text: "; std::getline(std::cin >> std::ws, text);
                for (long unsigned int i = 0; i < getCurrentUser()->getOrders().size(); i++)
                {
                    for (long unsigned j = 0; j < getCurrentUser()->getOrders()[i]->getProducts().size(); j++)
                    {
                        if (getCurrentUser()->getOrders()[i]->getProducts()[j] == getProducts()[index - 1]->getReference())
                        {
                            createReview(getProducts()[index - 1]->getReference(), rating, text);
                            ex = 1;
                        }
                    }
                }
                if (ex == 0)
                {
                    std::cout << "  You have not bought this product yet.." << std::endl;
                    std::this_thread::sleep_for(g_timespan);
                }
            }
            else
            {
                std::cout << "  You have not bought any products yet.." << std::endl;
                std::this_thread::sleep_for(g_timespan);
            }
        }
        else if (opt == "3")  //Get reviews by rating
        {
            clearscreen();
            headerLoggedUser();
            if (getProducts().size() > 0)
            {
                std::cout << "\n*------------------------------------------------*" << std::endl;
                for (long unsigned int i = 0; i < getProducts().size(); i++)
                    std::cout << *getProducts()[i] << std::endl;
                std::cout << "*------------------------------------------------*" << std::endl;
                do
                {
                    std::cout << "\n  Select a valid index: "; std::cin >> index;
                }while (index > getProducts().size());
                std::cout << "  Rating: "; std::cin >> rating;
                while (!std::cin.good())
                {
                    std::cout << "  ERROR: Introduce numeric value\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "  Rating: "; std::cin >> rating;
                }
                std::cout << "\n  REVIEWS: \n" << std::endl;
                for(long unsigned int i = 0; i < getReviewsByRating(getProducts()[index - 1]->getReference(), rating).size(); i++)
                {
                    std::cout << "  Id: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getId() << std::endl;
                    std::cout << "  Rating: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getRating() << std::endl;
                    std::cout << "  Text: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getText() << std::endl;
                    std::cout << "  Author: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getAuthor()->getUsername() << std::endl;
                    std::cout << "  Votes: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getVotes() << std::endl;
                    std::cout << "  Date: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getDate() << "\n" << std::endl;
                }
                std::this_thread::sleep_for(g_timespan2);
            }
        }
        else if (opt == "4") //Up/downvote review
        {
            clearscreen();
            headerLoggedUser();
            while (exituodMenu != 1)
                uodMenu();
            exituodMenu = 0;
        }
        else if (opt == "5") //Modify review
        {
            clearscreen();
            headerLoggedUser();
            while (exitmodifyrevMenu != 1)
                modifyrevMenu();
            exitmodifyrevMenu = 0;
        }
        else if (opt == "6") //Delete review
        {
            unsigned long id;
            int exfor = 0;
            clearscreen();
            headerLoggedUser();
            std::cout << " \n  Introduce review id: "; std::cin >> id;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << " \n  Introduce review id: "; std::cin >> id;
            }
            for (long unsigned int i = 0; i < getProducts().size(); i++)
            {
                for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
                {
                    if (id == getProducts()[i]->getReviews()[j]->getId())
                    {
                        deleteReview(id);
                        std::cout << "\n  Review deleted!" << std::endl;
                        exfor = 1;
                    }
                }
            }
            if (exfor == 0)
                std::cout << "\n  Review not found." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "7") //Edit Username
        {
            std::string username;
            clearscreen();
            headerLoggedUser();
            std::cout << "\n  Introduce new USERNAME: "; std::cin >> username;
            if(editUsername(username) == true)
                std::cout << "\n  Successfully changed actual username." << std::endl;
            else
                std::cout << "\n  Error: Already existing username." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "8") //Edit Email
        {
            std::string email;
            clearscreen();
            headerLoggedUser();
            std::cout << "\n  Introduce new EMAIL: "; std::cin >> email;
            if(editEmail(email) == true)
                std::cout << "\n  Successfully changed actual email." << std::endl;
            else
                std::cout << "\n  Error: Invalid email." << std::endl;
        }
        else if (opt == "9") //Edit Password
        {
            std::string password;
            clearscreen();
            headerLoggedUser();
            std::cout << "\n  Introduce new PASSWORD: "; std::cin >> password;
            editPassword(password);
            std::cout << "\n  Successfully changed actual password." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "10") //View/Edit addresses
        {
            clearscreen();
            headerLoggedUser();
            while (exitaddressMenu != 1)
                addressMenu();
            exitaddressMenu = 0;
        }
        else if (opt == "11") //View/Edit payment options
        {
            clearscreen();
            headerLoggedUser();
            while (exitpaymentMenu != 1)
                paymentMenu();
            exitpaymentMenu = 0;
        }
        else if (opt == "12") //Logout
        {
            logout();
            exitUserMenu = 1;
        }
    }
}

void    interface::Menu()
{
    clearscreen();
    wellcome();
    std::cout << std::endl;
    std::cout << "  1. Login                                        " << std::endl;
    std::cout << "  2. Create an account                            " << std::endl;
    std::cout << "  3. Exit                                         " << std::endl;
    std::cout << "                                                  " << std::endl;
    std::cout << "  Choose a valid option: "; std::cin >> opt;
    if (opt == "1")
    {
        clearscreen();
        header();
        Ilogin();
    }
    else if (opt == "2")
    {
        clearscreen();
        header();
        Icreateacc();
    }
    else if (opt == "3")
    {
        clearscreen();
        exit(0);
    }
}

void    interface::makeorderMenu()
{
    if ((getCurrentUser()->getAddresses().size() == 0) || (getCurrentUser()->getPaymentOptions().size() == 0))
    {
        std::cout << "\n  You must have at least 1 address\n  and 1 payment option" << std::endl;
        std::this_thread::sleep_for(g_timespan2);
        exitmakeorderMenu = 1;
    }
    else
    {
        getCurrentUser()->getCart() = new ShoppingCart();
        std::cout << "*------------------------------------------------*" << std::endl;
        for (long unsigned int i = 0; i < getCurrentUser()->getAddresses().size(); i++)
            std::cout << i + 1 << ".- id: " << getCurrentUser()->getAddresses()[i]->getId() << " " <<
            getCurrentUser()->getAddresses()[i]->show() << std::endl;
        std::cout << "*------------------------------------------------*" << std::endl;
        std::cout << "\n  Select an address for the order [INDEX]: "; std::cin >> opt;
        int addopt = std::stoi(opt);
        std::cout << "\n*------------------------------------------------*" << std::endl;
        for (long unsigned int i = 0; i < getCurrentUser()->getPaymentOptions().size(); i++)
            std::cout << i + 1 << ".- " << getCurrentUser()->getPaymentOptions()[i]->show() << std::endl;
        std::cout << "*------------------------------------------------*" << std::endl;
        std::cout << "\n  Select an address for the order [INDEX]: "; std::cin >> opt;
        int delopt = std::stoi(opt);
        std::cout << "\n  Ready to buy!\n" << std::endl;
        std::this_thread::sleep_for(g_timespan);
        clearscreen();
        header();
        if (getProducts().size() > 0)
        {
            std::cout << "\n*---------------------------------------------*" << std::endl;
            for (long unsigned int i = 0; i < getProducts().size(); i++)
            {
                std::cout << *getProducts()[i] << std::endl;
            }
            std::cout << "*---------------------------------------------*" << std::endl;
            std::this_thread::sleep_for(g_timespan);
            exitorderMenu = 0;
            while(exitorderMenu != 1)
                orderMenu(addopt - 1, delopt - 1);
        }
        else
        {
            std::cout << "\n No products available!" << std::endl;
            std::this_thread::sleep_for(g_timespan);
            exitmakeorderMenu = 1;
        }
    }
}

void    interface::adminMenu()
{
    exitAdminMenu = 0;
    std::string name;
    std::string description;
    unsigned long reference;
    long unsigned int index;
    int rating = -1;
    int ex;
    std::string text;
    float price;
    while (exitAdminMenu != 1)
    {
        clearscreen();
        headerLoggedAdmin();
        std::cout << std::endl;
        std::cout << "- Admin commands: " << std::endl;
        std::cout << "  1. Add product                                  " << std::endl;
        std::cout << "  2. Show users                                   " << std::endl;
        std::cout << "  3. Save to file                                 " << std::endl;
        std::cout << "  4. Load from file                               " << std::endl;
        std::cout << "\n- User commands:                                " << std::endl;
        std::cout << "  5. Make order                                   " << std::endl;
        std::cout << "  6. Create review                                " << std::endl;
        std::cout << "  7. Get reviews by rating                        " << std::endl;
        std::cout << "  8. Up/Downvote review                           " << std::endl;
        std::cout << "  9. Modify review                                " << std::endl;
        std::cout << "  10. Delete review                               " << std::endl;
        std::cout << "\n  -- Profile options --                         " << std::endl;
        std::cout << "  11. Edit Username                               " << std::endl;
        std::cout << "  12. Edit Email                                  " << std::endl;
        std::cout << "  13. Edit Password                               " << std::endl;
        std::cout << "  14. View/Add addresses                          " << std::endl;
        std::cout << "  15. View/Add payment options                    " << std::endl;
        std::cout << "  16. Logout                                      " << std::endl;
        std::cout << std::endl;
        opt = "";
        std::cout << "  Choose a valid option: "; std::cin >> opt;
        if (opt == "1") //Add product
        {
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  New product name: "; std::getline(std::cin >> std::ws, name);
            std::cout << "  Brief description: "; std::getline(std::cin >> std::ws, description);
            std::cout << "  Reference: "; std::cin >> reference;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Reference: "; std::cin >> reference;
            }
            std::cout << "  Price (in euros): "; std::cin >> price;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Price (in euros): "; std::cin >> price;
            }
            if (addProduct(name, description, reference, price) == true)
                std::cout << "\n  Product Added!" << std::endl;
            else
                std::cout << "\n  Invalid reference (already existing prod. reference?)" << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "2") //Show users
        {
            std::cout << "\n  USERS:" << std::endl;
            for (long unsigned int i = 0; i < getUsers().size(); i++)
                std::cout << "  " << i + 1 << ".-  Username: " <<  getUsers()[i]->getUsername() << " | Reputation = " << getUsers()[i]->getReputation() << std::endl;
            std::cout << std::endl;
            std::this_thread::sleep_for(g_timespan2);
        }
        else if (opt == "3") //Save to file
        {
            std::string fileAddress;
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  FileAddress? "; std::cin >> fileAddress;
            saveToFile(fileAddress);
        }
        else if(opt == "4") //Load from file
        {
            std::string fileAddress;
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  FileAddress? "; std::cin >> fileAddress;
            loadFromFile(fileAddress);
        }
        else if (opt == "5")  //Make order
        {
            clearscreen();
            headerLoggedAdmin();
            while (exitmakeorderMenu != 1)
                makeorderMenu();
            exitmakeorderMenu = 0;
        }
        else if (opt == "6") //Create review
        {
            clearscreen();
            headerLoggedAdmin();
            if (getCurrentUser()->getOrders().size() > 0)
            {
                std::cout << "\n*------------------------------------------------*" << std::endl;
                for (long unsigned int i = 0; i < getProducts().size(); i++)
                    std::cout << *getProducts()[i] << std::endl;
                std::cout << "*------------------------------------------------*" << std::endl;
                do
                {
                    std::cout << "\n  Select a valid index: "; std::cin >> index;
                }while (index > getProducts().size());
                do
                {
                    std::cout << "  Rating [0-5]: "; std::cin >> rating;
                    while (!std::cin.good())
                    {
                        std::cout << "  ERROR: Introduce numeric value\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "  Rating [0-5]: "; std::cin >> rating;
                    }
                }while ((rating < 0) && (rating > 5));
                std::cout << "  Introduce text: "; std::getline(std::cin >> std::ws, text);
                for (long unsigned int i = 0; i < getCurrentUser()->getOrders().size(); i++)
                {
                    for (long unsigned j = 0; j < getCurrentUser()->getOrders()[i]->getProducts().size(); j++)
                    {
                        if (getCurrentUser()->getOrders()[i]->getProducts()[j] == getProducts()[index - 1]->getReference())
                        {
                            createReview(getProducts()[index - 1]->getReference(), rating, text);
                            ex = 1;
                        }
                    }
                }
                if (ex == 0)
                {
                    std::cout << "  You have not bought this product yet.." << std::endl;
                    std::this_thread::sleep_for(g_timespan);
                }
            }
            else
            {
                std::cout << "  You have not bought any products yet.." << std::endl;
                std::this_thread::sleep_for(g_timespan);
            }
        }
        else if (opt == "7") //Get reviews by rating
        {
            clearscreen();
            headerLoggedAdmin();
            if (getProducts().size() > 0)
            {
                std::cout << "\n*------------------------------------------------*" << std::endl;
                for (long unsigned int i = 0; i < getProducts().size(); i++)
                    std::cout << *getProducts()[i] << std::endl;
                std::cout << "*------------------------------------------------*" << std::endl;
                do
                {
                    std::cout << "\n  Select a valid index: "; std::cin >> index;
                }while (index > getProducts().size());
                std::cout << "  Rating: "; std::cin >> rating;
                while (!std::cin.good())
                {
                    std::cout << "  ERROR: Introduce numeric value\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "  Rating: "; std::cin >> rating;
                }
                std::cout << "\n  REVIEWS: \n" << std::endl;
                for(long unsigned int i = 0; i < getReviewsByRating(getProducts()[index - 1]->getReference(), rating).size(); i++)
                {
                    std::cout << "  Id: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getId() << std::endl;
                    std::cout << "  Rating: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getRating() << std::endl;
                    std::cout << "  Text: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getText() << std::endl;
                    std::cout << "  Author: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getAuthor()->getUsername() << std::endl;
                    std::cout << "  Votes: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getVotes() << std::endl;
                    std::cout << "  Date: " << getReviewsByRating(getProducts()[index - 1]->getReference(), rating)[i]->getDate() << "\n" << std::endl;
                }
                std::this_thread::sleep_for(g_timespan2);
            }
            else
            {
                std::cout << "  No products online.." << std::endl;
                std::this_thread::sleep_for(g_timespan);
            }
        }
        else if (opt == "8") // Up/Downvote review
        {
            clearscreen();
            headerLoggedAdmin();
            while (exituodMenu != 1)
                uodMenu();
        }
        else if (opt == "9") //Modify review
        {
            clearscreen();
            headerLoggedAdmin();
            while (exitmodifyrevMenu != 1)
                modifyrevMenu();
        }
        else if (opt == "10") //Delete review
        {
            unsigned long id;
            int exfor = 0;
            clearscreen();
            headerLoggedUser();
            std::cout << "  Introduce review id: "; std::cin >> id;
            while (!std::cin.good())
            {
                std::cout << "  ERROR: Introduce numeric value\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "  Introduce review id: "; std::cin >> id;
            }
            for (long unsigned int i = 0; i < getProducts().size(); i++)
            {
                for (long unsigned int j = 0; j < getProducts()[i]->getReviews().size(); j++)
                {
                    if (id == getProducts()[i]->getReviews()[j]->getId())
                    {
                        deleteReview(id);
                        std::cout << "\n  Review deleted!" << std::endl;
                        exfor = 1;
                    }
                }
            }
            if (exfor == 0)
                std::cout << "\n  Review not found." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "11") //Edit Username
        {
            std::string username;
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  Introduce new USERNAME: "; std::cin >> username;
            if(editUsername(username) == true)
                std::cout << "\n  Successfully changed actual username." << std::endl;
            else
                std::cout << "\n  Error: Already existing username." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "12") //Edit Email
        {
            std::string email;
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  Introduce new EMAIL: "; std::cin >> email;
            if(editEmail(email) == true)
                std::cout << "\n  Successfully changed actual email." << std::endl;
            else
                std::cout << "\n  Error: Invalid email" << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "13") //Edit Password
        {
            std::string password;
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  Introduce new PASSWORD: "; std::cin >> password;
            editPassword(password);
            std::cout << "\n  Successfully changed actual password." << std::endl;
            std::this_thread::sleep_for(g_timespan);
        }
        else if (opt == "14") //View/edit addresses
        {
            clearscreen();
            headerLoggedAdmin();
            while (exitaddressMenu != 1)
                addressMenu();
            exitaddressMenu = 0;
        }
        else if (opt == "15") //View/edit payment options
        {
            clearscreen();
            headerLoggedAdmin();
            while (exitpaymentMenu != 1)
                paymentMenu();
            exitpaymentMenu = 0;
        }
        else if (opt == "16") //Logout
        {
            logout();
            exitAdminMenu = 1;
        }
    }
}

void    interface::inter()
{
    opt = "";
    exitMenu = 0;
    clearscreen();
    wellcome();
    if (IaddAdmin() == true)
    {
        while (exitMenu != 1)
            Menu();
    }
    else
    {
        clearscreen();
        header();
        std::cout << "\n  Try again later :-(\n" << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
    exit(0);
}

int main(void)
{
    interface i;
    i.inter();
    return (0);
}

