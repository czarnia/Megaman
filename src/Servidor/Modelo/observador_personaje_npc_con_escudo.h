#ifndef OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H
#define OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H

#include "observador_personaje_npc.h"

class Observador_personaje_npc_con_escudo:
public Observador_personaje_npc{
	public:
		bool bajo_escudo;
	public:
		//Dado un juego y una coordenada, crea a un
		//observador de personaje NPC con escudo.
		Observador_personaje_npc_con_escudo(Juego* juego, Personaje *personaje);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_NPC_CON_ESCUDO_H
