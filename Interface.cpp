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
        std::cout << "  Press any key to return to main menu." << std::endl;
        if (getCurrentUser()->isAdmin() == true)
            adminMenu();
        else
            userMenu();
        return (true);
    }
    else
    {
        std::cout << "\n  Unsuccessful login :-(" << std::endl;
        std::cout << "  Press any key to return to main menu." << std::endl;
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
    std::cout << "  Password: "; std::cin >> password;
    std::cout << "  Worker Id: ";  std::cin >> worker_id;
    if (addAdmin(username, email, password, worker_id) == true)
    {
        std::cout << "\n Created Admin! " << std::endl;
        return (true);
    }
    else
        std::cout << "\n Wrong Admin creation :-( " << std::endl;
    return (false);
}

void    interface::Icreateacc()
{
    std::string username, email, password;
    std::cout << "  Username: "; std::cin >> username;
    std::cout << "  Email: "; std:: cin >> email;
    std::cout << "  Password: "; std::cin >> password;
    addUser(username, email, password);
}

void    interface::orderMenu()
{
    int prod = 0;
    std::cout << "\n  1. Add product" << std::endl;
    std::cout << "  2. Make order" << std::endl;
    std::cout << "  3. Exit" << std::endl;
    std::cout << "\n  Select a valid option: "; std::cin >> opt;
    if (opt == "1")
    {
        std::cout << "\n  Which product? "; std::cin >> prod;
        if (getProducts().size() >= 1)
            getCurrentUser()->getOrders().back()->addProduct(getProducts()[prod - 1]->getReference());
        else
            std::cout << "  There are no products available!" << std::endl;
    }
    else if (opt == "2")
    {
        if (getCurrentUser()->getOrders().back()->getProducts().size() != 0)
        {
            makeOrder(getCurrentUser()->getOrders().back()->getProducts(), getCurrentUser()->getAddresses().back()->getId(), getCurrentUser()->getPaymentOptions().back()->getId());
                std::cout << "  Order made!" << std::endl;
        }
        else
            std::cout << "No products on cart, try again later!" << std::endl;
        std::this_thread::sleep_for(g_timespan);
    }
    else if (opt == "3")
        exitorderMenu = 1;
}

void    interface::userMenu()
{
    unsigned long reference;
    int rating;
    std::string text;
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
        std::cout << "  7. Exit                                         " << std::endl;
        std::cout << std::endl;
        opt = "";
        std::cin.clear();
        std::cout << "  Choose a valid option: "; std::cin >> opt;
        if (opt == "1") //Make order
        {
            clearscreen();
            headerLoggedUser();
            std::cout << "*---------------------------------------------*" << std::endl;
            for (long unsigned int i = 0; i < getProducts().size(); i++)
                std::cout << "  " << i + 1 << ".-  " << getProducts()[i]->getName() <<
                " " << getProducts()[i]->getReference() << " " << getProducts()[i]->getPrice() << std::endl;
            std::cout << "*---------------------------------------------*" << std::endl;
            std::this_thread::sleep_for(g_timespan);
            while(exitorderMenu != 1)
                orderMenu();
        }
        else if (opt == "2") //Create review
        {
            clearscreen();
            headerLoggedUser();
            std::cout << "\n  Product reference: "; std::cin >> reference;
            while ((rating < 0) && (rating > 5))
                std::cout << "  Rating [0-5]: "; std::cin >> rating;
            std::cout << "  Introduce text:\n"; std::cin >> text;
            createReview(reference, rating, text);
        }
        else if (opt == "3")  //Get reviews
        {
        }
        else if (opt == "4") //Up/downvote review
        {

        }
        else if (opt == "5") //Modify review
        {

        }
        else if (opt == "6") //Delete review
        {

        }
        else if (opt == "7") //Exit
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

void    interface::adminMenu()
{
    exitAdminMenu = 0;
    std::string name;
    std::string description;
    unsigned long reference;
    int rating = -1;
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
        std::cout << "  4. Load from file                              " << std::endl;
        std::cout << "\n- User commands:                                  " << std::endl;
        std::cout << "  5. Make order                                   " << std::endl;
        std::cout << "  6. Create review                                " << std::endl;
        std::cout << "  7. Get reviews by rating                        " << std::endl;
        std::cout << "  8. Up/Downvote review                           " << std::endl;
        std::cout << "  9. Modify review                                " << std::endl;
        std::cout << "  10. Delete review                                " << std::endl;
        std::cout << "  11. Exit                                        " << std::endl;
        std::cout << std::endl;
        opt = "";
        std::cout << "  Choose a valid option: "; std::cin >> opt;
        if (opt == "1") //Add product
        {
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  New product name: "; std::cin >> name;
            std::cout << "  Brief description: "; std::cin >> description;
            std::cout << "  Reference: "; std::cin >> reference;
            std::cout << "  Price (in euros): "; std::cin >> price;
            if (addProduct(name, description, reference, price) == true)
                std::cout << "\nProduct Added!" << std::endl;
            else
                std::cout << "\n :-(" << std::endl;
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

        }
        else if (opt == "5")  //Make order
        {
            clearscreen();
            headerLoggedAdmin();
            std::cout << "*------------------------------------------------*" << std::endl;
            for (long unsigned int i = 0; i < getProducts().size(); i++)
                std::cout << "  " << i + 1 << ".-  " << getProducts()[i]->getName() << " " << getProducts()[i]->getReference() << " " << getProducts()[i]->getPrice() << std::endl;
            std::cout << "*------------------------------------------------*" << std::endl;
            std::this_thread::sleep_for(g_timespan);
            while(exitorderMenu != 1)
                orderMenu();
        }
        else if (opt == "6") //Create review
        {
            clearscreen();
            headerLoggedAdmin();
            std::cout << "\n  Product reference: "; std::cin >> reference;
            while ((rating < 0) && (rating > 5))
                std::cout << "  Rating [0-5]: "; std::cin >> rating;
            std::cout << "  Introduce text:\n"; std::cin >> text;
            createReview(reference, rating, text);
        }
        else if (opt == "7") {}
        else if (opt == "8") {}
        else if (opt == "9") {}
        else if (opt == "10") {}
        else if (opt == "11")
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
    exit(0);
}

int main()
{
    interface i;
    i.inter();
    return (0);
}

