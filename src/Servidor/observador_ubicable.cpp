#include "observador_ubicable.h"
#include <iostream>
#include <sstream>

Observador_ubicable::Observador_ubicable(Juego* juego, 
Coordenada *coord_inicial): juego(juego),
coordenada(coord_inicial->obtener_abscisa(),
coord_inicial->obtener_ordenada()){}

void Observador_ubicable::update(Observable *obs){
	Ubicable *ubicable = (Ubicable*)obs;
	int id = ubicable->get_id();
	int tipo = ubicable->get_tipo();
	//HAY QUE AVISARLE AL CLIENTE QUE SE ACTUALIZO LA COORDENADA VIEJA TAMBIEN.
	if (!(coordenada == ubicable->get_coordenada())){
		std::cout << "OBSERVER_UBICABLE: UBICABLE ACTUALIZO POSICION\n";
		std::stringstream inicial;
		inicial << coordenada.obtener_abscisa() << "," << coordenada.obtener_ordenada() << "\n";
		std::cout << "OBSERVER_UBICABLE: POS INICIAL " + inicial.str() + "\n";
		//Un personaje p actualizo su posicion.
		int x = (int)ubicable->get_coordenada().obtener_abscisa();
		int y = (int)ubicable->get_coordenada().obtener_ordenada();
		std::stringstream pos_final;
		pos_final << x << "," << y << "\n";
		std::cout << "OBSERVER_UBICABLE: POS FINAL " + pos_final.str() + "\n";
		juego->actualizo_posicion(tipo, id, x, y);
		coordenada = ubicable->get_coordenada();
	}
}
