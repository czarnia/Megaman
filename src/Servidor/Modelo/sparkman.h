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
		Sparkman(Mapa *mapa, Coordenada c, Arma_sparkman* arma, int id);
		virtual void atacar(int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
		
		friend class StrategyMoverSparkman;
	private:
		std::vector<Bala*> balas_ataque();
};

#endif //SPARKMAN_H
