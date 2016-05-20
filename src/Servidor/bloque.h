#ifndef BLOQUE_H
#define BLOQUE_H

#include "personaje.h"
#include "obstaculo.h"
#include "coordenada.h"

class Bloque: public Obstaculo{
	private:
		Coordenada coord;
	public:
		Bloque(Coordenada &coordenada);
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Destructor del bloque.
		~Bloque();
}

#endif //BLOQUE_H
