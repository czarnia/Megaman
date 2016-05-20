#ifndef ESCALERA_H
#define ESCALERA_H

#include "personaje.h"
#include "obstaculo.h"
#include "coordenada.h"

class Escalera: public Obstaculo{
	private:
		Coordenada coord;
	public:
		Escalera(Coordenada &coordenada);
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Destructor de la Escalera.
		~Escalera();
}

#endif //ESCALERA_H
