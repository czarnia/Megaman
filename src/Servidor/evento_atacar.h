#ifndef EVENTO_ATACAR_H
#define EVENTO_ATACAR_H

#include "evento.h"

class Evento_atacar : class Evento{
  private:
    std::string id;
    int direccion;
  public:
    Evento_atacar(int id, int dir);
    ~Evento_atacar();
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_ATACAR_H
