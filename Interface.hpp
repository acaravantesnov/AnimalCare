#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include "Manager.hpp"
# include <iostream>
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
        std::vector<unsigned long> worker_ids;
        int exitMenu = 0;
        int exitAdminMenu = 0;
        int exitUserMenu = 0;
        int exitorderMenu = 0;
        int exituodMenu = 0;
        int exitmodifyrevMenu = 0;
        int exitaddressMenu = 0;
        int exitpaymentMenu = 0;
        int exitmakeorderMenu = 0;
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
        void    paymentMenu();
        void    makeorderMenu();
        std::vector<unsigned long> &getWorker_Ids();
        unsigned long getCurrentWorker_Id();
};

#endif // INTERFACE_HPP
