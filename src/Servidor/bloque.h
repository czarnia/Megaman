#ifndef BLOQUE_H
#define BLOQUE_H

#include "elemento.h"

class Personaje;

class Bloque: public Elemento{
	public:
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Personaje* pj);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Destructor del bloque.
		~Bloque();
};

#endif //BLOQUE_H
