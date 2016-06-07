#include "bloque.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include "puas_asesinas.h"
#include <algorithm>
#include <vector>
#define ALTO 2
#define ANCHO 2
#define TIPO_BLOQUE 10

Bloque::Bloque(Coordenada c) : Elemento(c, TIPO_BLOQUE) {
	alto = ALTO;
	ancho = ANCHO;
}

bool Bloque::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Bloque::puede_ocupar(Personaje* pj){
	return false;
}

bool Bloque::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Bloque::puede_ocupar(Bloque* bloque){
	return false;
}

bool Bloque::puede_ocupar(Bala* bala){
	return false;
}

bool Bloque::puede_ocupar(Escalera* esc){
	return false;
}

bool Bloque::puede_ocupar(Puas* puas){
	return false;
}

bool Bloque::puede_ocupar(Puas_asesinas* puas){
	return false;
}

void Bloque::interactuar(Personaje *pj){} //Los bloques no interactuan!

std::vector<Coordenada> Bloque::coordenadas(Coordenada c){
	std::vector<Coordenada> s_coord;
	Coordenada coord_aux(0,0);
	for (int i = 0; i <= alto/2; i++){
		for (int j = 0; j <= ancho/2; j++){
			coord_aux = c.arriba(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(c.arriba(i).izquierda(j));
			} 
			coord_aux = c.arriba(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(c.arriba(i).derecha(j));
			}
			coord_aux = c.abajo(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(c.abajo(i).izquierda(j));
			}
			coord_aux = c.abajo(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(c.abajo(i).derecha(j));
			}
			
		}
	}
	
	return s_coord;
}

std::vector<Coordenada> Bloque::coordenadas(){
	return coordenadas(coord);
}

void Bloque::notificar_observadores(){}

void Bloque::agregar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

void Bloque::quitar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

Bloque::~Bloque() {}
