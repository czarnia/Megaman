#include "personaje.h"
#include "strategy_mover.h"
#include "evento_mover.h"
#include "bala.h"
#include <iostream>

#define PERDER_VIDA -1
#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4
#define SALTAR 5
//TODO: levantar estos datos de xml/json!!!
#define VELOCIDAD 1
#define VELOCIDAD_SALTO 2  //La velocidad se toma respecto de las divisiones del mapa: div/seg.

#define ALTO 2
#define ANCHO 1

Personaje::Personaje(Mapa *mapa, Coordenada c, std::string id):
coordenada(c),
id(id){
	velocidad_y = 0;
	velocidad_x = 0;
	alto = ALTO;
	ancho = ANCHO;
	agregar_observador(mapa);
	flotando = false; //asumo siempre inicio al personaje no en el aire.
}

void notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

void Personaje::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	mover(tiempo, mapa);
	atacar(tiempo, mapa);
}

void Personaje::agregar_movimiento(int direccion){
	if (direccion == SALTAR && !flotando){
		velocidad_y -= VELOCIDAD_SALTO;
	}
	if (direccion == DERECHA){
		velocidad_x += VELOCIDAD;
	}
	if (direccion == IZQUIERDA){
		velocidad_x -= VELOCIDAD;
	}
}

void Personaje::agregar_ataque(int direccion) {}

Coordenada Personaje::get_coordenada(){
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
