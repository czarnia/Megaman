#ifndef BLOQUE_H
#define BLOQUE_H

#include "elemento.h"

class Personaje;

class Bloque: public Elemento{
	public:
		Bloque(Coordenada c) : Elemento(c) {};
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Ubicable* ubic);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Devuelve todas las coordenadas que ocupa un bloque.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía un bloque si su centro es-
		//tuviera en c.
		virtual std::vector<Coordenada> coordenadas(Coordenada c);
		//Destructor del bloque.
		~Bloque();
};

#endif //BLOQUE_H
