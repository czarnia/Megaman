#ifndef BLOQUE_H
#define BLOQUE_H

#include "elemento.h"

class Personaje;

class Bloque: public Elemento{
	public:
		Bloque(Coordenada c) : Elemento(c) {};
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Personaje* pj);
		//Dado un elemento, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Elemento* pj);
		//Dada una bala, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Bala* bala);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Escalera* esc);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Puas* puas);
		//Dadas unas puas_asesinas, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Puas_asesinas* puas);
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
