#ifndef CREADOR_CAMBIAR_ARMA_H
#define CREADOR_CAMBIAR_ARMA_H

#include "creador_evento.h"
#include "evento.h"

class Creador_cambiar_arma : class Creador_evento{
  private:
    int id;
  public:
    //Crea un evento de tipo cambiar_arma dado un id y un parametro.
    virtual Evento* crear(int id, int parametro);
};

#endif //CREADOR_CAMBIAR_ARMA_H
