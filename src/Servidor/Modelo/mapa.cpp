#include "mapa.h"
#include "../../Comun/lock.h"

#include "coordenada.h"

#include "elemento.h"
#include "bloque.h"
#include "puas.h"
#include "puas_asesinas.h"
#include "escalera.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

#include <math.h>
#include <algorithm>


#define TAM_BLOQUE 1

typedef std::vector<Coordenada>::iterator ItBloques;
typedef std::map<int, Personaje*>::iterator ItPersonaje;
typedef std::vector<Bala*>::iterator ItBalas;

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
		if (((elem!=NULL) && (!elem->puede_ocupar(ubic))) || (!tiene_coordenada(c_act))){
			return false;
		}
	}
	return true;
}

bool Mapa::ubicar(Personaje* pj, Coordenada c){
	if (!puede_ubicarse(pj, c)){
		return false;
	}
	personajes[pj->get_id()] = pj;
	return true;
}

bool Mapa::ubicar(Elemento* elem, Coordenada c){
	if (!puede_ubicarse(elem, c)){
		return false;
	}
	int x = c.obtener_abscisa();
	int y = c.obtener_ordenada();
	elementos[x][y] = elem;
	return true;
}

bool Mapa::ubicar(Bala* bala, Coordenada c){
	if (!puede_ubicarse(bala, c)){
		return false;
	}
	int x = c.obtener_abscisa();
	int y = c.obtener_ordenada();
	elementos[x][y] = bala;
	balas.push_back(bala);
	return true;
}

Personaje* Mapa::obtener_pj(int id_pj){
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
		if ( (x > ancho_min) && (x < ancho_max) && (y > alto_min) && (y < alto_max) ){
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
	coord_iniciales_personajes = coord_personajes();
	for (size_t i = 0; i < bloques.size(); i++){
		Coordenada c1 = bloques[i];
		Bloque* b = new Bloque(c1);
		std::vector<Coordenada> coordenadas_bloque = b->coordenadas();
		for (size_t j = 0; j < coordenadas_bloque.size(); j++){
			Coordenada c2 = coordenadas_bloque[j];
			int x = c2.obtener_abscisa();
			int y = c2.obtener_ordenada();
			elementos[x][y] = b;
		}
	}
}

void Mapa::agregar_bala(Bala *b){
	balas.push_back(b);
}

void Mapa::quitar_bala(Bala *b){
	ItBalas it_bala = std::find(balas.begin(), balas.end(), b);
	balas.erase(it_bala);
	//TODO: SACAR DEL MAPA DE ELEMENTOOOOSSS!!!	
}

void Mapa::agregar_personaje(Personaje *p){
	personajes.insert(std::pair<int, Personaje*>(p->get_id(), p));
	std::cout << "ID PJ AGREGADO: " << p->get_id() << "\n";
}

void Mapa::quitar_personaje(int id_pj){
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

std::vector<Ubicable*> Mapa::devolver_ubicables(){
	std::set<Ubicable*> ubicables;
	for (size_t i = 0; i < long_x; i++){
		for (size_t j = 0; j < long_y; j++){
			if (elementos[i].find(j) != elementos[i].end()){
				ubicables.insert(elementos[i][j]);
			}
		}
	}
	for (ItPersonaje it = personajes.begin(); it != personajes.end(); ++it){
		ubicables.insert(it->second);
	}

	std::vector<Ubicable*> ubicables_v(ubicables.begin(), ubicables.end());
	return ubicables_v;
}
