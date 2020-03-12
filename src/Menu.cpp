#include "Menu.h"

Menu::Menu()
{
    //ctor
}

int Menu::menuPrincipal()
{
    int opc;

    cout << endl << "MENU PRINCIPAL" << endl;
    cout << "0.- Salir" << endl;
    cout << "1.- Alumnos" << endl;
    cout << "--> ";
    cin >> opc;

    return opc;
}

int Menu::menuAlumnos()
{
    int opc;

    cout << endl << "MENU ALUMNOS" << endl;
    cout << "0.- Salir" << endl;
    cout << "1.- Agregar" << endl;
    cout << "2.- Buscar" << endl;
    cout << "3.- Mostrar Todos" << endl;
    cout << "4.- Modificar" << endl;
    cout << "5.- Eliminar" << endl;
    cout << "--> ";
    cin >> opc;

    return opc;
}

Menu::~Menu()
{
    //dtor
}
