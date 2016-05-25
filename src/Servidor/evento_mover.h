#ifndef EVENTO_MOVER_H
#define EVENTO_MOVER_H

#include "evento.h"
#include <string>

class Evento_mover : class Evento{
  private:
    std::string id;
    int direccion;
  public:
    Evento_mover(int id, int dir);
    ~Evento_mover();
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_MOVER_H
