#include <iostream>
#include <string.h>
using namespace std;

class Persona {
public:
    Persona(string, int, char);
    void imprimeDatos() const;
    void actualizaDatos(string, int, char);
    ~Persona();
    static void imprime();
private:
    string nombre;
    int    edad;
    char   genero;
    static int personas;
};

class Alumno : public Persona {
public:
    Alumno(string, int, char, string, int, string);
    void imprimeDatos() const;
    void actualizaDatos(string, int, string);
    ~Alumno();
    static int alumnos;
private:
    string matricula;
    int semestre;
    string carrera;
};

class Profesor : public Persona {
public:
    Profesor(string, int, char, string, int, string);
    void imprimeDatos() const;
    void actualizaDatos(string, int, string);
    ~Profesor();
    static int profesores;
private:
    string clave;
    int antiguedad;
    string especialidad;
};

int Persona::personas = 0;
int Alumno::alumnos = 0;
int Profesor::profesores = 0;

Persona::Persona (string n, int e, char g) {
    nombre  = n;
    edad    = e;
    genero  = g;
    cout << "Se construyo un objeto persona." << endl;
    personas++;
}

Alumno::Alumno (string n, int e, char g, string m, int s, string c) : Persona(n, e, g) {
    matricula = m;
    semestre = s;
    carrera = c;
    cout << "Se construyo un objeto alumno." << endl;
    alumnos++;
}

Profesor::Profesor (string n, int e, char g, string m, int s, string c) : Persona (n, e, g) {
    clave = m;
    antiguedad = s;
    especialidad = c;
    cout << "Se construyo un objeto profesor." << endl;
    profesores++;
}

void Persona::imprimeDatos () const {
    cout << endl << "Nombre: " << nombre << endl;
    cout <<         "Edad:   " << edad << endl;
    cout <<         "Genero: " << genero << endl << endl;
}

void Persona::actualizaDatos (string n, int e, char g) {
    nombre = n;
    edad = e;
    genero = g;
}

Profesor::~Profesor () {
	profesores--;
    cout << "Se destruyo un objeto profesor." << endl;
    imprimeDatos ();
}

Alumno::~Alumno () {
	alumnos--;
    cout << "Se destruyo un objeto alumno." << endl;
    imprimeDatos ();
}

Persona::~Persona () {
	personas--;
    cout << endl << "Se destruyo un objeto persona." << endl;
    imprimeDatos ();
}

void Alumno::imprimeDatos () const {
    Persona::imprimeDatos();
    cout << "Matricula: " << matricula << endl;
    cout << "Semestre:  " << semestre << endl;
    cout << "Carrera:   " << carrera << endl << endl;
    cout << "Todos:     " << alumnos+Profesor::profesores << endl;
    cout << "Alumnos:   " << alumnos << endl;
    cout << "Profesores:" << Profesor::profesores << endl;
}

void Profesor::imprimeDatos () const {
    Persona::imprimeDatos();
    cout << "Clave:       " << clave << endl;
    cout << "Antiguedad:  " << antiguedad << endl;
    cout << "Especialidad:" << especialidad << endl << endl;
    cout << "Todos:       " << profesores+Alumno::alumnos << endl;
    cout << "Profesores:  " << profesores << endl;
    cout << "Alumnos:     " << Alumno::alumnos << endl;
}

void Alumno::actualizaDatos (string m, int s, string c) {
    matricula = m;
    semestre = s;
    carrera = c;
}

void Profesor::actualizaDatos (string m, int s, string c) {
    clave = m;
    antiguedad = s;
    especialidad = c;
}

void Persona::imprime () {
    cout << "Todos:       " << Profesor::profesores+Alumno::alumnos << endl;
    cout << "Profesores:  " << Profesor::profesores << endl;
    cout << "Alumnos:     " << Alumno::alumnos << endl << endl;
}

int main () {
	Persona::imprime();
    Persona p1("Ana",21,'F');
    p1.imprimeDatos();
    cout << endl;
    Alumno a1("Pedro",20,'M',"345623",5,"LCC");
    a1.imprimeDatos();
    cout << endl;
    Alumno a2("Mario",21,'M',"345634",6,"LCC");
    a2.imprimeDatos();
    cout << endl;
    Alumno a3("Maria",17,'F',"345333",5,"FIS");
    a3.imprimeDatos();
    cout << endl;
    Profesor b1("Anastasia",30,'F',"567",15,"Matematicas");
    b1.imprimeDatos();
    cout << endl;
    Profesor b2("Nikolay",40,'M',"357",10,"Fisica");
    b2.imprimeDatos();
    cout << endl;
    Profesor b3("Miroslav",50,'M',"246",20,"Computacion");
    b3.imprimeDatos();
    cout << endl;
}
