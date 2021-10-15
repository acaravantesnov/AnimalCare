#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include <iostream>
# include "Manager.hpp"
# include <string>
# include <chrono>
# include <thread>

std::chrono::milliseconds g_timespan(1500);
std::chrono::milliseconds g_timespan2(3000);
std::chrono::milliseconds g_timespan3(5000);


class interface : public Manager
{
    private:
        std::string opt;
        int exitMenu = 0;
        int exitAdminMenu = 0;
        int exitUserMenu = 0;
        int exitorderMenu = 0;
        int exituodMenu = 0;
        int exitmodifyrevMenu = 0;
        int exitaddressMenu = 0;
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
        bool    Icreateacc();
        void    userMenu();
        void    orderMenu(int _address, int _payment);
        void    uodMenu();
        void    modifyrevMenu();
        void    addressMenu();
};

#endif // INTERFACE_HPP
