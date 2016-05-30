#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

#include "servidor.h"
#include "observador.h"
#include "personaje.h"
#include "mapa.h"

class ObservadorPersonaje: public Observador{
	private:
		Mapa* mapa;
		Servidor *servidor;
		Coordenada coordenada;
		int cantidad_vidas;
		int porcentaje_vida;
		int energia;
	public:
		ObservadorPersonaje(Mapa* mapa, Servidor* servidor);
		virtual void update(Observable *obs);
};

#endif //OBSERVADOR_PERSONAJE_H
