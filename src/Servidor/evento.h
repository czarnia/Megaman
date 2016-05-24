#ifndef EVENTO_H
#define EVENTO_H

#include "mapa.h"
#include <iosfwd>
#include <cstddef>


class Evento{
	public:
    //Destructor del evento.
		virtual ~Evento();
		//Ejecuta un evento.
		virtual void ejecutar() = 0;
};

#endif //EVENTO_H
