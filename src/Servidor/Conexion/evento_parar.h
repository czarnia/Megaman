#ifndef EVENTO_PARAR_H
#define EVENTO_PARAR_H

#include "evento.h"
#include <string>

class Evento_parar : public Evento{
  private:
    std::string id_evento;
    int direccion;
  public:
    //Crea un evento parar dado un id y una direccion.
    Evento_parar(int id, int dir);
    //Devuelve la direccion del evento parar.
    int get_direccion();
    //Ejecuta un evento parar dado un juego.
    virtual void ejecutar(Juego* j);
    //Destructor del evento parar.
    virtual ~Evento_parar();
};

#endif //EVENTO_PARAR_H
