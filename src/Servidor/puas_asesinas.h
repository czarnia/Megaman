#ifndef PUAS_ASESINAS_H
#define PUAS_ASESINAS_H

#include "elemento.h"

class Personaje;

class Puas_asesinas: public Elemento{
	public:
		Puas_asesinas(Coordenada c) : Elemento(c) {}
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Ubicable* ubic);
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
