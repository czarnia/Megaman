#include "observador_personaje_pc.h"
#include <iostream>
#include <sstream>

Observador_personaje_pc::Observador_personaje_pc(Juego* juego, Personaje* pj):
Observador_personaje(juego, pj){
	energia = pj->get_energia();
}

void Observador_personaje_pc::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	if (energia != personaje->get_energia()){
		std::cout << "OBSERVER_P: PERSONAJE ACTUALIZO ENERGIA\n";
		energia = personaje->get_energia();
		int tipo = personaje->get_tipo();
		int id = personaje->get_id();
		juego->actualizo_energia(tipo, id, energia);
	}
	Observador_personaje::update(obs);
}
