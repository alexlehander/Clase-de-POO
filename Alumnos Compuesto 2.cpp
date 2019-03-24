// Programa que declara la clase Alumno compuesta del objeto Fecha
// 19 de marzo de 2014
// Omar Álvarez X.
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

class Titu {
public:
    Titu (string);
    void captura () const;
    void actualizaFechaGrado (int, int, int);
    ~Titu();
private:
    string tipo;
};

class Alumno {
public:
    Alumno(string, int, int, int, int);
    void imprimeDatos() const;
    void actualizaFechaNacimiento(int, int, int);
    ~Alumno();
 private:
    string nombre;
    int edad;
    Fecha nacimiento; //Declaracion objeto tipo Fecha
    Titu datos; //Declaracion objeto tipo Titulacion
};


// Definición de métodos
Fecha::Fecha(int d, int m, int a)
{
    dia  = d;
    mes  = m;
    anio = a;
    cout << "Se construyo un objeto fecha." << endl;
}

Titu::Titu(string a)
{
    tipo = '0';
    cout << "Se construyo un objeto Titulacion." << endl;
}

Fecha::~Fecha()
{
    cout << "Se destruyo un objeto fecha." << endl;
}

//Imprime Fecha
void Fecha::imprimeFecha() const
{
 cout << dia << "/" << mes << "/" << anio << endl;
}

void Fecha::actualizaFecha(int d, int m, int a)
{
    dia  = d;
    mes  = m;
    anio = a;
}

Alumno::Alumno(string n, int e, int d, int m, int a)
       : nacimiento(d, m, a)
{
    nombre     = n;
    edad       = e;
    cout << "Se construyo un objeto alumno." << endl;
}

Alumno::~Alumno()
{
    cout << "Se destruyo un objeto alumno." << endl;
}

void Alumno::imprimeDatos() const
{
 cout << endl;
 cout << "Nombre:              " << nombre << endl;
 cout << "Edad:                " << edad << endl;
 cout << "Fecha de nacimiento: ";
 nacimiento.imprimeFecha();
}

void Alumno::actualizaFechaNacimiento(int d, int m, int a)
{
    nacimiento.actualizaFecha(d,m,a);
}


int main()
{
 Alumno a1("Pedro",13,15,12,2000);
 a1.imprimeDatos();
 a1.actualizaFechaNacimiento(12,10,2000);
 a1.imprimeDatos();
 cout << endl;

 return 0;
}


