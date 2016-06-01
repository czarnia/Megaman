#ifndef MET_H
#define MET_H

#include "personaje.h"
#include "arma.h"

class Met: public Personaje{
	private:
		Mapa *mapa;
    bool tras_escudo;
    size_t tiempo_pasado;
		Arma* arma;
	public:
		Met(Mapa *mapa, Coordenada c, std::string id);
		virtual void atacar(size_t tiempo, int dir, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
};

#endif //MET_H
