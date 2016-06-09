#ifndef EVENTO_LOBBY_H
#define EVENTO_LOBBY_H

#include <iosfwd>
#include <cstddef>

class Servidor;

class Evento_lobby{
	public:
		//Destructor del evento.
		virtual ~Evento_lobby() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s) = 0;
};

#endif //EVENTO_LOBBY_H
