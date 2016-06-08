#ifndef JUEGO_OBSERVABLE_H
#define JUEGO_OBSERVABLE_H

#include "../Conexion/observador_juego.h"

class Observador_juego;

class Juego_observable:
public Observable{
	public:
		//Notifica a sus observadores de eventuales cambios.
		virtual void notificar_observadores() = 0;
		//Quita un observador del juego.
		void quitar_observador(Observador_juego *observador) = 0;
		//Agrega un observador al juego.
		void agregar_observador(Observador_juego *observador) = 0;
		//Notifica a los observadores que finalizo la partida.
		void notificar_termino_partida() = 0;
		//Notifica a los observadores que se produjo un gameover.
		void notificar_gameover(int id) = 0;
		//Notifica a los observadores que murio un determinado pj.
		void notificar_murio_personaje(int tipo, int id) = 0;
		//Notifica a los observadores que se modifico la cantidad de vidas de un
		//personaje.
		void notificar_cantidad_vidas(int tipo, int id, int vidas) = 0;
		//Notifica a los observadores que se modifico el porcentaje de vida de un
		//personaje.
		void notificar_porcentaje_vida(int tipo, int id, int cant_vida) = 0;
		//Notifica a los observadores que se modifico el porcentaje de energia de un
		//personaje.
		void notificar_energia(int tipo, int id, int energia) = 0;
		//Notifica a los observadores que se modifico la posicion de un personaje.
		void notificar_posicion(int tipo, int id, int x, int y) = 0;
}

#endif //JUEGO_OBSERVABLE_H
