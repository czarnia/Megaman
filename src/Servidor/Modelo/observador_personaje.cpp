#include "observador_personaje.h"
#include <iostream>
#include <sstream>

Observador_personaje::Observador_personaje(Juego* juego, Personaje* pj):
juego(juego), posicion_inicial(pj->get_coordenada()){
	cantidad_vidas = pj->get_cantidad_vidas();
	porcentaje_vida = pj->get_porcentaje_vida();
	energia = pj->get_energia();
}

void Observador_personaje::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	int id = personaje->get_id();
	int tipo = personaje->get_tipo();
	if (!personaje->esta_vivo()){
		std::cout << "OBSERVER_P: PERSONAJE MURIO\n";
		juego->murio_personaje(tipo, id);
	}else{
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
		if (porcentaje_vida != personaje->get_porcentaje_vida()){
			std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO % VIDA\n";
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_porcentaje_vida(tipo, id, cantidad_vidas);
		}
		if (energia != personaje->get_energia()){
			std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO ENERGIA\n";
			energia = personaje->get_energia();
			juego->actualizo_energia(tipo, id, energia);
		}
	}
}
