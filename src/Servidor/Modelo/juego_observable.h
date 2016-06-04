#ifndef JUEGO_OBSERVABLE_H
#define JUEGO_OBSERVABLE_H

#include "../Conexion/observador_juego.h"

class Observador_juego;

class Juego_observable:
public Observable{
	public:
		virtual void agregar_observador(Observador_juego *observador) = 0;
		virtual void quitar_observador(Observador_juego *observador) = 0;
		virtual void notificar_gameover(int id) = 0;
		virtual void notificar_termino_partida() = 0;
		virtual void notificar_murio_personaje(int tipo, int id) = 0;
		virtual void notificar_cantidad_vidas(int tipo, int id, int vidas) = 0;
		virtual void notificar_porcentaje_vida(int tipo, int id, int cant_vida) = 0;
		virtual void notificar_energia(int tipo, int id, int energia) = 0;
		virtual void notificar_posicion(int tipo, int id, int x, int y) = 0;
		virtual void notificar_observadores() = 0;
};

#endif //JUEGO_OBSERVABLE_H
