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

bool Coordenada::operator==(const Coordenada& otro) const{
	bool x_iguales = (this->x == otro.x);
	bool y_iguales = (this->y == otro.y);
	return (x_iguales && y_iguales);
}

bool Coordenada::operator<(const Coordenada& otro) const{
	return ((this->x < otro.x)); //|| (this->y < otro.y));
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

bool Coordenada::esta_en_rango(int xi, int xf, int yi, int yf){
	return ((x > xi) && (x < xf) && (y > yi) && (y < yf));
}
