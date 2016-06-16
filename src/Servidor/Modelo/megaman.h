#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "mapa.h"
#include "personaje.h"
#include "strategy_mover_megaman.h"
#include "../../Comun/lock.h"
#include "../../Comun/mutex.h"
class Arma;
class Arma_megaman;

class Megaman: public Personaje{
	private:
		Mutex m;
		Mapa *mapa;
		std::vector<Arma*> armas;
		StrategyMoverMegaman *movimiento_megaman;
		StrategyMover *movimiento_actual;
		size_t arma_act;
	public:
		//Dado un Mapa*, una coordenada, un Arma_megaman* y un id, crea un megaman.
		Megaman(Mapa *mapa, Coordenada c, Arma_megaman *arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(size_t tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(size_t tiempo);
		//Dada un Arma*, se la agrega a la armeria del megaman.
		virtual void agregar_arma(Arma *arma);
		//Dado una direccion, se agrega un movimiento en dicha direccion.
		virtual void agregar_movimiento(int direccion);
		//Dado una direccion, se saca un movimiento en dicha direccion.
		virtual void sacar_movimiento(int direccion);

		friend class StrategyMoverMegaman;
};

#endif //MEGAMAN_H
