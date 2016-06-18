#ifndef OBSERVADOR_PERSONAJE_PC_H
#define OBSERVADOR_PERSONAJE_PC_H

#include "observador_personaje.h"
#include "personaje_pc.h"

class Observador_personaje_pc:
public Observador_personaje{
	protected:
		int energia;
		int accion_actual;
		size_t cantidad_vidas;
	public:
		//Dado un juego y una coordenada, crea a un 
		//observador de personaje PC.
		Observador_personaje_pc(Juego* juego, Personaje_pc *personaje);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_PC_H
