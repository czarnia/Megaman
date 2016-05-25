#ifndef CREADOR_CAMBIAR_ARMA_H
#define CREADOR_CAMBIAR_ARMA_H

#include "creador_evento.h"
#include "evento.h"

class Creador_cambiar_arma : public Creador_evento{
  private:
    int id;
  public:
    //Dado un id, crea un creador cambiar_arma.
    Creador_cambiar_arma(int id_creador);
    //Destructor del creador cambiar_arma.
    virtual ~Creador_cambiar_arma();
    //Crea un evento de tipo cambiar_arma dado un parametro.
    virtual Evento* crear(int parametro);
};

#endif //CREADOR_CAMBIAR_ARMA_H
