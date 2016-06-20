#ifndef OBSERVADOR_JUEGO_H
#define OBSERVADOR_JUEGO_H

#include "../../Modelo/observador.h"
#include "../../Modelo/juego_observable.h"
#include "../../../Comun/socket.h"

#include "estado.h"

class Juego_observable;

class Observador_juego: public Observador{
	public:
		//Dado un observable, realiza un update.
		virtual void update(Observable *obs) = 0;
		//Dado un estado, hace un update.
		virtual void update_estado(Estado e) = 0;
};

#endif //OBSERVADOR_JUEGO_H
