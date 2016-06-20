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
		//Notifica a los observadores que finalizo la partida.
		virtual void notificar_termino_partida() = 0;
		//Notifica a los observadores que se produjo un gameover.
		virtual void notificar_gameover(int id) = 0;
		//Notifica a los observadores que se modifico la cantidad de vidas de un
		//personaje.
		virtual void notificar_cantidad_vidas(int tipo, int id, int vidas) = 0;
		//Notifica a los observadores que se modifico el porcentaje de vida de un
		//personaje.
		virtual void notificar_porcentaje_vida(int tipo, int id, int cant_vida) = 0;
		//Notifica a los observadores que se modifico el porcentaje de energia de un
		//personaje.
		virtual void notificar_energia(int tipo, int id, int energia) = 0;
		//Notifica a los observadores que se modifico la posicion de un personaje.
		virtual void notificar_posicion(int tipo, int id, int x, int y) = 0;
		//Recibe id y tipo y un estado correspondientes a un personaje y
		//y notifica al servidor del cambio de estado.
		virtual void actualizo_estado_personaje(int tipo, int id, int estado) = 0;
		//Notifica a los observadores de que se gano el nivel actual.
		virtual void notificar_termino_nivel() = 0;
};

#endif //JUEGO_OBSERVABLE_H
