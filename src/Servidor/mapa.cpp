#include "mapa.h"
#include "coordenada.h"
#include "elemento.h"
#include "../Comun/lock.h"
#include "puas.h"
#include "escalera.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

#include <math.h>
#include <algorithm>


#define TAM_BLOQUE 1

typedef std::vector<Coordenada>::iterator ItBloques;
typedef std::map<std::string, Personaje*>::iterator ItPersonaje;

//-------------->Auxiliares<-----------//
std::vector<Coordenada> coord_tierras(){
	//IMPORTANTE: las coordenadas de los bloques
	//de tierra son las coordenadas internas
	//ya que los bordes de los bloque
	//pueden ser ocupados.

	std::vector<Coordenada> tierras;

	tierras.push_back(Coordenada(1,11));
	tierras.push_back(Coordenada(3,11));
	tierras.push_back(Coordenada(5,11));
	tierras.push_back(Coordenada(7,11));
	tierras.push_back(Coordenada(9,11));
	tierras.push_back(Coordenada(11,11));
	tierras.push_back(Coordenada(1,9));
	tierras.push_back(Coordenada(3,9));
	tierras.push_back(Coordenada(5,9));
	return tierras;
}

std::vector<Coordenada*> coord_personajes(){
	std::vector<Coordenada*> c_personajes;
	c_personajes.push_back(new Coordenada(3,6));

	return c_personajes;
}

std::vector<Coordenada> coord_puas(){
	std::vector<Coordenada> puas;

	puas.push_back(Coordenada(2,0));
	puas.push_back(Coordenada(1,3));
	puas.push_back(Coordenada(6,3));

	return puas;
}

std::vector<Coordenada> coord_escaleras(){
	std::vector<Coordenada> escaleras;
	for (size_t i = 0; i < 3; i++){
		escaleras.push_back(Coordenada(0,i+4));
		escaleras.push_back(Coordenada(5,i+1));
	}
	return escaleras;
}

//TODO: que esto sea una funcion de una interface "colisionable" o algo así
//que la implementen todos los ex ubicables.
bool colisionan(size_t x1, size_t y1, size_t ancho1, size_t alto1,
size_t x2, size_t y2, size_t ancho2, size_t alto2){
	int x_aux = std::min(x1+ancho1, x2+ancho2) - std::max(x1, x2);
	int y_aux = std::min(y1+alto1, y2+alto2) - std::max(y1,y2);
	size_t x_colision = std::max(0, x_aux);
	size_t y_colision = std::max(0, y_aux);
	return ((x_colision*y_colision) != 0);
}

//------------------------------------//

Mapa::Mapa(size_t long_x, size_t long_y):
long_x(long_x),
long_y(long_y){
	this->cargar();
}

int Mapa::obtener_long_x(){
	return long_x;
}

int Mapa::obtener_long_y(){
	return long_y;
}

bool Mapa::puede_ubicarse_en(Coordenada coord, size_t alto, size_t ancho){
	bool puedo_ocupar;
	//Personajes *
	//Verifico que el mapa tiene las coordenadas:
	Coordenada superior_derecha = coord.arriba(alto/2).derecha(ancho/2);
	Coordenada superior_izquierda = coord.arriba(alto/2).izquierda(ancho/2);
	Coordenada inferior_derecha = coord.abajo(alto/2).derecha(ancho/2);
	Coordenada inferior_izquierda = coord.abajo(alto/2).izquierda(ancho/2);

	puedo_ocupar = (this->tiene_coordenada(superior_derecha));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(superior_izquierda));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(inferior_derecha));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(inferior_izquierda));

	if (!puedo_ocupar){
		return false;
	}

	size_t xobj = superior_izquierda.obtener_abscisa();
	size_t yobj = superior_izquierda.obtener_ordenada();

	for (ItBloques it = bloques.begin(); it != bloques.end(); ++it){
		Coordenada coord_bloque_central = (*it);
		size_t xbloque = coord_bloque_central.arriba(TAM_BLOQUE).izquierda(TAM_BLOQUE).obtener_abscisa();
		size_t ybloque = coord_bloque_central.arriba(TAM_BLOQUE).izquierda(TAM_BLOQUE).obtener_ordenada();

		if (colisionan(xobj, yobj, ancho, alto, xbloque, ybloque, TAM_BLOQUE*2, TAM_BLOQUE*2)){
			return false;
		}
	}
	return true;
}

Personaje* Mapa::obtener_pj(std::string id_pj){
	Personaje *p = NULL;
	if (personajes.find(id_pj) != personajes.end()){
		p = personajes[id_pj];
	}
	return p;
}

void Mapa::update(size_t tiempo){
	for (ItPersonaje it= personajes.begin(); it != personajes.end(); ++it){
		(*it).second->update(tiempo, this);
	}
	for (size_t j = 0; j < balas.size(); j++){
		balas[j]->update(tiempo, this);
	}
}

bool Mapa::esta_en_aire(Coordenada coord, size_t alto){
	return !hay_tierra(coord.abajo((alto/2)+1)); //asumo los bloques son de tamaño 2
}

bool Mapa::hay_personaje(Coordenada *coord){
	size_t x = coord->obtener_abscisa();
	size_t y = coord->obtener_ordenada();
	for (ItPersonaje it = personajes.begin(); it != personajes.end(); ++it){
		Personaje *p = it->second;
		Coordenada coord_personaje = p->get_coordenada();
		size_t alto = p->get_alto();
		size_t ancho = p->get_ancho();
		size_t ancho_max = coord_personaje.derecha(ancho/2).obtener_abscisa();
		size_t ancho_min = coord_personaje.izquierda(ancho/2).obtener_abscisa();
		size_t alto_max = coord_personaje.arriba(alto/2).obtener_ordenada();
		size_t alto_min = coord_personaje.abajo(alto/2).obtener_ordenada();
		if ( (x > ancho_min) && (ancho_min < x) && (y > alto_min) && (y < alto_max) ){
			return true;
		}
	}
	return false;
}

bool Mapa::hay_tierra(Coordenada coord){
	for (size_t i = 0; i < bloques.size(); i++){
		if (bloques[i] == coord){
			return true;
		}
	}
	return false;
}

bool Mapa::tiene_coordenada(Coordenada coordenada){
	unsigned int x = coordenada.obtener_abscisa();
	unsigned int y = coordenada.obtener_ordenada();
	bool tiene_coordenada = (0 <= x) && (x <= long_x) && (0 <= y) && (y <= long_y);
	return tiene_coordenada;
}

void Mapa::cargar(){
	bloques = coord_tierras();
	coord_iniciales_personajes = coord_personajes();
}

void Mapa::agregar_bala(Bala *b){
	balas.push_back(b);
}

void Mapa::agregar_personaje(std::string id, Personaje *p){
	personajes.insert(std::pair<std::string, Personaje*>(id, p));
}

void Mapa::quitar_personaje(std::string id_pj){
	if (personajes.find(id_pj) != personajes.end()){
		personajes.erase(id_pj);
	}
}

std::vector<Coordenada> Mapa::coord_bloques(){
	return bloques;
}
