#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "observador.h"
#include "juego.h"
class Juego;

class Observador_personaje: 
public Observador{
	protected:
		Juego* juego;
		int cantidad_vidas;
		int porcentaje_vida;
		int energia;
	public:
		Observador_personaje(Juego* juego);
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
