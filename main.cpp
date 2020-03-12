#include <iostream>

#include "Alumnos.h"
#include "AdminArchivos.h"
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;
    AdminArchivos admin("alumnos");
    int opc = 33;
    while(opc!=0)
    {
        opc = menu.menuPrincipal();
        switch(opc)
        {
            case 1:
            {
                int opc1 = 33;
                while(opc1 != 0)
                {
                    opc1 = menu.menuAlumnos();
                    switch(opc1)
                    {
                        case 1:
                        {
                            int codigo, nss;
                            string nombre, apellido1, apellido2;
                            cout << "Ingrese el codigo del alumno: ";
                            cin >> codigo;
                            cout << "Ingrese el nss: ";
                            cin >> nss;
                            cout << "Ingrese el nombre: ";
                            cin >> nombre;
                            cout << "Ingrese el apellido paterno: ";
                            cin >> apellido1;
                            cout << "Ingrese el apellido materno: ";
                            cin >> apellido2;
                            Alumnos obj(codigo,nss,nombre,apellido1,apellido2);
                            admin.agregarAlumno(&obj);
                            break;
                        }
                        case 2:
                        {
                            int codigo;
                            cout << "Ingresa el codigo del alumnos a Buscar: ";
                            cin >> codigo;
                            if(admin.buscarAlumno(codigo))
                            {
                                cout << "Se encontro el alumno: " << endl;
                                cout << admin.mostrarAlumno(codigo) << endl;
                            }
                            else
                                cout << "No se encontro el alumno" << endl;
                            break;
                        }
                        case 3:
                        {
                            cout << admin.mostrarAlumnos() << endl;
                            break;
                        }
                        case 4:
                        {
                            int codigo,nss;
                            string nombre, ap1, ap2;
                            cout << "Ingresa el codigo del alumnos a modificar: ";
                            cin >> codigo;
                            if(admin.buscarAlumno(codigo))
                            {
                                cout << admin.mostrarAlumno(codigo) << endl;
                                cout << "---------------------------------" << endl;
                                cout << "Ingrese el nuevo nss: ";
                                cin >> nss;
                                cout << "Ingrese el nuevo Nombre: ";
                                cin >> nombre;
                                cout << "Ingrese el nuevo Apellido Paterno: ";
                                cin >> ap1;
                                cout << "Ingrese el nuevo Apellido Materno: ";
                                cin >> ap2;
                                Alumnos* obj = new Alumnos(codigo,nss,nombre,ap1,ap2);
                                admin.modificarAlumno(codigo,obj);
                            }
                            break;
                        }
                        case 5:
                        {
                            int codigo;
                            cout << "Ingrese el codigo del alumno a eliminar: ";
                            cin >> codigo;
                            admin.eliminarAlumno(codigo);
                            break;
                        }
                    }
                }
                break;
            }
            default:
            {
                cout << "Opcion Incorrecta" << endl;
                break;
            }
        }
    }
}
