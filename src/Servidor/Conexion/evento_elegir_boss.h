#ifndef EVENTO_ELEGIR_BOSS_H
#define EVENTO_ELEGIR_BOSS_H

#include <iosfwd>
#include <cstddef>

#include "evento_lobby.h"

class Evento_elegir_boss : public Evento_lobby{
  private:
    int boss;
	public:
    //Dado un numero de boss, crea un evento_elegir_boss.
    Evento_elegir_boss(int b) : boss(b) {}
		//Destructor del evento.
		virtual ~Evento_elegir_boss() {};
		//Ejecuta un evento.
		virtual void ejecutar(Servidor* s);
};

#endif //EVENTO_ELEGIR_BOSS_H
