#include "observador_personaje_npc_con_escudo.h"

Observador_personaje_npc_con_escudo::
Observador_personaje_npc_con_escudo(Juego* juego, Personaje *personaje):
Observador_personaje_npc(juego, personaje){}

void Observador_personaje_npc_con_escudo::update(Observable *obs){
	//Personaje *personaje = (Personaje*)obs;
	//if (personaje->bajo_escudo() != bajo_escudo){
		//bajo_escudo = personaje->bajo_escudo();
		//juego->personaje_update_escudo(personaje->get_tipo(), 
		//personaje->get_id(), bajo_escudo);
	//}
	Observador_personaje::update(obs);
}

