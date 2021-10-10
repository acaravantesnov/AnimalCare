/*#include "Interface.hpp"

void    header()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "|                  AnimalCare                    |" << std::endl;
    std::cout << "*------------------------------------------------*" << std::endl;
}

void clearscreen() {system("clear");}

void welcome()
{
    std::cout << "*------------------------------------------------*" << std::endl;
    std::cout << "| Welcome to AnimalCare!                         |" << std::endl;
    std::cout << "*------------------------------------------------*" << std::endl;
}

void    login()
{
    std::cout << "                                                  " << std::endl;
    std::cout << " Username: " << User::setUsername(std::cin);
    std::cout << " Password: " << User::setPassword(std::cin);
}

void options()
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
            login();
            break;
        case 2:
            break;
        case 3:
            exit(0);
    }
}

void    interface()
{
    clearscreen();
    welcome();
    options();
    login();
}

int main()
{
    interface();
    return (0);
}
*/
