#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "personaje.h"

class Megaman: public Personaje{
	private:
		Mapa *mapa;

	public:
		Megaman(Mapa *mapa, Coordenada c, std::string id);
		virtual void atacar(size_t tiempo, Mapa* mapa);
		virtual void mover(size_t tiempo, Mapa* mapa);
		virtual void recibir_ataque(Bala* ataque);
		virtual void update(size_t tiempo);
};

#endif //MEGAMAN_H
