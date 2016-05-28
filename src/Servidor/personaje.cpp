#include "personaje.h"
#include "strategy_mover.h"
#include "evento_mover.h"
#include <iostream>

#define PERDER_VIDA -1
#define VELOCIDAD 1	  //La velocidad se toma respecto de las divisiones del mapa: div/seg.
#define ALTO 2
#define ANCHO 2

Personaje::Personaje(Mapa *mapa, Coordenada *c, std::string id):
coordenada(c),
id(id){
	movimiento = new StrategyMover(mapa, this, true);
	tiempo_pasado = 0;
	velocidad_y = 0;
	//TODO: levantar estos datos de xml/json!!!
	velocidad_x = VELOCIDAD;
	alto = ALTO;
	ancho = ANCHO;
}

int Personaje::get_velocidad(){
	return this->velocidad_x;
}

void Personaje::update(size_t tiempo){
	tiempo_pasado += tiempo;
	movimiento->mover(tiempo);
}

void Personaje::agregar_evento(Evento_mover *mover){
	movimiento->agregar_direccion(mover->get_direccion());
}

Coordenada* Personaje::get_coordenada(){
	return coordenada;
}

std::string& Personaje::devolver_id(){
	return id;
}

bool Personaje::esta_vivo(){
	return vidas.empty();
}

void Personaje::perder_vida(int porcentaje){
	if (porcentaje == PERDER_VIDA){
		vidas.erase(vidas.begin());
	}else{
		vidas[0]->perder(porcentaje);
	}
}
