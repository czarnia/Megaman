#ifndef EVENTO_CAMBIAR_ARMA_H
#define EVENTO_CAMBIAR_ARMA_H

#include "evento.h"
#include <string>

class Evento_cambiar_arma : public Evento{
  private:
    int id_evento;
    int num_arma;
  public:
    //Crea un evento cambiar_arma dado un id y un numero de arma.
    Evento_cambiar_arma(int id, int arma);
    //Destructor del evento cambiar_arma.
    virtual ~Evento_cambiar_arma();
    //Ejecuta un evento cambiar_arma dado un juego.
    virtual void ejecutar(Juego* j, Log* l);
};

#endif //EVENTO_CAMBIAR_ARMA_H
