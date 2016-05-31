#ifndef OBSERVADOR_JUEGO_H
#define OBSERVADOR_JUEGO_H

#include "observador.h"

class Observador_juego: public Observador{
	public:
		virtual void update_gameover(std::string id) = 0;
		virtual void update_fin_partida() = 0;
		virtual void update_murio_personaje(std::string id) = 0;
		virtual void update_cantidad_vidas(std::string id, int vidas) = 0;
		virtual void update_porcentaje_vida(std::string id, int porcentaje_vida) = 0;
		virtual void update_energia(std::string id, int energia) = 0;
		virtual void update_posicion(std::string id, int x, int y) = 0;
};

#endif //OBSERVADOR_JUEGO_H
