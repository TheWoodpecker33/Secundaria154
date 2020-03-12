#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

#ifndef ALUMNOS_H
#define ALUMNOS_H

class Alumnos
{
    private:
        int codigo;
        int nss;
        string nombre;
        string apellidoPaterno;
        string apellidoMaterno;
    public:
        Alumnos();
        Alumnos(int,int,string,string,string);
        void cargarAlumno(string);
        string mostrarAlumno();
        string aArchivo();
        int getCodigo();
        int getNss();
        string getNombre();
        string getApellidoPaterno();
        string getApellidoMaterno();
        virtual ~Alumnos();
};

#endif // ALUMNOS_H
