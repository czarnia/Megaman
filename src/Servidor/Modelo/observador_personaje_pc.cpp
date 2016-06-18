#include "observador_personaje_pc.h"
#include <iostream>
#include <sstream>

enum estado{RESPAWNEANDO, MURIENDO, CORRIENDO, SALTANDO, IDLE, 
	DISPARANDO, ESCALANDO};

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
	if (cantidad_vidas != personaje->get_cantidad_vidas()){
		std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO CANTIDAD VIDAS\n";
		cantidad_vidas = personaje->get_cantidad_vidas();
		porcentaje_vida = personaje->get_porcentaje_vida();
		juego->actualizo_cantidad_vidas(tipo, id, cantidad_vidas);

		personaje->respawn(posicion_inicial);
		int alto = personaje->get_alto();
		int ancho = personaje->get_ancho();
		Coordenada c = posicion_inicial.arriba(alto/2).izquierda(ancho/2);
		int x = c.obtener_abscisa();
		int y = c.obtener_ordenada();
		juego->actualizo_posicion(tipo, id, x, y);
	}
	Observador_personaje::update(obs);
}
