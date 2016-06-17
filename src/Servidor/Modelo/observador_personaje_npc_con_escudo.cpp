#include "observador_personaje_npc_con_escudo.h"
#include <iostream>
#include <sstream>

Observador_personaje_npc_con_escudo::
Observador_personaje_npc_con_escudo(Juego* juego, 
Personaje_npc_con_escudo *personaje):
Observador_personaje_npc(juego, personaje){
	esta_bajo_escudo = personaje->esta_bajo_escudo();
}

void Observador_personaje_npc_con_escudo::update(Observable *obs){
	Personaje_npc_con_escudo *personaje = (Personaje_npc_con_escudo*)obs;
	if (personaje->esta_bajo_escudo() != esta_bajo_escudo){
		esta_bajo_escudo = personaje->esta_bajo_escudo();
		juego->personaje_update_escudo(personaje->get_tipo(),personaje->get_id(), esta_bajo_escudo);
	}
	if (!personaje->esta_vivo()){ //TODO: esto debería estar en observador_personaje_npc
		std::cout << "OBSERVER_P_NPC: PERSONAJE MURIO\n";
		Mapa* m = juego->get_mapa();
		m->ubicar_premio(coordenada);
	}
	Observador_personaje::update(obs);
}
