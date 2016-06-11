#ifndef EVENTO_START_H
#define EVENTO_START_H

#include <iosfwd>
#include <cstddef>

#include "evento_lobby.h"

class Evento_start : public Evento_lobby{
	public:
		//Destructor del evento.
		virtual ~Evento_start() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s);
};

#endif //EVENTO_START_H
