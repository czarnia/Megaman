#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "personaje.h"

class Megaman: public Personaje{
  public:
    Megaman(Mapa *mapa, Coordenada c, std::string id);
    virtual void atacar(int direccion, Mapa* mapa);
    virtual void mover(size_t tiempo, Mapa* mapa);
    virtual void recibir_ataque(/*Bala ataque*/);
};

#endif //MEGAMAN_H
