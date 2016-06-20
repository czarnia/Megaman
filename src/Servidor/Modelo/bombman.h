#ifndef BOMBMAN_H
#define BOMBMAN_H

#include "personaje_npc.h"
#include "strategy_mover_bombman.h"

class Arma_bombman;

class Bombman: public Personaje_npc{
	private:
		Mapa *mapa;
		float tiempo_pasado;
		Arma_bombman* arma;
		StrategyMoverBombman movimiento;
	public:
		//Dado un Mapa*, una coordenada, un Arma_bombman* y un id, crea un bombman.
		Bombman(Mapa *mapa, Coordenada c, Arma_bombman* arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(float tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(float tiempo);
		
		friend class StrategyMoverBombman;
};

#endif //BOMBMAN_H
