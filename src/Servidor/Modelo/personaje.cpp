#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include "bloque.h"
#include <algorithm>
#include <vector>

#include <string>
#include <iostream>
#include <sstream>
#include "../../Comun/lock.h"
#include "../../Comun/mutex.h"

#define PERDER_MAX -100
#define GANAR_MAX 100
#define VELOCIDAD 2
#define VELOCIDAD_SALTO 2  //La velocidad se toma respecto de las divisiones del mapa: div/seg.
#define ALTO 4
#define ANCHO 2

Personaje::Personaje(Mapa *mapa, Coordenada c, int id):
coordenada(c),
id(id){
	//velocidad_y = 0;
	//velocidad_x = 0;
	alto = ALTO;
	ancho = ANCHO;
	flotando = false; //asumo siempre inicio al personaje no en el aire.
	tiempo_pasado = 0;
	tipo = 0;
	energia = GANAR_MAX;
}

void Personaje::notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

void Personaje::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	mover(tiempo, mapa);
	notificar_observadores();
}

void Personaje::agregar_movimiento(int dir, StrategyMover *movimiento){
	if (movimientos.find(dir) == movimientos.end()){
		movimientos[dir] = movimiento;
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
	return !vidas.empty();
}

int Personaje::get_cantidad_vidas(){
	return vidas.size();
}

int Personaje::get_porcentaje_vida(){
	int porcentaje = 0;
	if (!vidas.empty()){
		porcentaje = vidas[0].get_porcentaje();
	}
	return porcentaje;
}

int Personaje::get_energia(){
	return 0; //TODO: cambiar al valor de la energia actual!
}

void Personaje::perder_vida(int porcentaje){
	if (porcentaje == PERDER_MAX){
		vidas.erase(vidas.begin());
	}else{
		vidas[0].perder(porcentaje);
	}
}

void Personaje::ganar_vida(int porcentaje){
	if (porcentaje == GANAR_MAX){
		Vida vida_nueva = Vida();
		vidas.push_back(vida_nueva);
	}else{
		vidas[0].ganar(porcentaje);
	}
}

void Personaje::perder_energia(int porcentaje){
	if ((energia - porcentaje) <= 0){
		energia = 0;
	}else{
		energia -= porcentaje;
	}
}

void Personaje::ganar_energia(int porcentaje){
	if ((porcentaje - energia) >= GANAR_MAX){
		energia = GANAR_MAX;
	}else{
		energia += porcentaje;
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

std::vector<Coordenada> Personaje::coordenadas(Coordenada centro){
	std::vector<Coordenada> s_coord;
	Coordenada coord_aux(0,0);
	for (size_t i = 0; i <= alto/2; i++){
		for (size_t j = 0; j <= ancho/2; j++){
			coord_aux = centro.arriba(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.arriba(i).izquierda(j));
			}
			coord_aux = centro.arriba(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.arriba(i).derecha(j));
			}
			coord_aux = centro.abajo(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.abajo(i).izquierda(j));
			}
			coord_aux = centro.abajo(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.abajo(i).derecha(j));
			}

		}
	}
	return s_coord;
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

bool Personaje::puede_ocupar(Elemento* elem){
	return elem->puede_ocupar(this);
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

bool Personaje::puede_ocupar(Premio* premio){
	return true;
}

void Personaje::respawn(Coordenada posicion_inicial){
	coordenada = posicion_inicial;
}
