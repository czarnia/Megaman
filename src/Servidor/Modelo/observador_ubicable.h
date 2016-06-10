#ifndef OBSERVADOR_UBICABLE_H
#define OBSERVADOR_UBICABLE_H

#include "observador.h"
#include "juego.h"
class Juego;

class Observador_ubicable: 
public Observador{
	protected:
		Juego* juego;
		Coordenada coordenada;
	public:
		//Dado un juego y una coordenada, crea a un observador ubicable.
		Observador_ubicable(Juego* juego, Coordenada *coordenada);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_UBICABLE_H
