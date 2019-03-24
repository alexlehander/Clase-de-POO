// Programa que declara la clase Alumno compuesta del objeto Fecha
// 19 de marzo de 2018
// Omar Álvarez X.
#include <iostream>
#include <string.h>
using namespace std;

class Fecha
{public:
    Fecha(int, int, int);
    void imprimeFecha() const;
    ~Fecha();
 private:
    int dia;
    int mes;
    int anio;
};

class Alumno
{public:
    Alumno(string, int, int, int, int);
    void imprimeDatos() const;
    ~Alumno();
 private:
    string nombre;
    int edad;
    Fecha nacimiento;   //Declaracion objeto tipo Fecha
};

// Definición de métodos
Fecha::Fecha(int d, int m, int a)
{
    dia  = d;
    mes  = m;
    anio = a;
    cout << "Se construyo un objeto fecha." << endl;
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

int main()
{
 Alumno a1("Pedro",13,15,12,2000);
 a1.imprimeDatos();
// a1.nacimiento.imprimeFecha();
 cout << endl;

 return 0;
}


