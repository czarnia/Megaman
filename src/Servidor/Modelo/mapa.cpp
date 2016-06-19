#include "mapa.h"
#include "../../Comun/lock.h"

#include "coordenada.h"

#include "personaje_pc.h"
#include "personaje_npc.h"

#include "elemento.h"
#include "bloque.h"
#include "puas.h"
#include "escalera.h"

#include "capsula_de_plasma_factory.h"
#include "capsula_de_energia_factory.h"
#include "nueva_vida_factory.h"
#include "puerta_boss.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

#include <math.h>
#include <algorithm>

#define TAM_BLOQUE 30
#define CAPSULA_DE_PLASMA 1
#define CAPSULA_DE_ENERGIA 2
#define NUEVA_VIDA 3

typedef std::vector<Coordenada>::iterator ItBloques;
typedef std::map<int, Personaje_pc*>::iterator ItPersonajePc;
typedef std::map<int, Personaje_npc*>::iterator ItPersonajeNpc;
typedef std::vector<Bala*>::iterator ItBalas;
typedef std::map<int, Premio_factory*>::iterator ItPremios;

//-------------->Auxiliares<-----------//
std::vector<int> obtener_claves(std::map<int, Premio_factory*> hash){
  std::vector<int> v;
  for (ItPremios it = hash.begin(); it != hash.end(); it++){
    v.push_back(it->first);
  }
  return v;
}

//------------------------------------//

Mapa::Mapa(size_t l_x, size_t l_y):
long_x(l_x), 
long_y(l_y+TAM_BLOQUE){
  int y = long_y - TAM_BLOQUE/2;
  for (size_t x = 0; x < long_x; x++){
    Puas* puas_asesinas = new Puas(Coordenada(x,y));
    elementos.push_back(puas_asesinas);
  }
}

Mapa::~Mapa(){
	std::vector<int> claves = obtener_claves(premios);
	for (size_t i = 0; i < claves.size(); i++){
		Premio_factory* premio = premios[claves[i]];
  	premios.erase(claves[i]);
    delete premio;
	}
}

int Mapa::obtener_long_x(){
	return long_x;
}

int Mapa::obtener_long_y(){
	return long_y;
}

bool Mapa::puede_ubicarse(Ubicable* ubic, Coordenada c){
  int ancho = ubic->get_ancho();
  int alto = ubic->get_alto();
  if (!tiene_coordenada(c.arriba(alto/2)) || !tiene_coordenada(c.abajo(alto/2))
  || !tiene_coordenada(c.izquierda(ancho/2)) || !tiene_coordenada(c.izquierda(ancho/2))){
      return false;
  }
	for (size_t i = 0; i < elementos.size(); i++){
		if (elementos[i] == ubic){
			continue;
		}
		if (elementos[i]->colisiona(ubic, c) && !elementos[i]->puede_ocupar(ubic)){
			return false;
		}
	}
  return true;
}

bool Mapa::ubicar(Personaje_pc* pj, Coordenada c){
	if (!puede_ubicarse(pj, c)){
		return false;
	}
	personajes_pc[pj->get_id_unico()] = pj;
	return true;
}

bool Mapa::ubicar(Personaje_npc* pj, Coordenada c){
	if (!puede_ubicarse(pj, c)){
		return false;
	}
  personajes_npc[pj->get_id_unico()] = pj;
	return true;
}

bool Mapa::ubicar(Elemento* elem, Coordenada c){
	if (!puede_ubicarse(elem, c)){
		return false;
	}
	elementos.push_back(elem);
	return true;
}

bool Mapa::ubicar(Bala* bala, Coordenada c){
	if (!puede_ubicarse(bala, c)){
		return false;
	}
	elementos.push_back(bala);
	balas.push_back(bala);
	return true;
}

bool Mapa::ubicar(Bloque* bloque, Coordenada c){
	if (!puede_ubicarse(bloque, c)){
		return false;
	}
	elementos.push_back(bloque);
	return true;
}

Personaje* Mapa::obtener_pj(int id_pj){
	if (personajes_pc.find(id_pj) != personajes_pc.end()){
		return personajes_pc[id_pj];
	}
  if (personajes_npc.find(id_pj) != personajes_npc.end()){
		return personajes_npc[id_pj];
	}
	return NULL;
}

void Mapa::update(float tiempo){
	for (size_t j = 0; j < balas.size(); j++){
		balas[j]->update(tiempo, this);
	}
	for (ItPersonajePc it= personajes_pc.begin(); it != personajes_pc.end(); ++it){
		(*it).second->update(tiempo, this);
		interactuar_con_entorno(it->second);
	}
  for (ItPersonajeNpc i= personajes_npc.begin(); i != personajes_npc.end(); ++i){
    (*i).second->update(tiempo, this);
    interactuar_con_entorno(i->second);
  }
}

void Mapa::interactuar_con_entorno(Personaje* pj){
  Coordenada c = pj->get_coordenada();
  for(size_t i = 0; i < elementos.size(); i++){
    if (elementos[i]->colisiona(pj, c)){
      elementos[i]->interactuar(pj);
    }
  }
}

bool Mapa::esta_en_aire(Personaje* personaje){
  size_t alto = personaje->get_alto();
  Coordenada c = personaje->get_coordenada().abajo(alto/2);
  for (size_t i = 0; i < elementos.size(); i++){
    if (elementos[i]->colisiona(personaje, c) && elementos[i]->es_piso()){
      return false;
    }
  }
	return true;
}

bool Mapa::bala_colisiona_con_pj(Bala *bala, Coordenada *coord){
	for (ItPersonajePc it = personajes_pc.begin(); it != personajes_pc.end(); ++it){
		Personaje *p = it->second;
		if (p->colisiona(bala, *coord)){
			return true;
		}
	}
  for (ItPersonajeNpc i = personajes_npc.begin(); i != personajes_npc.end(); ++i){
		Personaje *p = i->second;
		if (p->colisiona(bala, *coord)){
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

void Mapa::agregar_bala(Bala *b){
	balas.push_back(b);
	elementos.push_back(b);
}

void Mapa::quitar_bala(Bala *b){
	ItBalas it_bala = std::find(balas.begin(), balas.end(), b);
	balas.erase(it_bala);
}

void Mapa::agregar_personaje(Personaje_pc *p){
	puerta_boss->sumar_personaje(p->get_id_unico());
	personajes_pc.insert(std::pair<int, Personaje_pc*>(p->get_id_unico(), p));
	std::cout << "ID PJ AGREGADO: " << p->get_id() << "\n";
}

void Mapa::agregar_personaje(Personaje_npc *p){
	personajes_npc.insert(std::pair<int, Personaje_npc*>(p->get_id_unico(), p));
	std::cout << "ID PJ AGREGADO: " << p->get_id() << "\n";
}

void Mapa::quitar_personaje(int id_pj){
	if (personajes_pc.find(id_pj) != personajes_pc.end()){
		puerta_boss->restar_personaje(id_pj);
		personajes_pc.erase(id_pj);
	}
	if (personajes_npc.find(id_pj) != personajes_npc.end()){
		personajes_npc.erase(id_pj);
	}
}


std::vector<Ubicable*> Mapa::devolver_ubicables(){
	std::vector<Ubicable*> ubicables;
	for (size_t i = 0; i < elementos.size(); i++){
    size_t y_elemento = elementos[i]->get_coordenada().obtener_ordenada();
    if ((y_elemento + elementos[i]->get_alto()/2) <= (long_y - TAM_BLOQUE)){
      ubicables.push_back(elementos[i]);
    }
	}
	for (ItPersonajePc it = personajes_pc.begin(); it != personajes_pc.end(); ++it){
		ubicables.push_back(it->second);
	}
  for (ItPersonajeNpc i = personajes_npc.begin(); i != personajes_npc.end(); ++i){
    ubicables.push_back(i->second);
  }
	return ubicables;
}

bool Mapa::ubicar_premio(Coordenada c){
	if (!toca_premio()){
		return true;
	}
	Premio* nuevo_premio = premio_al_azar(c);
	if (!puede_ubicarse(nuevo_premio, c)){
		return false;
	}
	elementos.push_back(nuevo_premio);
	return true;
}

Premio* Mapa::premio_al_azar(Coordenada c){
	size_t resultado = rand() % 10 +1;
	size_t prob_total= 0;
	for (ItPremios it = premios.begin(); it != premios.end(); ++it){
		prob_total += (*it).second->probabilidad_de_crear();
	}
	size_t prob_ant = 0;
	for (ItPremios it = premios.begin(); it != premios.end(); ++it){
		size_t prob_premio = (*it).second->probabilidad_de_crear();
		size_t rango_premio = (prob_premio/prob_total+prob_ant)*10;
		if ((resultado < rango_premio) && (rango_premio < resultado + prob_ant)){
			return (*it).second->crear(c);
		}
		prob_ant = prob_premio/prob_total;
	}
	return NULL;
}

bool Mapa::toca_premio(){
	size_t resultado = rand() % 10 +1;
	size_t probabilidad = 0;
	for (ItPremios it = premios.begin(); it != premios.end(); ++it){
		probabilidad += (*it).second->probabilidad_de_crear();
	}
	return (probabilidad*10 < resultado);
}

void Mapa::cargar_premios_factories(){
	premios[CAPSULA_DE_PLASMA] = new Capsula_de_plasma_factory();
	premios[CAPSULA_DE_ENERGIA] = new Capsula_de_energia_factory();
	premios[NUEVA_VIDA] = new Nueva_vida_factory();
}

void Mapa::ubicar_puerta_boss(Coordenada c){
	puerta_boss = new Puerta_boss(c);
	elementos.push_back(puerta_boss);
}
