#include "observador_personaje.h"
#include <iostream>
#include <sstream>
#include "personaje.h"

Observador_personaje::Observador_personaje(Juego* juego, Coordenada coord): 
Observador_ubicable(juego, coord){
	cantidad_vidas = 0;
	porcentaje_vida = 0;
	energia = 0;
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

