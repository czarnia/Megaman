#ifndef EVENTO_MOVER_H
#define EVENTO_MOVER_H

#include "evento.h"
#include <string>

class Evento_mover : class Evento{
  private:
    std::string id;
    int direccion;
  public:
    //Crea un evento mover dado un id y una direccion.
    Evento_mover(int id, int dir);
    //Destructor del evento mover.
    ~Evento_mover();
    //Ejecuta un evento mover dado un juego.
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_MOVER_H
