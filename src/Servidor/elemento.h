#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "personaje.h"

class Mapa;

class Elemento{
	public:
		virtual void interactuar(Mapa &mapa, Personaje *pj) = 0;
		virtual bool puede_ocupar(Personaje *pj) = 0;
};

#endif //ELEMENTO_H
