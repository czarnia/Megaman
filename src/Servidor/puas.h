#ifndef PUAS_H
#define PUAS_H

#include "personaje.h"
#include "obstaculo.h"
#include "coordenada.h"

class Puas: public Obstaculo{
	private:
		Coordenada coord;
	public:
		Puas(Coordenada &coordenada);
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Destructor de las Puas.
		~Puas();
}

#endif //PUAS_H