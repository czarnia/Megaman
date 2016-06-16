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
		//Dado un Mapa*, una coordenada, un Arma_minion* y un id, crea un met.
		Met(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
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
	private:
		//Devuelve true si es vulnerable a un cierto ataque, false en caso contrario.
		bool es_vulnerable(Bala* ataque);
};

#endif //MET_H
