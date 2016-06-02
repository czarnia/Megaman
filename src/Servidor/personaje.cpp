#include "personaje.h"
#include "evento_mover.h"
#include "bala.h"
#include <iostream>

#include <string>
#include <iostream>
#include <sstream>

#define PERDER_VIDA -1
#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4
#define SALTAR 5
#define VELOCIDAD 2
#define VELOCIDAD_SALTO 2  //La velocidad se toma respecto de las divisiones del mapa: div/seg.
#define ALTO 4
#define ANCHO 2

Personaje::Personaje(Mapa *mapa, Coordenada c, std::string id):
coordenada(c),
id(id){
	velocidad_y = 0;
	velocidad_x = 0;
	alto = ALTO;
	ancho = ANCHO;
	flotando = false; //asumo siempre inicio al personaje no en el aire.
	tiempo_pasado = 0;
}

void Personaje::notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

void Personaje::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	Coordenada pos_inicial(-1, -1);
	pos_inicial = coordenada;
	mover(tiempo, mapa);
	if (!(coordenada == pos_inicial)){
		std::cout << "NOTIFICO OBSERVADORES\n";
		notificar_observadores();
	}
	//atacar(tiempo, mapa);
}

void Personaje::agregar_movimiento(int direccion){
	std::cout << "PERSONAJE: AGREGAR MOVIMIENTO PERSONAJE\n";
	if (direccion == -1){
		velocidad_x = 0;
	}
	if (direccion == SALTAR && !flotando){
		std::cout << "caso salto \n";
		velocidad_y -= VELOCIDAD_SALTO;
	}
	if (direccion == DERECHA){
		std::cout << "caso derecha \n";
		velocidad_x += VELOCIDAD;
	}
	if (direccion == IZQUIERDA){
		std::cout << "caso izquierda \n";
		velocidad_x -= VELOCIDAD;
	}
}

void Personaje::sacar_movimiento(int direccion){
	if (direccion == -1){
		velocidad_x = 0;
	}
	if (direccion == DERECHA){
		std::cout << "caso dejo de apretar derecha \n";
		velocidad_x -= VELOCIDAD;
	}
	if (direccion == IZQUIERDA){
		std::cout << "caso dejar de apretar izquierda \n";
		velocidad_x += VELOCIDAD;
	}
}

void Personaje::agregar_ataque(int direccion) {}

Coordenada Personaje::get_coordenada(){
	return coordenada;
}

std::string Personaje::devolver_id(){
	return id;
}

bool Personaje::esta_vivo(){
	return vidas.empty();
}

int Personaje::get_cantidad_vidas(){
	return vidas.size();
}

int Personaje::get_porcentaje_vida(){
	int porcentaje = 0;
	if (!vidas.empty()){
		porcentaje = vidas[0]->get_porcentaje();
	}
	return porcentaje;
}

int Personaje::get_energia(){
	return 0; //TODO: cambiar al valor de la energia actual!
}

void Personaje::perder_vida(int porcentaje){
	if (porcentaje == PERDER_VIDA){
		vidas.erase(vidas.begin());
	}else{
		vidas[0]->perder(porcentaje);
	}
}
