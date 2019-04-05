#include <iostream>
#include <string.h>
using namespace std;

class Alumno;
class Carrera;
class Fecha;

class Fecha {
friend class Alumno;
public:
    Fecha (int, int, int);
    void imprimeFecha () const;
    ~Fecha ();
private:
    int dia;
    int mes;
    int anio;
};

class Carrera {
friend void asignaCarrera (Alumno &, Carrera &);
public:
	Carrera (string, string);
	void imprimeDatos () const;
	~Carrera ();
private:
	string nombre;
	string facultad;
};

class Alumno {
friend void imprimeAlumno (Alumno &);
friend void setAlumno (Alumno&, string);
friend void asignaCarrera (Alumno &, Carrera &);
public:
    Alumno (string, int, string,  int, int, int);
    void imprimeDatos () const;
    ~Alumno ();
private:
    string nombre;
    int edad;
    string especialidad;
    Fecha nacimiento;
};

Fecha::Fecha (int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
    cout << "Se construyo un objeto fecha" << endl;
}

Fecha::~Fecha () {
    cout << "Se destruyo un objeto fecha" << endl;
}

Alumno::Alumno (string n, int e, string x, int d, int m, int a) : nacimiento(d, m, a) {
    nombre = n;
    edad = e;
    especialidad = x;
    cout << "Se construyo un objeto alumno" << endl;
}

Alumno::~Alumno () {
    cout << "Se destruyo un objeto alumno" << endl;
}

Carrera::Carrera (string x, string y) {
	nombre = x;
	facultad = y;
	cout << "Se construyo un objeto carrera" << endl;
}

Carrera::~Carrera () {
    cout << "Se destruyo un objeto carrera" << endl;
}

void Fecha::imprimeFecha () const {
 cout << dia << "/" << mes << "/" << anio << endl;
}

void Alumno::imprimeDatos () const {
 cout << endl << "Nombre:              " << nombre << endl;
 cout <<         "Edad:                " << edad << endl;
 cout <<         "Carrera:             " << especialidad << endl;
 cout <<         "Fecha de nacimiento: ";
 nacimiento.imprimeFecha();
}

void imprimeAlumno (Alumno &a) {
    cout << endl << "Nombre:              " << a.nombre << endl;
    cout <<         "Edad:                " << a.edad << endl;
    cout <<         "Carrera:             " << a.especialidad << endl;
    cout <<         "Fecha de nacimiento: ";
    a.nacimiento.imprimeFecha();
    cout << "Se imprimen datos por metodo friend" << endl;
}

void setAlumno (Alumno &a, string b) {
	a.nombre = b;
	cout << endl << "Dame la nueva edad de tu alumno" << endl;
	cin >> a.edad;
}

void asignaCarrera (Alumno &a, Carrera &b) {
	a.especialidad = b.nombre;
	cout << "Tu especialidad fue cambiada" << endl;
	imprimeAlumno (a);	
}

int main() {
    Alumno a1("Pedro",13, "Programacion", 15,12,2000);
    Carrera b1("Matematicas", "Ciencias");
    a1.imprimeDatos();
    setAlumno (a1, "Ana");
    asignaCarrera (a1, b1);
    cout << endl;
}

