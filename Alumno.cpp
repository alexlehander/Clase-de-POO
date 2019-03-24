// Programa que declara la clase Alumno
// 26 de enero de 2019
// Omar Álvarez X.
#include <iostream>
#include <string.h>

using namespace std;

class Alumno
{public:
    char nombre[15];
    void actualizaDatos(char[], int);
    void imprimeDatos();
 private:
    int edad;
};

//Asigna un nuevo valor a las variables
void Alumno::actualizaDatos(char n[], int e)
{
 strcpy(nombre,n);
 edad = e;
}

//Imprime datos del alumno
void Alumno::imprimeDatos()
{
 cout << "Nombre: " << nombre << endl;
 cout << "Edad:   " << edad   << endl;
}

int main()
{
 Alumno a;
 Alumno *ptrA = &a;
 Alumno &refA = a;

 a.actualizaDatos("Ana", 18);
 a.imprimeDatos();
 cout << endl;
 strcpy(refA.nombre,"Juan");
 ptrA->imprimeDatos();

 return 0;
}


