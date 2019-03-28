#include <iostream>
#include <string.h>
using namespace std;

class Deporte {
public:
    Deporte (string, int, int);
    void imprimir () ;
    void actualizar (string, int, int);
    ~Deporte ();
    static void print ();
    static int categorias;
private:
    string nombre;
    int    jugadores;
protected:
    int   tiempo;
};

class Terrestre : public Deporte {
public:
    Terrestre (string, int, int, string);
    void imprimir () ;
    void actualizar ();
    ~Terrestre ();
private:
    string terreno;
};

class Auxiliar : public Terrestre {
public:
    Auxiliar (string, int, int, string, string);
    void imprimir () ;
    void actualizar ();
    ~Auxiliar ();
private:
    string nivel;
};

int Deporte::categorias = 0;

Deporte::Deporte (string a="Indefinido", int b=0, int c=0) {
    nombre = a;
    jugadores = b;
    tiempo = c;
    cout << "Se construyo un objeto deporte." << endl;
}

Terrestre::Terrestre (string a="Indefinido", int b=0, int c=0, string d="Desconocido") : Deporte(a, b, c) {
    terreno = d;
    cout << "Se construyo un objeto terrestre." << endl;
    categorias++;
}

Auxiliar::Auxiliar (string a="Indefinido", int b=0, int c=0, string d="Desconocido", string e="Nada") : Terrestre(a, b, c, d) {
    nivel = e;
    cout << "Se construyo un objeto auxiliar." << endl;
}

Deporte::~Deporte () {
    cout << "Se destruyo un objeto deporte." << endl;
    Deporte::print();
}

Terrestre::~Terrestre () {
	categorias--;
    cout << "Se destruyo un objeto terrestre." << endl;
    Deporte::print();
}

Auxiliar::~Auxiliar () {
    cout << endl << "Se destruyo un objeto auxiliar." << endl;
    Deporte::print();
}

void Deporte::imprimir ()  {
	cout << "Nombre:          " << nombre << endl;
    cout << "Jugadores:       " << jugadores << endl;
    cout << "Tiempo:          " << tiempo << endl;
    cout << "Categorias:      " << categorias << endl;
}

void Deporte::print () {
    cout << "Categorias:      " << categorias << endl << endl;
}

void Terrestre::imprimir ()  {
	Deporte::imprimir();
	cout << "Terreno:         " << terreno << endl;
}

void Auxiliar::imprimir ()  {
	Terrestre::imprimir();
	cout << "Herramienta:     " << nivel << endl << endl;
}

void Auxiliar::actualizar() {
	cout << "Se cambio tu objeto auxiliar..." << endl;
	//nombre  = "Lucha";
    //jugadores    = 2;
    tiempo  = 10;
    //terreno = "Rocoso";
    nivel = "Equipamiento";
}

int main () {
	Deporte::print();
	Deporte d1("Soocer",11,60);
    d1.imprimir();
    cout << endl;
    Terrestre t1("Footbal",22,90,"Plano");
    t1.imprimir();
    cout << endl;
    Auxiliar a1("Polo",10,100,"Pasto","Caballo");
    a1.imprimir();
    a1.actualizar();
    a1.imprimir();
}
