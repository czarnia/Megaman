#ifndef PUAS_H
#define PUAS_H

#include "elemento.h"

class Personaje;

class Puas: public Elemento{
	public:
		//Dada una coordenada, crea unas puas.
		Puas(Coordenada c);
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
		//Dado un ubicable, dice si puede ubicarse en las mimas
		//coordendas que este elemento.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Dado un Premio, devuelve true si el premio puede ubicarse
		//en las mismas coordenadas que este elemento.
		virtual bool puede_ocupar(Premio* premio);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		virtual bool puede_ocupar(Puas* puas);
		//Recibe un personaje e interactúa con el mismo para
		//ocasionarle daño.
		void interactuar(Personaje *pj);
		//Notifica a las entidades que observen a este
		//elemento de un cambio en el estado del mismo;
		virtual void notificar_observadores();
		//Agrega un observador de ubicables a la lista de
		//observadores de este elemento
		virtual void agregar_observador(Observador_ubicable *observador);
		//Recibe un puntero a observador de ubicables y lo
		//remueve de la lista de observadores de este elemento
		virtual void quitar_observador(Observador_ubicable *observador);
		//Devuele true si el elemento actua como piso, false en caso contrario
		virtual bool es_piso();
		//Destructor de las Puas.
		~Puas();
};

#endif //PUAS_H
