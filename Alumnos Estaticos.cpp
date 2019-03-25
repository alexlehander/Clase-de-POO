#include <iostream>
#include <string.h>
using namespace std;

class Fecha {
public:
    Fecha(int, int, int);
    void imprimeFecha() const;
    void actualizaFecha(int, int, int);
    ~Fecha();
private:
    int dia;
    int mes;
    int anio;
};

class Alumno {
public:
    Alumno(string, int, char, int, int, int);
    void imprimeDatos() const;
    void actualizaFechaNacimiento(int, int, int);
    static void imprimeDatosClase();
    ~Alumno();
private:
    string nombre;
    int edad;
    char genero;
    Fecha nacimiento;
    static int masc_alumnos;
    static int fem_alumnos;
    static float Promedio_Masc;
    static float Promedio_Fem;
};

int Alumno::masc_alumnos = 0;
int Alumno::fem_alumnos = 0;
float Alumno::Promedio_Masc = 0;
float Alumno::Promedio_Fem = 0;

Fecha::Fecha (int d, int m, int a) {
    dia  = d;
    mes  = m;
    anio = a;
    cout << "Se construyo un objeto fecha." << endl;
}

Fecha::~Fecha () {
    cout << "Se destruyo un objeto fecha." << endl;
}

void Fecha::imprimeFecha () const {
    cout << dia << "/" << mes << "/" << anio << endl;
}

void Fecha::actualizaFecha (int d, int m, int a) {
    dia  = d;
    mes  = m;
    anio = a;
}

Alumno::Alumno (string n, int e, char g, int d, int m, int a) : nacimiento (d, m, a) {
    nombre     = n;
    edad       = e;
    genero = g;
    if (genero=='m') masc_alumnos++;
    if (genero=='f') fem_alumnos++;
    if (genero=='m') Promedio_Masc=(Promedio_Masc+edad);
    if (genero=='f') Promedio_Fem=(Promedio_Fem+edad);
    cout << "Se construyo un objeto alumno." << endl;
}

Alumno::~Alumno () {
    if (genero=='m') masc_alumnos--;
    if (genero=='f') fem_alumnos--;
    if (genero=='m') Promedio_Masc=(Promedio_Masc-edad);
    if (genero=='f') Promedio_Fem=(Promedio_Fem-edad);
    imprimeDatos();
    cout << "Se destruyo un objeto alumno." << endl;
}

void Alumno::imprimeDatos () const {
     cout << endl << "Nombre:              " << nombre << endl;
     cout << "Edad:                " << edad << endl;
     cout << "Genero:                " << genero << endl;
     cout << "Fecha de nacimiento: ";
     nacimiento.imprimeFecha();
     cout << "Alumnos registrados: " << masc_alumnos+fem_alumnos << endl;
     cout << "Hombres registrados: " << masc_alumnos << endl;
     cout << "Mujeres registradas: " << fem_alumnos << endl;
     cout << "Promedio Femenino: " << Promedio_Fem/fem_alumnos << endl;
     cout << "Promedio Masculino: " << Promedio_Masc/masc_alumnos << endl;
     cout << "Promedio General: " << (Promedio_Fem/fem_alumnos+Promedio_Masc/masc_alumnos)/2 << endl;
}

void Alumno::imprimeDatosClase () {
     cout << "Alumnos registrados: " << masc_alumnos+fem_alumnos << endl << endl;
     cout << "Alumnos hombres: " << masc_alumnos << endl << endl;
     cout << "Alumnos mujeres: " << fem_alumnos << endl << endl;
     cout << "Promedio general: " << (Promedio_Fem/fem_alumnos+Promedio_Masc/masc_alumnos)/2 << endl << endl;
     cout << "Promedio hombres: " << Promedio_Masc << endl << endl;
     cout << "Promedio mujeres: " << Promedio_Fem << endl << endl;
}

void Alumno::actualizaFechaNacimiento (int d, int m, int a) {
    nacimiento.actualizaFecha(d,m,a);
}

int main () {
     Alumno::imprimeDatosClase();
     Alumno a1("Pedro", 13, 'm', 15,12,2000);
     a1.imprimeDatos();
     cout << endl;
     Alumno a2("Anna",19, 'f', 12,01,1995);
     a2.imprimeDatos();
     cout << endl;
     Alumno a3("Ivan",20, 'm', 20,03,1991);
     a3.imprimeDatos();
     cout << endl;
     Alumno a4("Sonia",30, 'f', 05,10,2000);
     a4.imprimeDatos();
     cout << endl;
}
