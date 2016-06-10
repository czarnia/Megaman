#ifndef EVENTO_H
#define EVENTO_H

#include "../Arquitectura/log.h"

#include <iosfwd>
#include <cstddef>

class Juego;

class Evento{
	public:
		//Destructor del evento.
		virtual ~Evento() {};
		//Ejecuta un evento.
		virtual void ejecutar(Juego* j, Log* l) = 0;
};

#endif //EVENTO_H
