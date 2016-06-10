#ifndef EVENTO_ATACAR_H
#define EVENTO_ATACAR_H

#include "evento.h"
#include <string>

class Evento_atacar : public Evento{
  private:
    int id_evento;
    int direccion;
  public:
    //Crea un evento atacar dado un id y una direccion.
    Evento_atacar(int id, int dir);
    //Destructor del evento atacar.
    virtual ~Evento_atacar();
    //Ejecuta un evento atacar dado un juego.
    virtual void ejecutar(Juego* j, Log* l);
};

#endif //EVENTO_ATACAR_H
