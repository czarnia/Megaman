#ifndef OBSERVADOR_JUEGO_H
#define OBSERVADOR_JUEGO_H

#include "../Modelo/observador.h"
#include "../Modelo/juego_observable.h"

class Juego_observable;

class Observador_juego: public Observador{
	public:
		virtual void update(Observable *obs) = 0;	
		virtual void update_gameover(int id) = 0;
		virtual void update_fin_partida() = 0;
		virtual void update_murio_personaje(int tipo, int id) = 0;
		virtual void update_cantidad_vidas(int tipo, int id, int vidas) = 0;
		virtual void update_porcentaje_vida(int tipo, int id, int porcentaje_vida) = 0;
		virtual void update_energia(int tipo, int id, int energia) = 0;
		virtual void update_posicion(int tipo, int id, int x, int y) = 0;
};

#endif //OBSERVADOR_JUEGO_H
