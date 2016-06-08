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
		//Dado un juego*, crea un observador_personaje.
		Observador_personaje(Juego* juego);
		//Dado un observable*, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
