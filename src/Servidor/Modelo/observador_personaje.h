#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "observador_ubicable.h"
#include "juego.h"
class Juego;

class Observador_personaje:
public Observador_ubicable{
	protected:
		int cantidad_vidas;
		int porcentaje_vida;
	public:
		//Dado un juego*, crea un observador_personaje.
		Observador_personaje(Juego* juego, Coordenada coord);
		//Dado un observable*, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
