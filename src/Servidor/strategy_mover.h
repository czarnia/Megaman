#ifndef STRATEGY_MOVER_H
#define STRATEGY_MOVER_H

#include "mapa.h"
#include <string>

class Personaje;

class StrategyMover{
	public:
		StrategyMover(Mapa *mapa, Personaje *p, bool aplicar_gravedad);
		void agregar_direccion(int dir);
		void mover(size_t tiempo);
		//virtual Coordenada *nueva_coordenada(Coordenada &coord);
	protected:
		Mapa *mapa;
		Personaje *personaje;
		bool aplicar_gravedad;
		float gravedad;
		std::vector<int> direcciones;
};

#endif //STRATEGY_MOVER_H

