#include "Alumnos.h"

Alumnos::Alumnos()
{
    codigo = 0;
    nss = 0;
    nombre = "";
    apellidoPaterno = "";
    apellidoMaterno = "";
}

Alumnos::Alumnos(int codigo,int nss,string nombre,string apellidoPaterno,string apellidoMaterno)
{
    this->codigo = codigo;
    this->nss = nss;
    this->nombre = nombre;
    this->apellidoPaterno = apellidoPaterno;
    this->apellidoMaterno = apellidoMaterno;
}

void Alumnos::cargarAlumno(string cadena)
{
    string aux;
    int cont = 0;
    for(int i = 0; i < cadena.length(); i++)
    {
        if(cadena[i] == '|')
        {
            if(cont == 0)
            {
                codigo = atoi(aux.c_str());
                aux = "";
                cont++;
                continue;
            }
            else if(cont == 1)
            {
                nss = atoi(aux.c_str());
                aux = "";
                cont++;
                continue;
            }
            else if(cont == 2)
            {
                nombre = aux;
                aux = "";
                cont++;
                continue;
            }
            else if(cont == 3)
            {
                apellidoPaterno = aux;
                aux = "";
                cont++;
                continue;
            }
            else if(cont == 4)
            {
                apellidoMaterno = aux;
                aux = "";
                cont++;
                continue;
            }
        }
        else
        {
            aux += cadena[i];
        }
    }
}

string Alumnos::mostrarAlumno()
{
    stringstream ss;

    ss << "Codigo: " << codigo << endl << "NSS: " << nss << endl << "Nombre: " << nombre << endl << "Apellido Paterno: " << apellidoPaterno << endl << "Apellido Materno: " << apellidoMaterno;

    return ss.str();
}

string Alumnos::aArchivo()
{
    stringstream ss;

    ss << codigo << "|" << nss << "|" << nombre << "|" << apellidoPaterno << "|" << apellidoMaterno << "|" ;

    return ss.str();
}

int Alumnos::getCodigo()
{
    return codigo;
}

int Alumnos::getNss()
{
    return nss;
}

string Alumnos::getNombre()
{
    return nombre;
}

string Alumnos::getApellidoPaterno()
{
    return apellidoPaterno;
}

string Alumnos::getApellidoMaterno()
{
    return apellidoMaterno;
}

Alumnos::~Alumnos()
{
    //dtor
}
