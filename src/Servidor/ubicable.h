#ifndef UBICABLE_H
#define UBICABLE_H

#include "coordenada.h"
Class Mapa;

class Ubicable{
	public:
		//Intenta ubicar a un elemento ubicable en las coordenadas del mapa
		//que sean ocupadas por ese objeto, devuelve true sólo si la ubicación
		//del objeto o personaje fue realizada con éxito.
		virtual bool ubicar(Mapa &mapa) = 0;
		//Devuelve true sólo si el ubicable recibido tiene permitido
		//ubicarse en la misma celda. Si recibe NULL devuelve true
		//sólo si es ubicable con cualquier otro tipo de ubicable.
		virtual bool es_ubicable_con(Ubicable *ubicable) = 0;
		//Devuelve false si no puede compartir celda con ningun
		//ubicable.
		virtual bool puede_compartir_celda() = 0;
		//Destructor del ubicable.
		virtual ~Ubicable();
};

#endif //UBICABLE_H
