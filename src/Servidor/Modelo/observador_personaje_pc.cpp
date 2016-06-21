#include "observador_personaje_pc.h"
#include <iostream>
#include <sstream>

enum estado{RESPAWNEANDO, MURIENDO, CORRIENDO, SALTANDO, IDLE,
	DISPARANDO, ESCALANDO};

Coordenada Observador_personaje_pc::coordenada_respawn(0,0);

Observador_personaje_pc::Observador_personaje_pc(){}

Observador_personaje_pc::Observador_personaje_pc(Juego* juego, Personaje_pc* pj):
Observador_personaje(juego, pj){
	cantidad_vidas = pj->get_cantidad_vidas();
	energia = pj->get_energia();
}

void Observador_personaje_pc::update(Observable *obs){
	Personaje_pc *personaje = (Personaje_pc*)obs;
	int id = personaje->get_id();
	int tipo = personaje->get_tipo();
	if (energia != personaje->get_energia()){
		std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO ENERGIA\n";
		energia = personaje->get_energia();
		juego->actualizo_energia(tipo, id, energia);
	}
	if (cantidad_vidas != personaje->get_cantidad_vidas() && personaje->esta_vivo()){
		std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO CANTIDAD VIDAS "<< personaje->get_cantidad_vidas() <<"\n";
		cantidad_vidas = personaje->get_cantidad_vidas();
		porcentaje_vida = personaje->get_porcentaje_vida();
		juego->actualizo_cantidad_vidas(tipo, id, cantidad_vidas);

		personaje->respawn(Observador_personaje_pc::coordenada_respawn);
		int alto = personaje->get_alto();
		int ancho = personaje->get_ancho();
		Coordenada c = coordenada_respawn.arriba(alto/2).izquierda(ancho/2);
		int x = c.obtener_abscisa();
		int y = c.obtener_ordenada();
		juego->actualizo_posicion(tipo, id, x, y);
	}
	Observador_personaje::update(obs);
}

void Observador_personaje_pc::set_coordenada_respawn(Coordenada coord){
	Observador_personaje_pc::coordenada_respawn = coord;
}
