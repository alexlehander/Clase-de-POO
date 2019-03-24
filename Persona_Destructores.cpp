// Programa que declara la clase Alumno y destructores
// 17 de febrero de 2017
// Omar Álvarez X.
#include <iostream>
#include <string.h>
using namespace std;

class Persona
{public:
    Persona(string, int);
    ~Persona();
    void imprimeDatos();
 private:
    string nombre;
    int edad;
};

Persona::Persona(string n="------", int e=0)
{   nombre = n;
    edad = e;
}

Persona::~Persona()
{
    cout << endl << "Murio " << nombre << " a sus " << edad << " anios." << endl;
}

//Imprime datos del alumno
void Persona::imprimeDatos()
{
 cout << "Nacio " << nombre << endl;
}

void creaPersona()
{
 Persona p6("Mariano",75);          // objeto local automatico
 p6.imprimeDatos();
}

 Persona p1("Antonio",80);          // objeto global
 static Persona p5("Antonieta",80); // objeto global

int main()
{p1.imprimeDatos();
 cout << endl;
 p5.imprimeDatos();
 cout << endl;
 Persona p2("Maria",85);         // objeto local automatico
 p2.imprimeDatos();
 cout << endl;
 static Persona p3("Pedro",20);  // objeto local estatico
 p3.imprimeDatos();
 cout << endl;
 creaPersona();
 cout << endl;
 Persona p4("Ana",54);           // objeto local automatico
 p4.imprimeDatos();
 cout << endl;

 return 0;
}


