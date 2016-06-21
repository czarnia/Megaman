#ifndef EVENTO_NULL_LOBBY_H
#define EVENTO_NULL_LOBBY_H

#include "evento_lobby.h"

class Evento_null_lobby : public Evento_lobby{
	public:
    //Dado un numero de boss, crea un evento_null_lobby.
    Evento_null_lobby(){}
		//Destructor del evento.
		virtual ~Evento_null_lobby() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s);
};

#endif //EVENTO_NULL_LOBBY_H
