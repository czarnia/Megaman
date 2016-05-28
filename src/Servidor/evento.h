#ifndef EVENTO_H
#define EVENTO_H

#include <iosfwd>
#include <cstddef>

class Juego;

class Evento{
	public:
		//Destructor del evento.
		virtual ~Evento() {};
		//Ejecuta un evento.
		virtual void ejecutar(Juego *j) = 0;
};

#endif //EVENTO_H
