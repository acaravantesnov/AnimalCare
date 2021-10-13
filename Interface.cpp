#include "Interface.hpp"

interface::interface() {}

void    interface::header()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

void    interface::headerLoggedUser()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "--- USER ---" << std::endl;
    std::cout << "* UserName: " << getCurrentUser()->getUsername() << std::endl;
    std::cout << "* Email: " << getCurrentUser()->getEmail() << std::endl;
}

void    interface::headerLoggedAdmin()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "\t\t--- ADMIN ---" << std::endl;
    std::cout << "\t\t UserName: " << getCurrentUser()->getUsername() << std::endl;
    std::cout << "\t\t Email: " << getCurrentUser()->getEmail() << std::endl;
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

void    interface::Menu()
{
    useroradmin = 1;
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

    }
    else if (opt == "3")
    {
        clearscreen();
        exit(0);
    }
}

void    interface::adminMenu()
{
    int exitfct = 0;
    std::string name;
    std::string description;
    unsigned long reference;
    float price;
    while (exitfct != 1)
    {
        clearscreen();
        headerLoggedAdmin();
        std::cout << std::endl;
        std::cout << "  1. Add product                                  " << std::endl;
        std::cout << "  2. Show users                                   " << std::endl;
        std::cout << "  3. Make order                                   " << std::endl;
        std::cout << "  4. Create review                                " << std::endl;
        std::cout << "  5. Get reviews by rating                        " << std::endl;
        std::cout << "  6. Up/Downvote review                           " << std::endl;
        std::cout << "  7. Modify review                                " << std::endl;
        std::cout << "  8. Delete review                                " << std::endl;
        std::cout << "  9. Save to file                                 " << std::endl;
        std::cout << "  10. Load from file                              " << std::endl;
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
            if (addProduct(name, description, reference, price) == false)
                std::cout << "\nProduct Added!" << std::endl;
            else
                std::cout << "\n :-(" << std::endl;
        }
        else if (opt == "2") //Show users
        {
            clearscreen();
            headerLoggedAdmin();
            for (int i = 0; i < getUsers().size(); i++)
                std::cout << i << ".-  Username: " <<  getUsers()[i]->getUsername() << " | Reputation = " << getUsers()[i]->getReputation() << std::endl;
            exitfct = 0;
        }
        else if (opt == "3")  //Make order
        {
            makeOrder(getCurrentUser()->getOrders()[getCurrentUser()->getOrders().size() - 1]->getProducts(), getCurrentUser()->getAddresses()[getCurrentUser()->getAddresses().size() - 1]->getId(), getCurrentUser()->getPaymentOptions()[getCurrentUser()->getPaymentOptions().size() - 1]->getId());
        }
        else if (opt == "4")
        {

        }
        else if (opt == "5") {}
        else if (opt == "6") {}
        else if (opt == "7") {}
        else if (opt == "8") {}
        else if (opt == "9") {}
        else if (opt == "10") {}
        else if (opt == "11")
            exitfct = 1;
    }
}

void    interface::inter()
{
    opt = "";
    useroradmin = 1;
    int exitfct = 0;
    clearscreen();
    wellcome();
    if (IaddAdmin() == true)
    {
        useroradmin = 2;
        while (exitfct != 1)
        {
            Menu();
            exitfct = 0;
        }
    }
    exit(0);
}

int main()
{
    interface i;
    i.inter();
    return (0);
}

