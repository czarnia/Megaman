#ifndef SNIPPER_H
#define SNIPPER_H

#include "personaje_npc_con_escudo.h"
#include "strategy_mover_snipper.h"

class Arma_minion;

class Snipper : public Personaje_npc_con_escudo {
	protected:
		Arma_minion* arma;
		StrategyMoverSnipper movimiento;
	public:
		//Dado un mapa*, una coordenada, un Arma_minion* y un id, crea a un Snipper.
		Snipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Devuelve true si el Snipper está descubierto, false en caso contrario.
		bool esta_bajo_escudo();
		//Devuelve true si el Snipper es vulnerable al ataque, false en caso contra-
		//rio.
		bool es_vulnerable(Bala* ataque);
		//Hace que el personaje ataque.
		void atacar(int dir, Mapa* mapa);
		//Le hace un update al personaje.
		virtual void update(float tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Hace que el personaje se mueva;
		void mover(float tiempo, Mapa* mapa);

		friend class StrategyMoverSnipper;
};

#endif //SNIPPER_H
