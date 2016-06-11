#ifndef MET_H
#define MET_H

#include "personaje.h"

class Arma_minion;

class Met: public Personaje{
	private:
		Mapa *mapa;
		bool tras_escudo;
		size_t tiempo_pasado;
		Arma_minion* arma;
	public:
		Met(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		virtual void atacar(int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
		virtual void sacar_movimiento(int direccion);
		virtual void agregar_movimiento(int direccion);
};

#endif //MET_H
