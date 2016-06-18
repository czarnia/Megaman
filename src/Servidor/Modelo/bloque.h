#ifndef BLOQUE_H
#define BLOQUE_H

#include "elemento.h"

class Personaje;

class Bloque: public Elemento{
	public:
		//Dada una coordenada, crea un bloque.
		Bloque(Coordenada c);
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
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
		//Dado un Premio, devuelve true si el premio puede ubicarse
		//en las mismas coordenadas que este elemento.
		virtual bool puede_ocupar(Premio* premio);
		//Dado un bloque, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Puas* puas);
		//Dado un ubicable, dice si puede ubicarse en las mimas
		//coordendas que este elemento.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Devuele true si el elemento actua como piso, false en caso contrario
		virtual bool es_piso();
		//Destructor del bloque.
		~Bloque();
};

#endif //BLOQUE_H
