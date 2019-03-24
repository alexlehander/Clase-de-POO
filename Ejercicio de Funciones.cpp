#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Calcu {
public:
    void Suma ();
    void Resta ();
    void Multi ();
    void Divi ();
    void Def ();
    void Imp ();
private:
    float a;
    float b;
    float c;
};
void Calcu::Suma () {
    c=a+b;
}
void Calcu::Resta () {
    c=a-b;
}
void Calcu::Multi () {
    c=a*b;
}
void Calcu::Divi () {
    c=a/b;
}
void Calcu::Def () {
    cout << "Dame el primer y segundo numero: " << endl;
    cin >> a;
    cin >> b;
}
void Calcu::Imp () {
    cout << "Tu resultado es: " << c << endl;
}
int main () {
    Calcu h;
    int d=0;
    while (d!=5) {
        cout << "Elige la opcion de la operacion: 1 = Suma, 2 = Resta, 3 = Multiplicacion, 4 = Division, 5 = Salir"<< endl;
        cin >> d;
        if (d==1||d==2||d==3||d==4)  h.Def ();
        else return 0;
        if (d==1) h.Suma ();
        else if (d==2) h.Resta ();
        else if (d==3) h.Multi ();
        else if (d==4) h.Divi ();
        h.Imp ();
    }
}
