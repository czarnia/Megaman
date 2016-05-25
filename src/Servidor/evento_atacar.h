#ifndef EVENTO_ATACAR_H
#define EVENTO_ATACAR_H

#include "evento.h"

class Evento_atacar : class Evento{
  private:
    std::string id;
    int direccion;
  public:
    //Crea un evento atacar dado un id y una direccion.
    Evento_atacar(int id, int dir);
    //Destructor del evento atacar.
    ~Evento_atacar();
    //Ejecuta un evento atacar dado un juego.
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_ATACAR_H
