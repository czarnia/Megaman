#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "personaje.h"

class Megaman: public Personaje{
  public:
    Megaman(Mapa *mapa, Coordenada *c, std::string id);
    void atacar();
    void update(size_t tiempo);
    void recibir_ataque(/*Bala ataque*/);
};

#endif //MEGAMAN_H
