#include <iostream>
#include <string.h>
using namespace std;

class Ventas {
public:
    Ventas ();
    void imprimir ();
    ~Ventas ();
    static void print ();
    static int vendidos;
    static int novendidos;
    static float ingresos;
};

class Persona {
public:
    Persona (string, string);
    void imprimir ();
    ~Persona ();
    string nombre;
    string    telefono;
};

class Cliente : public Persona {
public:
    Cliente (string, string, int);
    void imprimir ();
    ~Cliente ();
    int ID;
};

class Vendedor : public Persona {
public:
    Vendedor (string, string, int);
    void imprimir () ;
    ~Vendedor ();
    int RFC;
};

class Fecha {
public:
    Fecha (int, int, int);
    void imprimir ();
    ~Fecha ();
    int dia;
    int mes;
    int anio;
};

class Auto {
friend float vender (Cliente &, Vendedor &, Auto &);
public:
    Auto (float, string, int, int, int);
    void imprimir () ;
    void factura ();
    ~Auto ();
    string sell;
    string buy;
    string fechaVenta;
    float precio;
    Fecha fechaManu;
    string marca;
};

int Ventas::vendidos = 0;
int Ventas::novendidos = 0;
float Ventas::ingresos = 0;

Ventas::Ventas () {
    cout << "Se construyo un objeto Ventas" << endl;
}

Persona::Persona (string a="Indefinido", string b="No se conoce") {
    nombre = a;
    telefono = b;
    cout << "Se construyo un objeto Persona" << endl;
}

Cliente::Cliente (string a="Indefinido", string b="No se conoce", int c=0) : Persona(a, b) {
    ID = c;
    cout << "Se construyo un objeto Cliente" << endl;
}

Vendedor::Vendedor (string a="Indefinido", string b="No se conoce", int c=0) : Persona(a, b) {
    RFC = c;
    cout << "Se construyo un objeto Vendedor" << endl;
}

Fecha::Fecha (int x, int y, int z) {
    dia = x;
    mes = y;
    anio = z;
    cout << "Se construyo un objeto Fecha" << endl;
}

Auto::Auto (float d, string e, int x, int y, int z) : fechaManu(x,y,z) {
    precio = d;
    marca = e;
    cout << "Se construyo un objeto Auto" << endl;
    Ventas::novendidos++;
}

Ventas::~Ventas () {
    cout << "Se destruyo un objeto Ventas" << endl;
    Ventas::print();
}

Persona::~Persona () {
    cout << "Se destruyo un objeto Persona" << endl;
}

Cliente::~Cliente () {
    cout << "Se destruyo un objeto Cliente" << endl;
}

Vendedor::~Vendedor () {
    cout << "Se destruyo un objeto Vendedor" << endl;
}

Fecha::~Fecha () {
    cout << "Se destruyo un objeto Fecha" << endl;
}

Auto::~Auto () {
    cout << "Se destruyo un objeto Auto" << endl;
}

float vender (Cliente &a, Vendedor &b, Auto &c) {
    c.buy=a.nombre;
    c.sell=b.nombre;
    c.fechaVenta="Ahora";
    Ventas::vendidos++;
    Ventas::novendidos--;
    float dinero = c.precio*1.16;
    Ventas::ingresos=Ventas::ingresos+dinero;
    return dinero;
}

void Ventas::print() {
    cout << endl << "Vehiculos vendidos:         " << vendidos << endl;
    cout <<         "Vehiculos en venta:         " << novendidos << endl;
    cout <<         "Ingresos totales:           " << ingresos << endl <<  endl;
}

void Auto::factura () {
    cout << endl << "Vendedor:          " << sell << endl;
    cout <<         "Comprador:         "<< buy << endl;
    cout <<         "Precio:            " << precio*1.16 << endl;
    cout <<         "Fecha de venta:    " << fechaVenta << endl;
    cout <<         "Auto:              " << marca << endl << endl;
}

void Persona::imprimir ()  {
    cout << endl << "Nombre:          " << nombre << endl;
    cout <<         "Telefono:        " << telefono << endl <<  endl;

}

void Cliente::imprimir ()  {
    cout << endl << "Nombre:          " << nombre << endl;
    cout <<         "Telefono:        " << telefono << endl;
    cout <<         "ID:              " << ID << endl <<  endl;
}

void Vendedor::imprimir ()  {
    cout << endl << "Nombre:          " << nombre << endl;
    cout <<         "Telefono:        " << telefono << endl;
    cout <<         "RFC:             " << RFC << endl <<  endl;
}

void Fecha::imprimir ()  {
    cout <<         "Dia:          " << dia << endl;
    cout <<         "Mes:          " << mes << endl;
    cout <<         "Anio:         " << anio << endl <<  endl;
}

void Auto::imprimir ()  {
    cout << endl << "Marca:                " << marca << endl;
    cout <<         "Precio:               " << precio << endl;
    cout <<         "Fecha de Manufactura: " << endl;
    fechaManu.imprimir();
}


int main () {
    Ventas::print();
    Cliente c1 ("Jorge" , "6461234564", 456);
    c1.imprimir();
    Cliente c2 ("Juan"  , "6461357905", 123);
    c2.imprimir();
    Cliente c3 ("Jose"  , "6462571234", 789);
    c3.imprimir();
    Vendedor v1 ("Anna" , "6165467897", 43567);
    v1.imprimir();
    Vendedor v2 ("Maria", "6162546709", 24489);
    v2.imprimir();
    Auto a1 (100000, "Dodge", 12, 12, 2012);
    a1.imprimir();
    Auto a2 (200000, "Wolkswagen", 11, 11, 2011);
    a2.imprimir();
    Auto a3 (300000, "Honda", 10, 10, 2010);
    a3.imprimir();
    vender (c1, v1, a1);
    a1.factura();
    vender (c2, v2, a2);
    a2.factura();
    Ventas::print();
}
