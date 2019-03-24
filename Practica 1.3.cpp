#include <iostream>
#include <conio.h>
using namespace std;
float cuadrado_1 (float &);
float cuadrado_2 (float &);
int main () {
    float a;
    cout << "Dame un valor: " <<endl;
    cin >> a;
    cuadrado_1(a);
    cout << "El cuadrado es: " << a;
}
inline float cuadrado_1 (float &a) {cuadrado_2(a);}
inline float cuadrado_2 (float &a) {a=a*a;}
