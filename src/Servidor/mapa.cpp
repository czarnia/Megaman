#include "mapa.h"
#include "coordenada.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"
#include "megaman.h"
#include "bala.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

#include <algorithm>


#define TAM_BLOQUE 1

typedef std::vector<Coordenada>::iterator ItBloques;
typedef std::pair<std::string, Megaman*> IdPersonaje;

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
	std::vector<Coordenada*> personajes;
	personajes.push_back(new Coordenada(3,6));

	return personajes;
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
	size_t i;
	for (i = 0; i < 3; i++){
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

Mapa::Mapa(size_t tamanio){
	tam = tamanio;
	this->cargar();
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
	return personajes[id_pj];
}

std::vector<Actualizable*> Mapa::obtener_actualizables(){
	std::vector<Actualizable*> v;
  std::map<std::string,Personaje*>::iterator i;
  for (i = personajes.begin(); i != personajes.end(); i++){
    v.push_back(i->second);
  }
	for (size_t j = 0; j < balas.size(); j++){
		v.push_back(balas[j]);
	}
  return v;
}

bool Mapa::esta_en_aire(Coordenada coord, size_t alto){
	return !hay_tierra(coord.abajo((alto/2)+1)); //asumo los bloques son de tamaño 2
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
	int x = coordenada.obtener_abscisa();
	int y = coordenada.obtener_ordenada();
	bool tiene_coordenada = (0 <= x) && (x <= tam) && (0 <= y) && (y <= tam);
	return tiene_coordenada;
}

void Mapa::cargar(){
	bloques = coord_tierras();
	coord_iniciales_personajes = coord_personajes(); 
}

void Mapa::agregar_personaje(Personaje *p){
	personajes.insert(std::pair<std::string, Personaje*>(p->devolver_id(), p));
}

void Mapa::quitar_personaje(std::string id){
	personajes.erase(id);
}
