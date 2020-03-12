#include <iostream>

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu
{
    public:
        Menu();
        int menuPrincipal();
        int menuAlumnos();
        virtual ~Menu();
};

#endif // MENU_H
