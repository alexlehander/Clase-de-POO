#include <iostream>
#include <string.h>
using namespace std;

class Suprema {
public:
	Suprema(string);
	~Suprema();
	void imprimeDatos() const;
	void actualizaDatos(string);
    string estado; 
};

class Persona : public Suprema{
public:
    Persona(string, string, int, char);
    void imprimeDatos() const;
    void actualizaDatos(string, int, char);
    ~Persona();
//protected:
    string nombre;
    int    edad;
    char   genero;
};

class Alienigena : public Suprema{
public:
    Alienigena(string, string);
    void imprimeDatos() const;
    void actualizaDatos(string);
    ~Alienigena();
//protected:
    string galaxia;
};

class SuperHeroe : public Persona, public Alienigena {
public:
    SuperHeroe(string, string, string, string, int, char, string, string);
    void imprimeDatos() const;
    void actualizaDatos(string, string);
    ~SuperHeroe();
//private:
    string poder;
    string debilidad;
};

Suprema::Suprema(string a) {
    estado  = a;
    cout << "Se construyo un objeto Suprema" << endl;
}

Persona::Persona(string a, string n, int e, char g) : Suprema (a) {
    nombre  = n;
    edad    = e;
    genero  = g;
    cout << "Se construyo un objeto PERSONA." << endl;
}

Alienigena::Alienigena(string a, string g) : Suprema (a) {
    galaxia   = g;
    cout << "Se construyo un objeto ALIENIGENA." << endl;
}

SuperHeroe::SuperHeroe(string a, string b, string c, string d, int e, char f, string x, string z)
       : Persona(c, d, e, f), Alienigena(a,b) {
    poder       = x;
    debilidad   = z;
    cout << "Se construyo un objeto SuperHeroe." << endl;
}

Alienigena::~Alienigena() {
    cout << "Se destruyo un objeto ALIENIGENA." << endl;
}

Persona::~Persona() {
    cout << "Se destruyo un objeto PERSONA." << endl;
}

SuperHeroe::~SuperHeroe() {
    cout << "Se destruyo un objeto SuperHeroe." << endl;
}

Suprema::~Suprema() {
    cout << "Se destruyo un objeto Suprema." << endl;
}

void SuperHeroe::imprimeDatos() const {
 Persona::imprimeDatos();
 Alienigena::imprimeDatos();
 cout << "Poder:       " << poder      << endl;
 cout << "Debilidad:   " << debilidad << endl;
 cout << "Estado_A:    " << nombre << endl;
 cout << "Estado_P:    " << galaxia << endl;

}

void Persona::imprimeDatos() const {
Suprema::imprimeDatos();
 cout << "Nombre:      " << nombre << endl;
 cout << "Edad:        " << edad   << endl;
 cout << "Genero:      " << genero << endl << endl;
}

void Suprema::imprimeDatos() const {
 cout << "Estado:      " << estado      << endl << endl;
}

void Alienigena::imprimeDatos() const {
Suprema::imprimeDatos();
 cout << "Galaxia:     " << galaxia  << endl << endl;
}

void SuperHeroe::actualizaDatos(string p, string d) {
    poder      = p;
    debilidad  = d;
}

void Suprema::actualizaDatos(string a) {
    estado      = a;
}

void Alienigena::actualizaDatos(string g) {
    galaxia  = g;
}

void Persona::actualizaDatos(string n, int e, char g) {
    nombre  = n;
    edad    = e;
    genero  = g;
}


int main() {
	Suprema b1("Materia");
	b1.imprimeDatos();
    Persona p1("Materia","Ana",21,'F');
    p1.imprimeDatos();
    cout << endl;
    Alienigena a1("Incorporea","Andromeda I");
    a1.imprimeDatos();
    cout << endl;
    SuperHeroe s1("Incorporea","Andromeda", "Materia","Ana",21,'F',"Vuela","Criptonita");
    s1.imprimeDatos();
    cout << endl;
    s1.Alienigena::estado="Ambiguo";
    cout << s1.Persona::estado << endl;
    cout << s1.Alienigena::estado << endl;
}


