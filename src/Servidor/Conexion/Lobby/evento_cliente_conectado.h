#ifndef EVENTO_CLIENTE_CONECTADO_H
#define EVENTO_CLIENTE_CONECTADO_H

#include <iosfwd>
#include <cstddef>

#include "evento_lobby.h"

class Evento_cliente_conectado : public Evento_lobby{
	public:
		//Destructor del evento.
		virtual ~Evento_cliente_conectado() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s, Log* l);
};

#endif //EVENTO_CLIENTE_CONECTADO_H
