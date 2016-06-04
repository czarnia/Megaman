#include "bloque.h"
#include "personaje.h"
#include "escalera.h"
#include "bala.h"
#include "puas.h"
#include "puas_asesinas.h"

#define ALTO 2
#define ANCHO 2
#define TIPO_BLOQUE 0

Bloque::Bloque(Coordenada c) : Elemento(c) {
	id = 0;
	tipo = TIPO_BLOQUE;
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
	std::vector<Coordenada> v;
	v.push_back(c);
	v.push_back(c.arriba(ALTO/2).izquierda(ANCHO/2));
	v.push_back(c.arriba(ALTO/2).derecha(ANCHO/2));
	v.push_back(c.abajo(ALTO/2).izquierda(ANCHO/2));
	v.push_back(c.abajo(ALTO/2).derecha(ANCHO/2));
	return v;
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

Coordenada Bloque::get_coordenada(){
	return coord;
}

int Bloque::get_tipo(){
	return tipo;
}
		
int Bloque::get_id(){
	return id;
}	

Bloque::~Bloque() {}
