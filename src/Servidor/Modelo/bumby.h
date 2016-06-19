#ifndef BUMBY_H
#define BUMBY_H

#include "personaje_npc.h"
#include "strategy_mover_bumby.h"

class StrategyMoverBumby;
class Arma_minion;

class Bumby : public Personaje_npc {
	private:
		StrategyMoverBumby mover_bumby;
		Arma_minion* arma;
	public:
		//Dado un Mapa*, una Coordenada, un Arma_minion* y un id, se crea un bumby.
		Bumby(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Hace que el personaje ataque.
		virtual void atacar(int dir, Mapa* mapa);
		//Le hace un update al personaje.
		virtual void update(float tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Hace que el personaje se mueva;
		virtual void mover(size_t, Mapa* mapa); 

		friend class StrategyMoverBumby;
};

#endif //BUMBY_H
