#include "coordenada.h"
#include <cmath>
#include <math.h>

#include <string>
#include <iostream>
#include <sstream>

#define RETROCEDER -1
#define AVANZAR 1

Coordenada::Coordenada(size_t ordenada, size_t abscisa){
	x = ordenada;
	y = abscisa;
}

/*void Coordenada::camino_minimo(Coordenada *origen, Coordenada *destino, std::queue<Coordenada> *camino){
	signed int delta_x = 0, delta_y = 0, versor_x = 0, versor_y = 0;

	size_t x0 = origen->obtener_abscisa();
	size_t y0 = origen->obtener_ordenada();
	size_t xf = destino->obtener_abscisa();
	size_t yf = destino->obtener_ordenada();

	if (x0 != xf){
		versor_x = (x0 > xf)? RETROCEDER : AVANZAR;
	}
	if (y0 != yf){
		versor_y = (y0 > yf)? RETROCEDER : AVANZAR;
	}

	while (((x0 + delta_x) != destino->obtener_abscisa()) && ((y0 + delta_y) != destino->obtener_ordenada())){
		delta_x += ((x0 + delta_x) != destino->obtener_abscisa())? versor_x : 0;
		delta_y += ((y0 + delta_y) != destino->obtener_ordenada())? versor_y : 0;

		Coordenada coord(x0 + delta_x, y0 + delta_y);
		camino->push(coord);
	}
}*/


bool Coordenada::operator==(const Coordenada& otro) const{
	bool x_iguales = (this->x == otro.x);
	bool y_iguales = (this->y == otro.y);
	return (x_iguales && y_iguales);
}

void Coordenada::operator=(const Coordenada& otro){
	this->x = otro.x;
	this->y = otro.y;
}

void Coordenada::sumar_abscisa(size_t delta_x){
	this->x += delta_x;
}

void Coordenada::sumar_ordenada(size_t delta_y){
	this->y += delta_y;
}

size_t Coordenada::obtener_ordenada(){
	return y;
}

size_t Coordenada::obtener_abscisa(){
	return x;
}

size_t Coordenada::obtener_distancia(Coordenada &otra_coordenada){
	size_t xcuadrado = pow((x-otra_coordenada.x),2);
	size_t ycuadrado = pow((y-otra_coordenada.y),2);
	return sqrt(xcuadrado + ycuadrado);
}

Coordenada Coordenada::arriba(size_t diferencial){
	return Coordenada(x,y-diferencial);
}

Coordenada Coordenada::abajo(size_t diferencial){
	return Coordenada(x,y+diferencial);
}

Coordenada Coordenada::izquierda(size_t diferencial){
	return Coordenada(x-diferencial,y);
}

Coordenada Coordenada::derecha(size_t diferencial){
	return Coordenada(x+diferencial,y);
}

bool Coordenada::es_negativa(){
	return ((x < 0) || (y < 0));
}

bool Coordenada::esta_en_rango(int xi, int xf, int yi, int yf){
	return ((x > xi) && (x < xf) && (y > yi) && (y < yf));
}
