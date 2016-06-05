#include "bala.h"
#include "escalera.h"
#include "personaje.h"
#include "puas.h"
#include "puas_asesinas.h"
#include "bloque.h"

#define TIEMPO_MOVER 5
#define VELOCIDAD 4
#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4

#define AVANZA 1
#define RETROCEDE -1
#define SUBE 1
#define BAJA -1

Bala::Bala(int dir_x, int dir_y, Coordenada c, int tipo, int id):
Elemento(c, tipo, id),
direccion_x(dir_x),
direccion_y(dir_y)
{
	impacto = false;
}

bool Bala::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Bala::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Bala::puede_ocupar(Bala* bala){
	return true;
}

bool Bala::puede_ocupar(Escalera* esc){
	return true;
}

bool Bala::puede_ocupar(Bloque* bloque){
	return false;
}

bool Bala::puede_ocupar(Puas* puas){
	return true;
}

bool Bala::puede_ocupar(Puas_asesinas* puas){
	return true;
}

bool Bala::puede_ocupar(Personaje* pj){
	return true;
}

void Bala::update(size_t tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	size_t delta_x = 0;
	size_t delta_y = 0;
	bool llegue = ((direccion_x == 0) && (direccion_y == 0));
	bool hay_colision = false;
	Coordenada actual = coord;
	if (tiempo_pasado >= TIEMPO_MOVER){
		if (impacto){
			//si la bala impacto con un objeto en el update anterior
			//se destruye en este update;
			actual = Coordenada(-1, -1);
		}
		while (!impacto && !llegue && !hay_colision){
			if ((direccion_x != 0) && (delta_x != VELOCIDAD)){
				actual = (direccion_x == DERECHA)? actual.derecha() : actual.izquierda();
				delta_x += (direccion_x == DERECHA)? AVANZA : RETROCEDE;
			}
			if ((direccion_y != 0) && (delta_y != VELOCIDAD)){
				actual = (direccion_x == ABAJO)? actual.abajo() : actual.arriba();
				delta_y += (direccion_y == ABAJO)? BAJA : SUBE;
			}
			llegue = !(((direccion_x != 0) && (delta_x != VELOCIDAD))
					    || ((direccion_y != 0) && (delta_y != VELOCIDAD)));

			if (!llegue){
				hay_colision = !mapa->puede_ubicarse(this, actual);
				hay_colision = hay_colision || mapa->hay_personaje(&actual);
				if (hay_colision){
					impacto = true;
					direccion_x = 0;
					direccion_y = 0;
				}
			}
		}
		if (!(actual == coord)){
			coord = actual;
			notificar_observadores();
		}
	}
}

void Bala::interactuar(Personaje* pj){
	pj->recibir_ataque(this);
}

Coordenada Bala::get_coordenada(){
	return coord;
}

int Bala::get_id(){
	return id;
}

int Bala::get_tipo(){
	return 0;
}

void Bala::agregar_observador(Observador_ubicable *observador){
	Observable::agregar_observador(observador);
}

void Bala::quitar_observador(Observador_ubicable *observador){
	Observable::quitar_observador(observador);
}

void Bala::notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

std::vector<Coordenada> Bala::coordenadas(){
	return coordenadas(coord);
}

std::vector<Coordenada> Bala::coordenadas(Coordenada c){
	std::vector<Coordenada> v;
	v.push_back(c);
	return v;
}
