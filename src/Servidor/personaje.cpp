#include "personaje.h"

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

