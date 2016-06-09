#ifndef ESCALERA_H
#define ESCALERA_H

#include "elemento.h"
class Personaje;

//TODO: LAS ESCALERAS DEBERÍAN TENER UNA COORDENADA DE INICIO Y UNA DE FIN.

class Escalera: public Elemento{
	public:
		Escalera(Coordenada c);
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
		//Recibe un personaje e interactúa con el mismo
		//para actualizar sus coordenadas:
		void interactuar(Personaje *pj);
		//Destructor de la Escalera.
		~Escalera();
};

#endif //ESCALERA_H
