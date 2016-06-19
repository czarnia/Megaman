#include "observador_ubicable.h"
#include "juego.h"
#include "ubicable.h"
#include <iostream>
#include <sstream>

Observador_ubicable::Observador_ubicable():
coordenada(0,0){}

Observador_ubicable::Observador_ubicable(Juego* juego, Coordenada coord):
coordenada(coord.obtener_abscisa(),
coord.obtener_ordenada()),
juego(juego){}

void Observador_ubicable::update(Observable *obs){
	Ubicable *ubicable = (Ubicable*)obs;
	int id = ubicable->get_id();
	int tipo = ubicable->get_tipo();
	if (!(coordenada == ubicable->get_coordenada())){
		int alto = ubicable->get_alto();
		int ancho = ubicable->get_ancho();
		Coordenada c = ubicable->get_coordenada().arriba(alto/2).izquierda(ancho/2);
		int x = c.obtener_abscisa();
		int y = c.obtener_ordenada();
		std::stringstream pos_final;

		juego->actualizo_posicion(tipo, id, x, y);
		coordenada = ubicable->get_coordenada();
	}
}
