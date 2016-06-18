#ifndef FIREMAN_H
#define FIREMAN_H

#include "personaje_npc.h"
#include "strategy_mover_fireman.h"
#include <vector>

class Arma_fireman;
class StrategyMoverFireman;

class Fireman: public Personaje_npc{
	private:
		Mapa *mapa;
		size_t tiempo_pasado;
		Arma_fireman* arma;
		bool atacando;
		StrategyMoverFireman movimiento;
	public:
		//Dado un Mapa*, una coordenada, un Arma_fireman* 
		//y un id, crea un fireman.
		Fireman(Mapa *mapa, Coordenada c, Arma_fireman* arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(size_t tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(size_t tiempo);
		
		friend class StrategyMoverFireman;
};

#endif //FIREMAN_H
