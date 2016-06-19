#ifndef STRATEGY_MOVER_MEGAMAN_H
#define STRATEGY_MOVER_MEGAMAN_H

#include "strategy_mover_personaje_pc.h"
#include "megaman.h"
#include "coordenada.h"

class StrategyMoverMegaman : public StrategyMoverPersonajePc{
	private:
		int velocidad_x;
		int velocidad_y;
	public:
		//Crea un StrategyMoverMegaman.
		StrategyMoverMegaman();
		//Dado un Mapa*, un Personaje_pc* y un tiempo, hace que el segundo se mueva.
		virtual void mover(Mapa *mapa, Personaje_pc *pj, size_t tiempo);
		//Dado un Personaje_pc*, le agrega un movimiento.
		void agregar_movimiento(Personaje_pc *pj, int dir);
		//Dado un Personaje_pc*, le saca un movimiento.
		void sacar_movimiento(Personaje_pc *pj, int dir);
		//Destructor del StrategyMoverMegaman.
		~StrategyMoverMegaman();
};

#endif //STRATEGY_MOVER_MEGAMAN_H
