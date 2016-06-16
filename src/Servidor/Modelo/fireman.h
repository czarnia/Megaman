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
		//Dado un Mapa*, una coordenada, un Arma_bombman* y un id, crea un fireman.
		Fireman(Mapa *mapa, Coordenada c, Arma_fireman* arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(size_t tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(size_t tiempo);

		virtual void sacar_movimiento(int direccion);
		virtual void agregar_movimiento(int direccion);
};

#endif //FIREMAN_H
