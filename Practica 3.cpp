#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class libro {
public:
    libro(string, string, int, char);
    ~libro();
    void crear();
    void imprime();
    void cambiar();
    void prestamo();
    void devolucion();
 private:
    bool verificar(char);
    char estadocambio(char);
    string titulo;
    string autor;
    int anio;
    char estado;
};

libro::libro(string a="------", string b="------", int c=0, char d='/') {
    titulo = a;
    autor = b;
    anio = c;
    estado = d;
}

void libro::crear () {
    cout << "Introduzeme los datos de tu libro: " << endl;
    cout << "Titulo: ";
    cin >> titulo;
    cout << "Autor: ";
    cin >> autor;
    cout << "Anno: ";
    cin >> anio;
    cout << "Estado: ";
    cin >> estado;
    libro *a1= new libro (titulo,autor,anio,estado);
}

void libro::prestamo () {
    cout << "Asi que quieres pedir prestado el libro, eh? " << endl;
    if (verificar('d')) {
        estadocambio('p');
        cout << "El libro fue exitosamente prestado" << endl;
    }
    else cout << "El libro no se pudo prestar" << endl;
}

void libro::devolucion () {
    cout << "Asi que quieres devolver el libro, eh? " << endl;
    if (verificar('p')) {
        estadocambio('d');
        cout << "El libro fue exitosamente devuelto" << endl;
    }
    else cout << "El libro no se pudo devolver" << endl;
}

bool libro::verificar (char a) {
    if (estado==a) return 1;
    return 0;
}

char libro::estadocambio (char a) {
    estado=a;
}

void libro::cambiar () {
    cout << "Titulo: ";
    cin >> titulo;
    cout << "Autor: ";
    cin >> autor;
    cout << "Anno: ";
    cin >> anio;
    cout << "Estado: ";
    cin >> estado;
}

void libro::imprime () {
    cout << "Titulo: " << titulo << endl << "Autor: " << autor << endl << "Anno: " << anio << endl << "Estado: " << estado << endl;
}

libro::~libro() {
    cout << endl << "El libro fue destruido..." << endl;
}

int main () {
    int a=1;
    libro *a1 = new libro ();
    while (a>=1||a<=6) {
    cout <<"1.Rellenar el libro"<< endl <<"2.Borrar el libro"<< endl << "3.Modificar el libro"<< endl<< "4.Imprimir el libro" << endl << "5.Prestar" << endl << "6.Devolver" << endl << "7.Salir"<<endl;
    cin >> a;
    if (a==1)  a1->crear();
    else if (a==2) delete a1;
    else if (a==3) a1->cambiar ();
    else if (a==4) a1->imprime ();
    else if (a==5) a1->prestamo();
    else if (a==6) a1->devolucion();
    else if (a==7) return 0;
    else cout << "Introduzeme otro valor! Esta mal!" << endl;
    }
}
