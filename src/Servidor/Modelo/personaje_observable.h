#ifndef PERSONAJE_OBSERVABLE_H
#define PERSONAJE_OBSERVABLE_H

#include "ubicable.h"
class Observador_personaje;

class Personaje_observable:
public Ubicable{
	public:
		//Dado un observador_personaje* lo agrega a sus observadores.
		virtual void agregar_observador(Observador_personaje *observador) = 0;
		//Dado un observador_personaje* lo quita de sus observadores.
		virtual void quitar_observador(Observador_personaje *observador) = 0;
};

#endif //PERSONAJE_OBSERVABLE_H
