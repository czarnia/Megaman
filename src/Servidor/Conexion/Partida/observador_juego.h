#ifndef OBSERVADOR_JUEGO_H
#define OBSERVADOR_JUEGO_H

#include "../../Modelo/observador.h"
#include "../../Modelo/juego_observable.h"

class Juego_observable;

class Observador_juego: public Observador{
	public:
		//Dado un observable, realiza un update.
		virtual void update(Observable *obs) = 0;
		//Dado un identificador, notifica un gameover del cliente correspondiente.
		virtual void update_gameover(int id) = 0;
		//Notifica el fin de una partida.
		virtual void update_fin_partida() = 0;
		//Dado un identificador y un tipo, notifica que un personaje murio.
		virtual void update_murio_personaje(int tipo, int id) = 0;
		//Dado un identificador, un tipo y una cantidad de vidas, notifica que un
		//personaje vio modificadas las mismas.
		virtual void update_cantidad_vidas(int tipo, int id, int vidas) = 0;
		//Dado un identificador, un tipo y una porcentaje de vida, notifica que un
		//personaje vio modificada la misma.
		virtual void update_porcentaje_vida(int tipo, int id, int porcentaje_vida) = 0;
		//Dado un identificador, un tipo y una porcentaje de energia, notifica que
		//un personaje vio modificada la misma.
		virtual void update_energia(int tipo, int id, int energia) = 0;
		//Dado un identificador, un tipo y nuevas coordenadas en x y en y, notifica
		//que un personaje vio modificadas la mismas.
		virtual void update_posicion(int tipo, int id, int x, int y) = 0;
};

#endif //OBSERVADOR_JUEGO_H
