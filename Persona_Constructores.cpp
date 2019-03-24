// Programa que declara la clase Alumno
// 26 de febrero de 2017
// Omar Álvarez X.
#include <iostream>
#include <string.h>
using namespace std;

class Persona
{public:
    Persona();
    Persona(string, int);
    Persona(int, string);
    void imprimeDatos();
 private:
    string nombre;
    int edad;
};

Persona::Persona()
{
    nombre = "Maria";
    edad = 85;
    cout << "metodo 1" << endl;
}

Persona::Persona(string n, int e=0)
{
    nombre = n;
    edad = e;
    cout << "metodo 2" << endl;
}

Persona::Persona(int e, string n="------")
{
    nombre = n;
    edad = e;
    cout << "metodo 3" << endl;
}
//Imprime datos del alumno
void Persona::imprimeDatos()
{
 cout << "Nombre: " << nombre << endl;
 cout << "Edad:   " << edad << endl;
}

int main()
{
 Persona p1(25);
 p1.imprimeDatos();
 cout << endl;
 Persona p2("Pedro",20);
 p2.imprimeDatos();
 cout << endl;
 Persona p5(20,"Pedro");
 p5.imprimeDatos();
 cout << endl;
 Persona p3("Ana");
 p3.imprimeDatos();
 cout << endl;
 Persona p4;
 p4.imprimeDatos();

 return 0;
}


