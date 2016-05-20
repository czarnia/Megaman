#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "personaje.h"

class Obstaculo{
	public:
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		virtual bool puede_ocupar(Personaje* pj) = 0;
		//Destructor del Obstaculo.
		virtual ~Obstaculo();
}

#endif //OBSTACULO_H
