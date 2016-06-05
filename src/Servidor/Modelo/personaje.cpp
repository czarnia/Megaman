#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include "puas_asesinas.h"
#include "bloque.h"
#include <set>

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

Personaje::Personaje(Mapa *mapa, Coordenada c, int id, Factory_observador_ubicable *fact_obs):
coordenada(c),
id(id),
fact_obs(fact_obs){
	velocidad_y = 0;
	velocidad_x = 0;
	alto = ALTO;
	ancho = ANCHO;
	flotando = false; //asumo siempre inicio al personaje no en el aire.
	tiempo_pasado = 0;
	tipo = 0;
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
		std::cout << "PERSONAJE: NOTIFICO OBSERVADORES\n";
		notificar_observadores();
	}
}

void Personaje::agregar_movimiento(int direccion){
	std::cout << "PERSONAJE: AGREGAR MOVIMIENTO PERSONAJE\n";
	if (direccion == -1){
		velocidad_x = 0;
	}
	if (direccion == SALTAR && !flotando){
		std::cout << "PERSONAJE agregar_mov:caso salto \n";
		velocidad_y -= VELOCIDAD_SALTO;
	}
	if (direccion == DERECHA){
		std::cout << "PERSONAJE agregar_mov:caso derecha \n";
		velocidad_x += VELOCIDAD;
	}
	if (direccion == IZQUIERDA){
		std::cout << "PERSONAJE agregar_mov:caso izquierda \n";
		velocidad_x -= VELOCIDAD;
	}
}

void Personaje::sacar_movimiento(int direccion){
	if (direccion == -1){
		velocidad_x = 0;
	}
	if (direccion == DERECHA){
		std::cout << "PERSONAJE sacar_mov: interrumpo mov derecha\n";
		velocidad_x = 0;
	}
	if (direccion == IZQUIERDA){
		std::cout << "PERSONAJE sacar_mov: interrumpo mov izquierda \n";
		velocidad_x = 0;
	}
}

Coordenada Personaje::get_coordenada(){
	return coordenada;
}

int Personaje::get_id(){
	return id;
}

int Personaje::get_tipo(){
	return tipo;
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

int Personaje::get_alto(){
	return alto;
}

int Personaje::get_ancho(){
	return ancho;
}

void Personaje::agregar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

void Personaje::quitar_observador(Observador_ubicable *observador){
	Observable::quitar_observador(observador);
}

void Personaje::agregar_observador(Observador_personaje *observador){
	Observable::agregar_observador(observador);
}

void Personaje::quitar_observador(Observador_personaje *observador){
	Observable::quitar_observador(observador);
}

std::vector<Coordenada> Personaje::coordenadas(Coordenada c){
	std::set<Coordenada> s_coord;
	for (size_t i = 0; i < alto/2; i++){
		for (size_t j = 0; j < ancho/2; j++){
			s_coord.insert(c.arriba(i).izquierda(j));
			s_coord.insert(c.arriba(i).derecha(j));
			s_coord.insert(c.abajo(i).izquierda(j));
			s_coord.insert(c.abajo(i).derecha(j));
		}
	}
	std::vector<Coordenada> v(s_coord.begin(), s_coord.end());
	return v;
}

std::vector<Coordenada> Personaje::coordenadas(){
	return coordenadas(coordenada);
}

bool Personaje::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Personaje::puede_ocupar(Personaje* pj){
	return true;
}

bool Personaje::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Personaje::puede_ocupar(Bala* bala){
	return true;
}

bool Personaje::puede_ocupar(Escalera* esc){
	return true;
}

bool Personaje::puede_ocupar(Bloque* bloque){
	return false;
}

bool Personaje::puede_ocupar(Puas* puas){
	return true;
}

bool Personaje::puede_ocupar(Puas_asesinas* puas){
	return true;
}