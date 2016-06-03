#ifndef PUAS_H
#define PUAS_H

#include "elemento.h"

class Personaje;

class Puas: public Elemento{
	public:
		Puas(Coordenada c) : Elemento(c) {}
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Ubicable* ubic);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Devuelve todas las coordenadas que ocupa una puas.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía una puas si su centro es-
		//tuviera en c.
		virtual std::vector<Coordenada> coordenadas(Coordenada c);
		//Destructor de las Puas.
		~Puas();
};

#endif //PUAS_H
