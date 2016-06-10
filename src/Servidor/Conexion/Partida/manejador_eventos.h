#ifndef MANEJADOR_EVENTOS_H
#define MANEJADOR_EVENTOS_H

class Juego;

#include "../Arquitectura/log.h"
#include "evento.h"

class Manejador_eventos{
  private:
    Juego *mundo;
    Log* l;
  public:
    //Dado un juego, crea un manejador de eventos.
    Manejador_eventos(Juego *m, Log* lg);
    //Destructor del manejador de eventos.
    ~Manejador_eventos();
    //Dado un evento, lo ejecuta.
    void ejecutar_evento(Evento* e);
};

#endif //MANEJADOR_EVENTOS_H
