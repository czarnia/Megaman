#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "observador_ubicable.h"
#include "juego.h"
#include "coordenada.h"
#include "personaje.h"

class Juego;

class Observador_personaje:
public Observador_ubicable{
	protected:
		int cantidad_vidas;
		int porcentaje_vida;
		int energia;
	public:
		//Dado un Juego* y un Personaje*, crea un observador_personaje.
		Observador_personaje(Juego* juego, Personaje* pj);
		//Dado un observable*, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
