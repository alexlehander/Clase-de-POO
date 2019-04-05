#include <iostream>
#include <string.h>
using namespace std;

class Cliente {
public:
	Cliente (string, string);
	~Cliente ();
	void imprimir ();
protected:
    string nombre;
	string rfc;
};

class Productos {
public:
	Productos ();
	~Productos ();
	void imprimir ();
	void insertar (string, int, float);
protected:
    string nombre [10];
	int cantidad [10];
	float precio [10];
	int contador = 0;
	float total = 0;
};

class Factura : public Cliente, public Productos {
public:
	Factura (string, string, string, int);
	~Factura ();
	void imprimir ();
	static int folio;
protected:
    string fecha;
    int fol;
};

int Factura::folio = 0;

Cliente::Cliente (string a, string b) {
    nombre = a;
    rfc = b;
    cout << "Se construyo un objeto Cliente" << endl;
}

Productos::Productos () {
    cout << "Se construyo un objeto Productos" << endl;
}

Factura::Factura (string a, string b, string c, int d=folio+1) : Cliente (a, b), Productos () {
    fecha = c;
    fol = d;
    cout << "Se construyo un objeto Factura" << endl;
    Factura::folio++;
}

Cliente::~Cliente () {
    cout << "Se destruyo un objeto Cliente" << endl;
}

Productos::~Productos () {
    cout << "Se destruyo un objeto Productos" << endl;
}

Factura::~Factura () {
    cout << "Se destruyo un objeto Factura" << endl;
}

void Factura::imprimir () {
    Cliente::imprimir ();
    cout << "Fecha:   " << fecha << endl;
    cout << "Folio:   " << fol << endl;
    Productos::imprimir ();
}

void Cliente::imprimir () {
    cout << "Nombre:  " << nombre << endl;
    cout << "RFC:     " << rfc << endl;
}

void Productos::imprimir () {
    total=0;
    for (int i=0; i<contador; i++) {
        cout << "Producto " << i+1 << ":";
        cout << "    Nombre: " << nombre [i];
        cout << "    Cantidad: " << cantidad [i];
        cout << "    Precio: " << precio [i];
        total = total + precio[i] * cantidad[i];
        cout << "    Subtotal: " << precio [i] * cantidad [i] << endl;
    }
    cout << "Total a pagar: " << total << " Pesos" << endl << endl;
}

void Productos::insertar(string a, int b, float c) {
    nombre[contador] = a;
    cantidad[contador] = b;
    precio[contador] = c;
    contador++;
}

int main () {
	Factura f1 ("Ana", "546jot", "24/Sep/2019");
	f1.insertar ("Plumas", 5, 25.5);
	f1.insertar ("Hojas", 10, 20.4);
	f1.insertar ("Cuadernos", 15, 90.3);
	cout << endl;
	f1.imprimir ();
	Factura f2 ("Pedro", "123jot", "12/Sep/2019");
	f2.insertar ("Carne", 10, 11.5);
	f2.insertar ("Pescado", 12, 19.4);
	f2.insertar ("Verduras", 20, 33.3);
	cout << endl;
	f2.imprimir ();
	f1.imprimir ();
	f2.imprimir ();
}
