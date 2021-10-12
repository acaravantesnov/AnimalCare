#include "Interface.hpp"

void    header()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

void clearscreen() {system("clear");}

void welcome()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "| Welcome to AnimalCare!                         |" << std::endl;
    std::cout << "*------------------------------------------------*\n" << std::endl;
}

void    Ilogin(Manager* only_manager)
{
    std::string email, password;
    std::cout << "\n  Email: "; std::cin >> email;
    std::cout << "  Password: "; std::cin >> password;
    if (only_manager->login(email, password) == true)
        std::cout << "\n  Successful login!" << std::endl;
    else
        std::cout << "\n  Unsuccessful login :-(" << std::endl;
}

void options(Manager* only_manager)
{
    int opt;
    std::cout << "                                                  " << std::endl;
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
            exit(0);
    }
}

void    IaddAdmin(Manager* only_manager)
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
        std::cout << "\n Created Admin! " << std::endl;
    else
        std::cout << "\n Wrong Admin creation :-( " << std::endl;
}

void    interface(Manager* only_manager)
{
    clearscreen();
    welcome();
    IaddAdmin(only_manager);
    options(only_manager);
}

int main()
{
    Manager only_manager;
    Manager* ptr;
    ptr = &only_manager;
    interface(ptr);
    return (0);
}

