#include <iostream>
#include <conio.h>
using namespace std;
float areaCirculo (float);
int main () {
    float a;
    cout << "Dame el radio del circulo: " <<endl;
    cin >> a;
    cout << "Valor del area es: " << areaCirculo (a);
}
inline float areaCirculo (float n) {return n*n*3.14159265;}
