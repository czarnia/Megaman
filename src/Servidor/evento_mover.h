#ifndef EVENTO_MOVER_H
#define EVENTO_MOVER_H

#include "evento.h"
#include "juego.h"
#include <string>
#include <map>

class Evento_mover : public Evento{
  private:
    std::string id_evento;
    int direccion;
  public:
    //Crea un evento mover dado un id y una direccion.
    Evento_mover(int id, int dir);
    //Devuelve la direccion del evento mover.
    int get_direccion();
    //Ejecuta un evento mover dado un juego.
    virtual void ejecutar(Juego *j);
    //Destructor del evento mover.
    virtual ~Evento_mover();
};

#endif //EVENTO_MOVER_H
