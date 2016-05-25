#ifndef EVENTO_CAMBIAR_ARMA_H
#define EVENTO_CAMBIAR_ARMA_H

#include "evento.h"

class Evento_cambiar_arma : class Evento{
  private:
    std::string id;
    int num_arma;
  public:
    Evento_cambiar_arma(int id, int arma);
    ~Evento_cambiar_arma();
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_CAMBIAR_ARMA_H
