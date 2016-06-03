#include "mapa.h"
#include "../Comun/lock.h"

#include "coordenada.h"

#include "elemento.h"
#include "bloque.h"
#include "puas.h"
#include "puas_asesinas.h"
#include "escalera.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

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

bool Mapa::puede_ubicarse(Ubicable* ubic, Coordenada c){
	std::vector<Coordenada> coordenadas = ubic->coordenadas(c);
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada c_act = coordenadas[i];
		int x = c_act.obtener_abscisa();
		int y = c_act.obtener_ordenada();
		Elemento* elem = elementos[x][y];
		if ((!elem->puede_ocupar(ubic)) || (!tiene_coordenada(c_act))){
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
		//size_t ancho_max = coord_personaje.derecha(ancho/2).obtener_abscisa();
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
	return ((0 <= x) && (x <= long_x) && (0 <= y) && (y <= long_y));
}

void Mapa::cargar(){
	bloques = coord_tierras();

	for (size_t i = 0; i < bloques.size(); i++){
		Coordenada c1 = bloques[i];
		Bloque* b = new Bloque(c1);
		std::vector<Coordenada> coordenadas_bloque = b->coordenadas();
		for (size_t j = 0; j < coordenadas_bloque.size(); j++){
			Coordenada c2 = coordenadas_bloque[i];
			int x = c2.obtener_abscisa();
			int y = c2.obtener_ordenada();

			elementos[x][y] = b;
		}
	}
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

void Mapa::interactuar_con_entorno(Personaje* pj){
	std::set<Elemento*> interactivos;
	std::vector<Coordenada> coordenadas = pj->coordenadas();

	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada c_act = coordenadas[i];
		int x = c_act.obtener_abscisa();
		int y = c_act.obtener_ordenada();

		Elemento* elem = elementos[x][y];
		interactivos.insert(elem);
	}

	std::set<Elemento*>::iterator it;
	for(it = interactivos.begin(); it != interactivos.end(); it++){
		(*it)->interactuar(pj);
	}
}
