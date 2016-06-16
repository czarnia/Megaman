#ifndef OBSERVADOR_PERSONAJE_NPC_H
#define OBSERVADOR_PERSONAJE_NPC_H

#include "observador_personaje.h"

class Observador_personaje_npc:
public Observador_personaje{
	public:
		//Dado un juego y una coordenada, crea a un 
		//observador de personaje NPC.
		Observador_personaje_npc(Juego* juego, Coordenada coord);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_NPC_H


