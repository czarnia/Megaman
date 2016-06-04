#ifndef PERSONAJE_OBSERVABLE_H
#define PERSONAJE_OBSERVABLE_H

#include "ubicable.h"
class Observador_personaje;

class Personaje_observable:
public Ubicable{
	public:
		virtual void agregar_observador(Observador_personaje *observador) = 0;
		virtual void quitar_observador(Observador_personaje *observador) = 0;
};

#endif //PERSONAJE_OBSERVABLE_H
