#ifndef CREADOR_ELEGIR_BOSS_H
#define CREADOR_ELEGIR_BOSS_H

#include "creador_evento_lobby.h"
#include "evento.h"

class Creador_elegir_boss : public Creador_evento_lobby{
  private:
    int id;
  public:
    //Dado un id, crea un creador elegir_boss.
    Creador_elegir_boss(int id_creador);
    //Destructor del creador elegir_boss.
    virtual ~Creador_elegir_boss();
    //Crea un evento de tipo elegir_boss dado un parametro.
    virtual Evento_lobby* crear(int parametro);
};

#endif //CREADOR_ELEGIR_BOSS_H
