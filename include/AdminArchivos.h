#include <fstream>
#include <string>


#include <iostream> //////// Borrrrarrrr //////////


#include "Alumnos.h"

using namespace std;

#ifndef ADMINARCHIVOS_H
#define ADMINARCHIVOS_H

class AdminArchivos
{
    private:
        ifstream fin;
        ofstream fout;
        string archivo;
    public:
        AdminArchivos();
        AdminArchivos(string);
        void agregarAlumno(Alumnos*);
        void modificarAlumno(int,Alumnos*);
        void eliminarAlumno(int);
        bool buscarAlumno(int);
        string mostrarAlumno(int);
        string mostrarAlumnos();
        virtual ~AdminArchivos();
};

#endif // ADMINARCHIVOS_H
