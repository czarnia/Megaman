#include "strategy_mover_con_gravedad.h"

#include <iostream>

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
	//POR EL MOMENTO LA VELOCIDAD SON CELDAS A MOVER:
	int total_celdas = personaje->get_velocidad();
	//aplicar gravedad y llamar al mover, 
	//considerando velocidad del personaje.
	bool cayendo = false;
	bool mover = true;
	int celdas_movidas = 0;
	std::cout << "ENTREE!\n";
	while (mover || cayendo){
		std::cout << "personaje puede caer:" << personaje->tiene_estrategia(caer->get_nombre()) << "\n";
		if (!personaje->tiene_estrategia(caer->get_nombre())){
			std::cout << "INTENTO CAER...\n";
			//Si el personaje entra en una escalera, por ejemplo,
			//tiene una estrategia para bajar y no quiero que caiga.
			cayendo = caer->mover(personaje);
			std::cout << "INTENTE CAER!\n";
			if (mover && cayendo){ 
				mover = false;
			}
			if (cayendo) std::cout << "ME CAIGO!!!\n";
		}
		if ((!cayendo) && (celdas_movidas < total_celdas)){
			//TODO:aca el mover tiene que considerar la velocidad porque no se esta 
			//llamando al ejecutar de StrategyMover que ya la considera
			//para movimientos sin gravedad.
			std::cout << "MUEVO!\n";
			mover = movimiento->mover(personaje);
			celdas_movidas++; 
		}
	}
	return !(mover || cayendo);
}

StrategyMoverConGravedad::~StrategyMoverConGravedad(){
	delete caer;
}
