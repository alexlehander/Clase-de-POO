#include <iostream>
#include <string.h>
using namespace std;
class Persona {
public:
    Persona(string, int);
    ~Persona();
    void imprimeDatos();
    void creaPersona ();
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

void Persona::imprimeDatos()
{
 cout << "Nacio " << nombre;
}

Persona *creaPersona()
{
 Persona *p6= new Persona ("Mariano",75);          // objeto local automatico
 p6->imprimeDatos();
 cout << endl << p6 << endl;
 return p6;
}

int main()
 {
 Persona *a1;
 a1=creaPersona();
 cout << "Ya estamos aqui" << endl << a1;
 delete a1;
 return 0;
}
