#ifndef MANEJADOR_EVENTOS_H
#define MANEJADOR_EVENTOS_H

#include "juego.h"
#include "evento.h"

class Manejador_eventos{
  private:
    Juego mundo;
  public:
    //Dado un juego, crea un manejador de eventos.
    Manejador_eventos(Juego m);
    //Destructor del manejador de eventos.
    ~Manejador_eventos();
    //Dado un evento, lo ejecuta.
    void ejecutar_evento(Evento e);
};

#endif //MANEJADOR_EVENTOS_H
