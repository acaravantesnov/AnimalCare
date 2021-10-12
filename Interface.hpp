#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include <iostream>
# include "Manager.hpp"

void    header();
void    headerLoggedUser(Manager* only_manager);
void    headerLoggedAdmin(Manager* only_manager);
void    clearscreen();
bool    Ilogin(Manager* only_manager);
bool    IaddAdmin(Manager* only_manager);
void    Menu(Manager* only_manager);
void    adminMenu(Manager* only_manager);
void    interface(Manager* only_manager);

#endif // INTERFACE_HPP
