#ifndef SPARKMAN_H
#define SPARKMAN_H

#include "personaje_npc.h"
#include "strategy_mover_sparkman.h"
#include <vector>

class Arma_sparkman;
class StrategyMoverSparkman;

class Sparkman: public Personaje_npc{
	private:
		Mapa *mapa;
		size_t tiempo_pasado;
		Arma_sparkman* arma;
		StrategyMoverSparkman movimiento;
	public:
		//Dado un Mapa*, una coordenada, un Arma_sparkman* y un id, crea a un spark-
		//man.
		Sparkman(Mapa *mapa, Coordenada c, Arma_sparkman* arma, int id);
		//Dado un Mapa* y una dirección, ataca en la misma.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo y un Mapa*, realiza un ataque.
		virtual void mover(size_t tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(size_t tiempo);

		friend class StrategyMoverSparkman;
	private:
		std::vector<Bala*> balas_ataque();
};

#endif //SPARKMAN_H
