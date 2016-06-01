#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "observador.h"
#include "personaje.h"
#include "juego.h"

class ObservadorPersonaje: public Observador{
	private:
		Juego* juego;
		Coordenada coordenada;
		int cantidad_vidas;
		int porcentaje_vida;
		int energia;
	public:
		ObservadorPersonaje(Juego* juego);
		virtual void update(Observable *obs);
		
		//para testear:
		Coordenada get_coordenada();
};

#endif //OBSERVADOR_PERSONAJE_H
