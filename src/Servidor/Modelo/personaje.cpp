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

//#define PERDER_MAX -100
//#define GANAR_MAX 100
#define VELOCIDAD 2
#define VELOCIDAD_SALTO 2  //La velocidad se toma respecto de las divisiones del mapa: div/seg.
#define ALTO 60
#define ANCHO 30

Personaje::Personaje(Mapa *mapa, Coordenada c, int id):
id(id),
coordenada(c){
	alto = ALTO;
	ancho = ANCHO;
	tiempo_pasado = 0;
	tipo = 0;
	flotando = false;
}

void Personaje::notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

void Personaje::update(float tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	mover(tiempo, mapa);
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

bool Personaje::esta_flotando(){
	return flotando;
}

void Personaje::interactuar(Escalera *esc){}

void Personaje::interactuar(Capsula_de_energia *capsula){}

bool Personaje::colisiona(Bala *bala, Coordenada c){
		size_t x = c.obtener_abscisa();
		size_t y = c.obtener_ordenada();
		size_t ancho_max = coordenada.derecha(ancho/2).obtener_abscisa();
		size_t ancho_min = coordenada.izquierda(ancho/2).obtener_abscisa();
		size_t alto_max = coordenada.arriba(alto/2).obtener_ordenada();
		size_t alto_min = coordenada.abajo(alto/2).obtener_ordenada();
		if ( (x >= ancho_min) && (x <= ancho_max) && (y <= alto_min) && (y >= alto_max) ){
			return true;
		}
		return false;
}

int Personaje::get_estado_actual(){
	return estado_actual;
}
