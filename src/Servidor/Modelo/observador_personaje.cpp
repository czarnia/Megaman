#include "observador_personaje.h"
#include <iostream>
#include <sstream>

Observador_personaje::Observador_personaje(){}

Observador_personaje::Observador_personaje(Juego* juego, Personaje* pj):
Observador_ubicable(juego, pj->get_coordenada()){
	porcentaje_vida = pj->get_porcentaje_vida();
	estado_actual = pj->get_estado_actual();
}

void Observador_personaje::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	int id = personaje->get_id();
	int tipo = personaje->get_tipo();
	if (!personaje->esta_vivo()){
		std::cout << "OBSERVER_P: PERSONAJE MURIO\n";
		juego->murio_personaje(personaje);
	}else{
		if (porcentaje_vida != personaje->get_porcentaje_vida()){
			std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO % VIDA\n";
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_porcentaje_vida(tipo, id, porcentaje_vida);
		}
		Observador_ubicable::update(obs);
	}
	if (estado_actual != personaje->get_estado_actual()){
		juego->actualizo_estado_personaje(tipo, id,
		personaje->get_estado_actual());
		estado_actual = personaje->get_estado_actual();
	}
}
