#ifndef OBSERVADOR_PERSONAJE_PC_H
#define OBSERVADOR_PERSONAJE_PC_H

#include "observador_personaje.h"

class Observador_personaje_pc:
public Observador_personaje{
	protected:
		int energia;
	public:
		//Dado un juego y una coordenada, crea a un 
		//observador de personaje PC.
		Observador_personaje_pc(Juego* juego, Personaje *personaje);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_PC_H