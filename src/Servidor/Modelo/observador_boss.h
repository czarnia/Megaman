#ifndef OBSERVADOR_BOSS_H
#define OBSERVADOR_BOSS_H

#include "observador_personaje_npc.h"

class Observador_boss : public Observador_personaje_npc{
	public:
		//Dado un juego y una coordenada, crea a un
		//observador de boss.
		Observador_boss(Juego* juego, Personaje_npc *personaje);
		//Recibe un observable y actualiza su estado.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_BOSS_H
