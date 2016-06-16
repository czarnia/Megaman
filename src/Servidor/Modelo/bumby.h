#ifndef BUMBY_H
#define BUMBY_H

#include "personaje.h"
#include "strategy_mover_bumby.h"

class Arma_minion;

class Bumby : public Personaje {
	private:
		StrategyMoverBumby mover_bumby;
		Arma_minion* arma;
	public:
		//Dado un Mapa*, una Coordenada, un Arma_minion* y un id, se crea un bumby.
		Bumby(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Hace que el personaje ataque.
		virtual void atacar(int dir, Mapa* mapa);		//NO TIENE SENTIDO PARA NPCs!
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Hace que el personaje se mueva;
		virtual void mover(size_t tiempo, Mapa* mapa);  //NO TIENE SENTIDO PARA NPCs!
		//Dada una direccion representada como un int, saca un movimiento en dicha
		//direccion.
		virtual void sacar_movimiento(int direccion);	//NO TIENE SENTIDO PARA NPCs!
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		virtual void agregar_movimiento(int direccion);	//NO TIENE SENTIDO PARA NPCs!
};

#endif //BUMBY_H
