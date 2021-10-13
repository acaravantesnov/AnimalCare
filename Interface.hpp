#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include <iostream>
# include "Manager.hpp"
# include <string>

class interface : public Manager
{
    private:
        int useroradmin;
        std::string opt;
    public:
        interface();
        void    inter();
        void    wellcome();
        void    header();
        void    headerLoggedUser();
        void    headerLoggedAdmin();
        void    clearscreen();
        bool    Ilogin();
        bool    IaddAdmin();
        void    Menu();
        void    adminMenu();
};

#endif // INTERFACE_HPP
