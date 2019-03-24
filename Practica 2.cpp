#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class Alumno {
public:
    void pideDato();
    void pideCali();
    void imprime();
 private:
    float calculaPro();
    bool validaMat();
    char nombre[30];
    string matricula;
    int calificaciones[4];
};

void Alumno::pideDato() {
    cout << "Dame tu nombre y matricula:" << endl;
    cin >> nombre >> matricula;
    while (!validaMat()) {
            cout << "Error: Introduce otra matricula:" << endl;
            cin >> matricula;
    }
}

void Alumno::pideCali() {
    cout << "Dame tus 4 calificaciones:" << endl;
    for (int i=0; i<4; i++) {
        cout << "Dame tu calificacion numero "<< i+1 << endl;
        cin >> calificaciones[i];
        while (calificaciones[i]<0 || calificaciones[i]>100) {
            cout << "Error: Introduce otro numero:" << endl;
            cin >> calificaciones[i];
        }
    }
}

void Alumno::imprime() {
    cout << "Tu promedio es: " << calculaPro() << endl << "Tu nombre es: " << nombre << endl << "Tu matricula es: " << matricula;
}

float Alumno::calculaPro() {
    float c=0;
    for (int i=0; i<4; i++) {
        c+=calificaciones[i];
    }
    return c/4;
}

bool Alumno::validaMat() {
    for (int i=0; i<matricula.size(); i++) {
        if (matricula [i]<'0' || matricula [i]>'9') return 0;
    }
    return 1;
}

int main() {
    Alumno h;
    h.pideDato ();
    h.pideCali ();
    h.imprime ();
}
