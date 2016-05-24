#include "strategy_mover_con_gravedad.h"

StrategyMoverConGravedad::StrategyMoverConGravedad(Mapa &mapa, StrategyMover *movimiento):
StrategyMover(mapa),
movimiento(movimiento){
	caer = new StrategyMoverAbajo(mapa);
}

std::string StrategyMoverConGravedad::get_nombre(){
	return movimiento->get_nombre();
}

Coordenada* StrategyMoverConGravedad::nueva_coordenada(Coordenada &coord){
	return movimiento->nueva_coordenada(coord);
}

bool StrategyMoverConGravedad::ejecutar(Personaje *personaje){
	//aplicar gravedad y llamar al mover, 
	//considerando velocidad del personaje.
	bool cayendo = false;
	bool mover = true;
	while (mover || cayendo){
		if (!personaje->tiene_estrategia(caer->get_nombre())){
			//Si el personaje entra en una escalera, por ejemplo,
			//tiene una estrategia para bajar y no quiero que caiga.
			cayendo = caer->ejecutar(personaje);
		}
		if (!cayendo){
			//TODO:aca el mover tiene que considerar la velocidad porque no se esta 
			//llamando al ejecutar de StrategyMover que ya la considera
			//para movimientos sin gravedad.
			mover = movimiento->ejecutar(personaje); 
		}
	}
	return !(mover || cayendo);
}

StrategyMoverConGravedad::~StrategyMoverConGravedad(){
	delete caer;
}
