#ifndef OBSERVADOR_UBICABLE_H
#define OBSERVADOR_UBICABLE_H

#include "observador.h"
#include "juego.h"
class Juego;

class Observador_ubicable: public Observador{
	protected:
		Juego* juego;
		Coordenada coordenada;
	public:
		Observador_ubicable(Juego* juego, Coordenada *coordenada);
		virtual void update(Observable *obs);	
};

#endif //OBSERVADOR_UBICABLE_H
