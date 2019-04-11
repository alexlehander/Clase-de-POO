#include "miniwin.h"
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace miniwin;

class Circulo {
public:
    Circulo (int, int, int, int, int, int, int);
    virtual void MueveCirculo ();
    bool ColisionCirculo (Circulo*);
    int get_bape ();
protected:
    void PintaCirculo ();
    void RebotaCirculo ();
    int get_y ();
    int get_x ();
    int x,y;
    int radio;
    int tipo;
    int sentido;
    int colorado;
    int bape;
};

class Pelota : public Circulo {
public:
    Pelota (int, int, int, int, int ,int, int);
};

class Bala : public Circulo {
public:
    Bala (int, int, int, int, int ,int, int);
    void MueveCirculo ();
};

Circulo::Circulo (int x, int y, int radio, int sentido=0, int tipo=0, int colorado=0, int bape=0) {
    this->x=x;
    this->y=y;
    this->radio=radio;
    this->sentido=sentido;
    this->tipo=tipo;
    this->colorado=colorado;
    this->bape=bape;
}

Pelota::Pelota (int x, int y, int radio, int sentido=0, int tipo=0, int colorado=0, int bape=1) : Circulo (x,y,radio,sentido,tipo,colorado,bape){
    this->x=x;
    this->y=y;
    this->radio=radio;
    this->sentido=sentido;
    this->tipo=tipo;
    this->colorado=colorado;
    this->bape=bape;
}

Bala::Bala (int x, int y, int radio, int sentido=0, int tipo=0, int colorado=0, int bape=2) : Circulo (x,y,radio,sentido,tipo,colorado, bape){
    this->x=x;
    this->y=y;
    this->radio=radio;
    this->sentido=sentido;
    this->tipo=tipo;
    this->colorado=colorado;
    this->bape=bape;
}

void Circulo::MueveCirculo () {
    switch (sentido) {
        case 1 : x--; y--; break;
        case 2 : x++; y--; break;
        case 3 : x--; y++; break;
        case 4 : x++; y++; break;
    }
    PintaCirculo ();
    RebotaCirculo ();
}

void Bala::MueveCirculo() {
    switch (sentido) {
        case 1 : x-=5; y-=5; break;
        case 2 : x+=5; y-=5; break;
        case 3 : x-=5; y+=5; break;
        case 4 : x+=5; y+=5; break;
    }
    PintaCirculo ();
    RebotaCirculo ();
}

void Circulo::PintaCirculo () {
    if (tipo) circulo_lleno (x, y, radio);
    else circulo (x,y,radio);
    color (colorado);
}

void Circulo::RebotaCirculo () {
	if (sentido==1 && x<=10) sentido=2;
	if (sentido==1 && y<=10) sentido=3;
	if (sentido==2 && x>=390) sentido=1;
	if (sentido==2 && y<=10) sentido=4;
	if (sentido==3 && x<=10) sentido=4;
	if (sentido==3 && y>=290) sentido=1;
	if (sentido==4 && x>=390) sentido=3;
	if (sentido==4 && y>=290) sentido=2;
	if (x<=10 && y<=10) sentido=4;
	if (x>=390 && y<=10) sentido=3;
	if (x<=10 && y>=290) sentido=2;
	if (x>=390 && y>=290) sentido=1;
}

bool Circulo::ColisionCirculo(Circulo*c) {
	int x1=x-10, y1=y-10, x2=c->get_x()-10, y2=c->get_y()-10, largo=20;
	if (x1<x2+largo && x1+largo>x2 && y1<y2+largo && y1+largo>y2) {
		int k=sentido;
		sentido=c->sentido;
		c->sentido=k;
		return true;
	}
	return false;
}

int Circulo::get_x() {
    return x;
}

int Circulo::get_y() {
    return y;
}

int Circulo::get_bape() {
    return bape;
}

int main() {
	vredimensiona (400,300);
	int t, x, y, sentido, colorado, colisiones=0, a[5]={0,0,0,0,0}, b[5]={0,0,0,0,0}, tiempo=0, eliminados=10;
	std::stringstream txtStream;
	std::stringstream txtStreamo;
	srand (time(NULL));
    list <Circulo*> listaPelotas;
    Circulo c1 (200,200,10,1,0,1);

    for (int i=0; i<5; i++) {
    	int f=0;
    	x=rand()%399+1;
    	y=rand()%299+1;
    	while (f==0) {
    		for (int j=0; j<5; j++) {
    			while (x>=a[j]-10 && x<=a[j]+10) {
    				x=rand()%399+1;
				}
				while (y>=b[j]-10 && y<=b[j]+10) {
    				y=rand()%299+1;
				}
			}
			f=1;
		}
		a[i]=x;
		b[i]=y;
    	sentido=rand()%4+1;
    	colorado=rand()%5+1;
    	listaPelotas.push_back(new Pelota(x,y,10,sentido,1,colorado));
	}

    while(eliminados>0) {
        t=tecla();
        if (t == int('A') && tiempo<=0) {
        	tiempo=30;
        	listaPelotas.push_back(new Bala(0,0,3,4,1,rand()%5+1));
		}
        borra();

        for (list<Circulo*>::iterator it = listaPelotas.begin(); it!=listaPelotas.end(); it++) {
        	(*it)->MueveCirculo();
			list<Circulo*>::iterator ot=it;
			advance (ot,1);
        	for (;ot!=listaPelotas.end(); ot++) {
        		if ((*it)->ColisionCirculo(*ot)) {
        			colisiones++;
				}
			}
			if (c1.ColisionCirculo(*it)) {
                colisiones++;
                if ((*it)->get_bape()==2) {
                    it=listaPelotas.erase(it);
        		    eliminados--;
                }
			}
		}

		c1.MueveCirculo();
        txtStream.str("");
        txtStream<<"Rebotes: "<<colisiones;
        txtStreamo.str("");
        txtStreamo<<"Vidas: "<<eliminados;
        miniwin::color(1);
        texto(300, 10, txtStream.str());
        texto(300, 30, txtStreamo.str());
        refresca();
        espera(10);
        tiempo--;
    }
    return 0;
}
