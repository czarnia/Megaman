#ifndef ESCALERA_H
#define ESCALERA_H

#include "elemento.h"
#include "strategy_mover_sin_gravedad.h"
class Personaje;

//TODO: LAS ESCALERAS DEBERÍAN TENER UNA COORDENADA DE INICIO Y UNA DE FIN.

class Escalera: public Elemento{
	private:
		std::vector<StrategyMoverSinGravedad> estrategias;
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
		//Dado un Premio, devuelve true si el premio puede ubicarse
		//en las mismas coordenadas que este elemento.
		virtual bool puede_ocupar(Premio* premio);
		//Dado un ubicable, dice si puede ubicarse en las mimas
		//coordendas que este elemento.
		virtual bool puede_ocupar(Ubicable* ubic);
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
