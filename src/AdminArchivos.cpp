#include "AdminArchivos.h"

AdminArchivos::AdminArchivos()
{

}

AdminArchivos::AdminArchivos(string nombre)
{
    archivo = nombre;
}

void AdminArchivos::agregarAlumno(Alumnos* obj)
{
    fout.open(archivo, ios::app);
    fout << obj->aArchivo() << endl;
    fout.close();
}

void AdminArchivos::modificarAlumno(int codigo, Alumnos* nuevo)
{
    string ss;
    fout.open("alumnos-aux",ios::app);
    fin.open(archivo);

    if(fin.is_open())
    {
        Alumnos obj;
        getline(fin, ss);
        while(!fin.eof())
        {
            obj.cargarAlumno(ss);
            if(obj.getCodigo() == codigo)
            {
                fout << nuevo->aArchivo() << endl;
            }
            else
            {
                fout << obj.aArchivo() << endl;
            }
            getline(fin, ss);
        }
    }

    fin.close();
    fout.close();
    remove(archivo.c_str());
    rename("alumnos-aux",archivo.c_str());
}

void AdminArchivos::eliminarAlumno(int codigo)
{
    string ss;
    fout.open("alumnos-aux",ios::app);
    fin.open(archivo);

    if(fin.is_open())
    {
        Alumnos obj;
        getline(fin, ss);
        while(!fin.eof())
        {
            obj.cargarAlumno(ss);
            if(obj.getCodigo() == codigo)
            {

            }
            else
            {
                fout << obj.aArchivo() << endl;
            }
            getline(fin, ss);
        }
    }

    fin.close();
    fout.close();
    remove(archivo.c_str());
    rename("alumnos-aux",archivo.c_str());

}

bool AdminArchivos::buscarAlumno(int codigo)
{
    string ss;
    fin.open(archivo);

    if(fin.is_open())
    {
        Alumnos obj;
        getline(fin, ss);
        while(!fin.eof())
        {
            obj.cargarAlumno(ss);
            if(obj.getCodigo() == codigo)
            {
                fin.close();
                return true;
            }
            getline(fin, ss);
        }
        fin.close();
        return false;
    }

    fin.close();
    return false;
}

string AdminArchivos::mostrarAlumnos()
{
    fin.open(archivo);

    if(fin.is_open())
    {
        Alumnos obj;
        string ss;
        getline(fin, ss);
        while(!fin.eof())
        {
            obj.cargarAlumno(ss);
            cout << obj.mostrarAlumno() << endl;
            getline(fin, ss);
        }
        fin.close();
        return ss;
    }

    fin.close();
    return "No hay alumnos";
}

string AdminArchivos::mostrarAlumno(int codigo)
{
    string ss;
    fin.open(archivo);

    if(fin.is_open())
    {
        Alumnos obj;
        getline(fin, ss);
        while(!fin.eof())
        {
            obj.cargarAlumno(ss);
            if(obj.getCodigo() == codigo)
            {
                fin.close();
                return obj.mostrarAlumno();
            }
            getline(fin, ss);
        }
        fin.close();
        return "";
    }

    fin.close();
    return "";
}

AdminArchivos::~AdminArchivos()
{
    //dtor
}
