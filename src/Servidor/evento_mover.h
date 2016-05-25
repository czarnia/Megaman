#ifndef EVENTO_MOVER_H
#define EVENTO_MOVER_H

#include "evento.h"
#include "juego.h"
#include <string>
#include <map>

class Evento_mover: public Evento{
  private:
    std::string id;
    int direccion;
  protected:
    static std::map<int, std::string> mis_direcciones;
  public:
    //Crea un evento mover dado un id y una direccion.
    Evento_mover(int id, int dir);
    std::string get_direccion();
    //Destructor del evento mover.
    ~Evento_mover();
    //Ejecuta un evento mover dado un juego.
    virtual void ejecutar(Juego j);
};

#endif //EVENTO_MOVER_H
