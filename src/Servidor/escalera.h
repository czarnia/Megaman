#ifndef ESCALERA_H
#define ESCALERA_H

#include "elemento.h"
class Personaje;

class Escalera: public Elemento{
	public:
		Escalera(Coordenada c) : Elemento(c) {}
		//Devuelve true sólo si el personaje recibido tiene permitido
		//ubicarse en la misma celda.
		bool puede_ocupar(Ubicable* ubic);
		//Recibe un personaje e interactúa con el mismo
		//para actualizar sus coordenadas:
		void interactuar(Personaje *pj);
		//Devuelve todas las coordenadas que ocupa una escalera.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía una escalera si su centro es-
		//tuviera en c.
		virtual std::vector<Coordenada> coordenadas(Coordenada c);
		//Destructor de la Escalera.
		~Escalera();
};

#endif //ESCALERA_H
