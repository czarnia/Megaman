#ifndef FIREMAN_H
#define FIREMAN_H

#include "personaje.h"
#include <vector>

class Arma_fireman;

class Fireman: public Personaje{
	private:
		Mapa *mapa;
		size_t tiempo_pasado;
		Arma_fireman* arma;
    bool atacando;
	public:
		Fireman(Mapa *mapa, Coordenada c, Arma_fireman* arma, int id);
		virtual void atacar(int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
		virtual void sacar_movimiento(int direccion);
		virtual void agregar_movimiento(int direccion);
};

#endif //FIREMAN_H
