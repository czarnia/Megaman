#ifndef OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H
#define OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H

#include "observador_personaje_npc.h"
#include "personaje_npc_con_escudo.h"

class Observador_personaje_npc_con_escudo:
public Observador_personaje_npc{
	public:
		bool esta_bajo_escudo;
	public:
		//Dado un juego y un personaje npc con escudo, crea a un
		//observador de personaje NPC con escudo.
		Observador_personaje_npc_con_escudo(Juego* juego, 
		Personaje_npc_con_escudo *personaje);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H
