#ifndef OBSERVADOR_PERSONAJE_NPC_H
#define OBSERVADOR_PERSONAJE_NPC_H

#include "observador_personaje.h"
#include "personaje_npc.h"

class Observador_personaje_npc:
public Observador_personaje{
	public:
		//Dado un juego y una coordenada, crea a un
		//observador de personaje NPC.
		Observador_personaje_npc(Juego* juego, Personaje_npc *personaje):
		Observador_personaje(juego, personaje){}
};

#endif //OBSERVADOR_PERSONAJE_NPC_H
