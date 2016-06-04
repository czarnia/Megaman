#ifndef UBICABLE_H
#define UBICABLE_H

#include "observable.h"
#include "coordenada.h"

class Observador_ubicable;

class Ubicable:
public Observable{
	public:
		virtual void agregar_observador(Observador_ubicable *observador) = 0;
		virtual void quitar_observador(Observador_ubicable *observador) = 0;
		virtual Coordenada get_coordenada() = 0;
		virtual int get_tipo() = 0;
		virtual int get_id() = 0;
};

#endif //UBICABLE_H
