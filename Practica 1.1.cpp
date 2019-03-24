#include <iostream>
#include <conio.h>
using namespace std;
void potencia (float, float &);
int main () {
    float a,b;
    cout << "Dame el numero: " <<endl;
    cin >> a;
    cout << "Dame la potencia: " <<endl;
    cin >> b;
    potencia (b,a);
    cout << "Valor del numero es: " << a;
}
inline void potencia (float b, float &a) {
    int c=a;
    for (int i=1; i<b; i++) {
        a=a*c;
    }
}
