#include "coordenada.h"
#include <cmath>
#include <math.h>

#define RETROCEDER -1
#define AVANZAR 1

Coordenada::Coordenada(int ordenada, int abscisa){
	x = ordenada;
	y = abscisa;
}

void Coordenada::camino_minimo(Coordenada *origen, Coordenada *destino, std::queue<Coordenada> *camino){
	signed int delta_x = 0, delta_y = 0, versor_x = 0, versor_y = 0;
	
	int x0 = origen->obtener_abscisa();
	int y0 = origen->obtener_ordenada();
	int xf = destino->obtener_abscisa();
	int yf = destino->obtener_ordenada();
		
	if (x0 != xf){
		versor_x = (x0 > xf)? RETROCEDER : AVANZAR; 
	}
	if (y0 != yf){
		versor_y = (y0 > yf)? RETROCEDER : AVANZAR;
	}

	while (((x0 + delta_x) != destino->obtener_abscisa()) || ((y0 + delta_y) != destino->obtener_ordenada())){
		delta_x += ((x0 + delta_x) != destino->obtener_abscisa())? versor_x : 0;
		delta_y += ((y0 + delta_y) != destino->obtener_ordenada())? versor_y : 0;
		
		Coordenada coord(x0 + delta_x, y0 + delta_y);
		camino->push(coord);
	}
}


bool Coordenada::operator==(const Coordenada& otro) const{
	bool x_iguales = (this->x == otro.x);
	bool y_iguales = (this->y == otro.y);
	return (x_iguales && y_iguales);
}

void Coordenada::operator=(const Coordenada& otro){
	this->x = otro.x;
	this->y = otro.y;
}

void Coordenada::sumar_abscisa(int delta_x){
	this->x += delta_x;
}

void Coordenada::sumar_ordenada(int delta_y){
	this->y += delta_y;
}

int Coordenada::obtener_ordenada(){
	return y;
}

int Coordenada::obtener_abscisa(){
	return x;
}

int Coordenada::obtener_distancia(Coordenada &otra_coordenada){
	int xcuadrado = pow((x-otra_coordenada.x),2);
	int ycuadrado = pow((y-otra_coordenada.y),2);
	return sqrt(xcuadrado + ycuadrado);
}

Coordenada Coordenada::arriba(int diferencial){
	return Coordenada(x,y-diferencial);
}

Coordenada Coordenada::abajo(int diferencial){
	return Coordenada(x,y+diferencial);
}

Coordenada Coordenada::izquierda(int diferencial){
	return Coordenada(x-diferencial,y);
}

Coordenada Coordenada::derecha(int diferencial){
	return Coordenada(x+diferencial,y);
}

bool Coordenada::es_negativa(){
	return ((x < 0) || (y < 0));
}
