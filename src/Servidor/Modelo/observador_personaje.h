#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "observador.h"
#include "juego.h"
#include "coordenada.h"
#include "personaje.h"

class Juego;

class Observador_personaje:
public Observador{
	protected:
		Juego* juego;
		int cantidad_vidas;
		int porcentaje_vida;
		int energia;
		Coordenada posicion_inicial;
	public:
		//Dado un Juego* y un Personaje*, crea un observador_personaje.
		Observador_personaje(Juego* juego, Personaje* pj);
		//Dado un observable*, hace un update.
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
