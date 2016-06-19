#ifndef OBSERVADOR_UBICABLE_H
#define OBSERVADOR_UBICABLE_H

#include "observador.h"
#include "coordenada.h"
class Juego;

class Observador_ubicable:
public Observador{
	protected:
		Coordenada coordenada;
		Juego* juego;
	public:
		Observador_ubicable();
		//Dado un juego y una coordenada, crea a un observador ubicable.
		Observador_ubicable(Juego* juego, Coordenada coord);
		//Dado un observable, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_UBICABLE_H
