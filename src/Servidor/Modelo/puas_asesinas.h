#ifndef PUAS_ASESINAS_H
#define PUAS_ASESINAS_H

#include "elemento.h"

class Personaje;

class Puas_asesinas: public Elemento{
	public:
		Puas_asesinas(Coordenada c);
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Ubicable* ubic);
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
		//Dadas unas puas_asesinas, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Puas_asesinas* puas);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Devuelve todas las coordenadas que ocupa una puas_asesinas.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía una puas_asesinas si su centro es-
		//tuviera en c.
		virtual std::vector<Coordenada> coordenadas(Coordenada c);
		//Destructor de las Puas_asesinas.
		~Puas_asesinas();
};

#endif //PUAS_ASESINAS_H
