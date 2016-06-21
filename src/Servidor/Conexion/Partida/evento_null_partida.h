#ifndef EVENTO_NULL_PARTIDA_H
#define EVENTO_NULL_PARTIDA_H

#include "evento.h"

class Evento_null_partida : public Evento{
  public:
    //Crea un evento null_partida dado un id y una direccion.
    Evento_null_partida();
    //Ejecuta un evento null_partida dado un juego.
    virtual void ejecutar(Juego* j);
    //Destructor del evento null_partida.
    virtual ~Evento_null_partida();
};

#endif //EVENTO_NULL_PARTIDA_H
