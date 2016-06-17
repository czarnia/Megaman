#include "observador_personaje_npc_con_escudo.h"
#include <iostream>
#include <sstream>

Observador_personaje_npc_con_escudo::
Observador_personaje_npc_con_escudo(Juego* juego, Personaje_npc *personaje):
Observador_personaje_npc(juego, personaje){}

void Observador_personaje_npc_con_escudo::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	//if (personaje->bajo_escudo() != bajo_escudo){
		//bajo_escudo = personaje->bajo_escudo();
		//juego->personaje_update_escudo(personaje->get_tipo(),
		//personaje->get_id(), bajo_escudo);
	//}
	if (!personaje->esta_vivo()){ //TODO: esto debería estar en observador_personaje_npc
		std::cout << "OBSERVER_P_NPC: PERSONAJE MURIO\n";
		Mapa* m = juego->get_mapa();
		m->ubicar_premio(coordenada);
	}
	Observador_personaje::update(obs);
}
