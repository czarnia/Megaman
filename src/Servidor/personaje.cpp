#include "personaje.h"

#define PERDER_VIDA -1

bool Personaje::ubicar(Mapa &mapa){
	mapa.ocupar(this, coordenadas_ocupadas);
}

void Personaje::mover(Mapa &mapa, StrategyMover &accion_mover){
	//Dentro del accion_mover hay que checkear si se puede actualizar
	//cada coordenada que se quiere actualizar
	//verificando si el objeto se esta "moviendo sobre su yo anterior" si es que el personaje 
	//ocupa mas de una celda:
	//if (accion_mover.mover(mapa, coordenadas_ocupadas)){ 
		//this->ubicar(mapa, coordenadas_ocupadas); //Se actualiza el mapa.
	//}
}

bool Personaje::esta_vivo(){
	return vidas.empty();
}

void Personaje::perder_vida(int porcentaje = PERDER_VIDA){
	if (porcentaje == PERDER_VIDA){
		vidas.erase(0);
	}else{
		vidas[0].perder(porcentaje);
	}
}

