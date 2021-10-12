#include "Interface.hpp"

void    header()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

void    headerLoggedUser(Manager* only_manager)
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "--- USER ---" << std::endl;
    std::cout << "* UserName: " << only_manager->getCurrentUser()->getUsername() << std::endl;
    std::cout << "* Email: " << only_manager->getCurrentUser()->getEmail() << std::endl;
}

void    headerLoggedAdmin(Manager* only_manager)
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
    std::cout << "--- ADMIN ---" << std::endl;
    std::cout << "* UserName: " << only_manager->getCurrentUser()->getUsername() << std::endl;
    std::cout << "* Email: " << only_manager->getCurrentUser()->getEmail() << std::endl;
}

void clearscreen() {system("clear");}

void welcome()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "| Welcome to AnimalCare!                         |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

bool    Ilogin(Manager* only_manager)
{
    std::string email, password;
    std::cout << "\n  Email: "; std::cin >> email;
    std::cout << "  Password: "; std::cin >> password;
    if (only_manager->login(email, password) == true)
    {
        std::cout << "\n  Successful login!" << std::endl;
        std::cout << "  Press any key to return to main menu." << std::endl;
        if (only_manager->getCurrentUser()->isAdmin() == true)
            adminMenu(only_manager);
        return (true);
    }
    else
    {
        std::cout << "\n  Unsuccessful login :-(" << std::endl;
        std::cout << "  Press any key to return to main menu." << std::endl;
    }
    return (false);
}

bool    IaddAdmin(Manager* only_manager)
{
    std::string username;
    std::string email;
    std::string password;
    unsigned long worker_id;
    std::cout << "\n  Username: "; std::cin >> username;
    std::cout << "  Email: "; std:: cin >> email;
    std::cout << "  Password: "; std::cin >> password;
    std::cout << "  Worker Id: ";  std::cin >> worker_id;
    if (only_manager->addAdmin(username, email, password, worker_id) == true)
    {
        std::cout << "\n Created Admin! " << std::endl;
        return (true);
    }
    else
        std::cout << "\n Wrong Admin creation :-( " << std::endl;
    return (false);
}

void    Menu(Manager* only_manager)
{
    clearscreen();
    welcome();
    int opt;
    std::cout << std::endl;
    std::cout << "  1. Login                                        " << std::endl;
    std::cout << "  2. Create an account                            " << std::endl;
    std::cout << "  3. Exit                                         " << std::endl;
    std::cout << "                                                  " << std::endl;
    std::cout << "  Choose a valid option: "; std::cin >> opt;
    switch (opt)
    {
        case 1:
            clearscreen();
            header();
            Ilogin(only_manager);
            break;
        case 2:
            break;
        case 3:
            clearscreen();
            exit(0);
            break;
    }
}

void    adminMenu(Manager* only_manager)
{
    int exitfct = 0;
    int opt;
    while (exitfct != 1)
    {
        headerLoggedAdmin(only_manager);
        std::cout << std::endl;
        std::cout << "  1. Add Product                                  " << std::endl;
        std::cout << "  2. Delete Product                               " << std::endl;
        std::cout << "  3. Exit                                         " << std::endl;
        std::cout << "                                                  " << std::endl;
        std::cout << "  Choose a valid option: "; std::cin >> opt;
    }
}

void    interface(Manager* only_manager)
{
    int exitfct = 0;
    clearscreen();
    welcome();
    if (IaddAdmin(only_manager) == true)
    {
        while (exitfct != 1)
        {
            Menu(only_manager);
            exitfct = 0;
        }
    }
    exit(0);
}

int main()
{
    Manager only_manager;
    Manager* ptr;
    ptr = &only_manager;
    interface(ptr);
    return (0);
}

