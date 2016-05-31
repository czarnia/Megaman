#ifndef JUEGO_OBSERVABLE_H
#define JUEGO_OBSERVABLE_H

#include "observador_juego.h"

class Juego_observable{
	protected:
		std::vector<Observador_juego*> observadores;
	public:
		virtual void agregar_observador(Observador_juego *observador) = 0;
		virtual void quitar_observador(Observador_juego *observador) = 0;
		virtual void notificar_gameover(std::string id) = 0;
		virtual void notificar_termino_partida() = 0;
		virtual void notificar_murio_personaje(std::string id) = 0;
		virtual void notificar_cantidad_vidas(std::string id, int vidas) = 0;
		virtual void notificar_porcentaje_vida(std::string id, int cant_vida) = 0;
		virtual void notificar_energia(std::string id, int energia) = 0;
		virtual void notificar_posicion(std::string id, int x, int y) = 0;
};

#endif //JUEGO_OBSERVABLE_H
