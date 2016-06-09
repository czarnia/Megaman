#ifndef PREMIO_H
#define PREMIO_H

#include "elemento.h"

class Premio : public Elemento{
	public:
		Premio(Coordenada coord, int tipo);
		//Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Personaje* pj);
		//Dado un elemento, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Elemento* pj);
		//Dada una bala, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Bala* bala);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Escalera* esc);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Puas* puas);
		//Destructor de premio.
		virtual ~Premio() = 0;
};

#endif //PREMIO_H
