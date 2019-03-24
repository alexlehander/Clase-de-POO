#include <iostream>
using namespace std;
class Hora
{
public:
    Hora ();
    void constructor (int, int, int);
    void estandar ();
    void extendida ();
private:
    int hora;
    int minuto;
    int segundo;
};
Hora::Hora() {hora=minuto=segundo=0;}
void Hora::constructor (int h, int m, int s) {
    hora = h;
    minuto = m;
    segundo = s;
}
void Hora::extendida () {
    cout << (hora<0||hora>23?"0":"") << hora << ":";
    cout << (minuto<0||minuto>59?"0":"") << minuto << ":";
    cout << (segundo<0||segundo>59?"0":"") << segundo << endl;
}
void Hora::estandar () {
    cout << (hora<=12?hora:hora-12) << ":";
    cout << (minuto<0||minuto>59?"0":"") << minuto << ":";
    cout << (segundo<0||segundo>59?"0":"") << segundo;
    cout << (hora<=12?" am":" pm") << endl;
}
int main () {
    Hora h;
    int a,b,c;
    cout << "Dame el tiempo que deseas mostrar: Hora, Minuto, Segundo..." << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    h.constructor (a,b,c);
    cout << "La hora extendida es:" << endl;
    h.extendida ();
    cout << "La hora estandar es:" << endl;
    h.estandar ();
}
