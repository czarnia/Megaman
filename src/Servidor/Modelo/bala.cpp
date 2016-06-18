#include "bala.h"
#include "escalera.h"
#include "personaje.h"
#include "puas.h"
#include "bloque.h"
#include <iostream>

#define TIEMPO_MOVER 5
#define VELOCIDAD 4
#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4

#define AVANZA 1
#define RETROCEDE -1
#define SUBE -1
#define BAJA 1

Bala::Bala(int dir_x, int dir_y, Coordenada c, int tipo, int id):
Elemento(c, tipo, id),
direccion_x(dir_x),
direccion_y(dir_y)
{
	alto = 0;
	ancho = 0;
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

bool Bala::puede_ocupar(Premio* premio){
	return true;
}

bool Bala::puede_ocupar(Bloque* bloque){
	return false;
}

bool Bala::puede_ocupar(Puas* puas){
	return true;
}

bool Bala::puede_ocupar(Personaje* pj){
	return true;
}

void Bala::update(float tiempo, Mapa* mapa){
	tiempo_pasado += tiempo;
	size_t delta_x = 0;
	size_t delta_y = 0;
	bool llegue = ((direccion_x == 0) && (direccion_y == 0));
	//bool hay_colision = false;
	Coordenada actual = coord;
	if (tiempo_pasado >= TIEMPO_MOVER){
		if (impacto){
			//si la bala impacto con un objeto en el update anterior
			//se destruye en este update;
			//std::cout << "BALA: IMPACTO, VA A -1, -1.\n";
			actual = Coordenada(-1, -1);
			mapa->quitar_bala(this);
		}
		while (!impacto && !llegue){
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
				impacto = !mapa->puede_ubicarse(this, actual);
				impacto = impacto || mapa-> bala_colisiona_con_pj(this, &actual);
				if (impacto){
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

bool Bala::colisiona(Ubicable *ubic, Coordenada c){
		size_t x = coord.obtener_abscisa();
		size_t y = coord.obtener_ordenada();
		size_t alto = ubic->get_alto();
		size_t ancho = ubic->get_ancho();
		size_t ancho_max = c.derecha(ancho/2).obtener_abscisa();
		size_t ancho_min = c.izquierda(ancho/2).obtener_abscisa();
		size_t alto_min = c.arriba(alto/2).obtener_ordenada();
		size_t alto_max = c.abajo(alto/2).obtener_ordenada();
		return (x >= ancho_min) && (x <= ancho_max) && (y >= alto_min) && (y <= alto_max);
}

void Bala::interactuar(Personaje* pj){
	pj->recibir_ataque(this);
}


bool Bala::es_piso(){
	return false;
}
