#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Paciente {
public:
    Paciente(string, string, int, int);
    ~Paciente();
    void registro ();
    void registroInc ();
    void alta ();
    void consulta ();
    void consulta () const;
    void cambioHab ();
    void nombrar ();
private:
    string nombre;
    string motivo;
    int habitacion;
    int estado;
    void cambioNom ();
};

Paciente::Paciente (string a="-", string b="------", int c=0, int d=0) {
    nombre = a;
    motivo = b;
    habitacion = c;
    estado = d;
}

static Paciente a2 ("Doctor", "Se encarga de curar a los pacientes", 666, 1);

void Paciente::registro () {
    cout << "Introduzeme los datos de tu paciente: " << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Motivo: ";
    cin >> motivo;
    cout << "Habitacion: ";
    cin >> habitacion;
    estado = 1;
    Paciente *a1= new Paciente (nombre,motivo,habitacion,estado);
    cout << "El paciente se creo exitosamente!" << endl;
}

void Paciente::registroInc () {
    cout << "Introduzeme los datos de tu paciente inconsciente: " << endl;
    cout << "Motivo: ";
    cin >> motivo;
    cout << "Habitacion: ";
    cin >> habitacion;
    estado = 0;
    Paciente *a1= new Paciente (nombre,motivo,habitacion,estado);
    cout << "El paciente se creo exitosamente!" << endl;
}

void Paciente::cambioHab () {
    cout << "Introduzeme la nueva habitacion de tu paciente: " << endl;
    cin >> habitacion;
}

void Paciente::cambioNom () {
    cout << "Introduzeme el nombre de tu paciente: " << endl;
    cin >> nombre;
}

void Paciente::alta () {
    float dias,costo;
    cout << "Dias internado: ";
    cin >> dias;
    cout << "Costo diario en pesos: ";
    cin >> costo;
    costo=costo*dias;
    cout << "Costo del servicio: " << costo << " Pesos" << endl;
}

void Paciente::consulta () {
    cout << "Nombre: " << nombre << endl;
    cout << "Motivo: " << motivo << endl;
    cout << "Habitacion: " << habitacion << endl;
    cout << "Estado: ";
    if (estado==0) cout << "Inconsciente" <<endl;
    else cout << "Consciente" <<endl;
}

void Paciente::consulta () const {
    cout << "Nombre: " << nombre << endl;
    cout << "Motivo: " << motivo << endl;
    cout << "Habitacion: " << habitacion << endl;
    cout << "Estado: ";
    if (estado==0) cout << "Inconsciente" <<endl;
    else cout << "Consciente" <<endl;
}

void Paciente::nombrar () {
    char a;
    if (nombre=="-") {
        cout << "Su paciente ya desperto? s/n" << endl;
        cin >> a;
        if (a=='s') {
            cambioNom ();
            estado=1;
        }
    }
}

Paciente::~Paciente() {
    cout << "Se fue el paciente!" << endl;
}

int main () {
    int a=1;
    char b;
    Paciente *a1 = new Paciente ();
    const Paciente a3 ("Enfermera", "Se encarga de recibir a los pacientes", 999, 1);
    while (a>=1||a<=6) {
    cout <<"1. Registrar Paciente"<< endl <<"2. Nombrar a los Pacientes recuperados"<< endl << "3. Dar de alta al Paciente"<< endl<< "4. Consulta" << endl << "5. Cambio de Habitacion" << endl << "6. Salir"<<endl;
    cin >> a;
    if (a==1)  {
        cout << "Tu Paciente esta consciente? s/n" << endl;
        cin >> b;
        if (b=='s') a1->registro();
        else a1->registroInc();
    }
    else if (a==2) a1->nombrar ();
    else if (a==3) {
        a1->alta ();
        delete a1;
        Paciente *a1 = new Paciente ();
        cout << endl <<"Muchas gracias, aqui les dejo los datos de la enfermera que lo atendio!" << endl << endl;
        a3.consulta();
    }
    else if (a==4) {
        cout << endl << "Quiere saber quien es nuestro doctor? s/n"  << endl << endl;
        cin >> b;
        if (b=='s') {
            a2.consulta ();
            cout << "Ahora si, tu paciente..." << endl << endl;
        }
        a1->consulta ();
    }
    else if (a==5) a1->cambioHab ();
    else if (a==6) return 0;
    else cout << "Introduzeme otro valor! Esta mal!" << endl;
    }
}
