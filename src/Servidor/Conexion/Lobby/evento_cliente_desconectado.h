#ifndef EVENTO_CLIENTE_DESCONECTADO_H
#define EVENTO_CLIENTE_DESCONECTADO_H

#include <iosfwd>
#include <cstddef>

#include "evento_lobby.h"

class Evento_cliente_desconectado : public Evento_lobby{
	private:
		int id;
	public:
		//Dado un id_cliente, se crea un evento_cliente_desconectado.
		Evento_cliente_desconectado(int id_cliente) : id(id_cliente){}
		//Destructor del evento.
		virtual ~Evento_cliente_desconectado() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s);
};

#endif //EVENTO_CLIENTE_DESCONECTADO_H
