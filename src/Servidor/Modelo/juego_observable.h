#ifndef JUEGO_OBSERVABLE_H
#define JUEGO_OBSERVABLE_H

#include "../Conexion/Partida/observador_juego.h"

class Observador_juego;

class Juego_observable:
public Observable{
	public:
		//Notifica a sus observadores de eventuales cambios.
		virtual void notificar_observadores() = 0;
		//Quita un observador del juego.
		virtual void quitar_observador(Observador_juego *observador) = 0;
		//Agrega un observador al juego.
		virtual void agregar_observador(Observador_juego *observador) = 0;
};

#endif //JUEGO_OBSERVABLE_H
