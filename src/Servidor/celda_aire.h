#ifndef CELDA_AIRE_H
#define CELDA_AIRE_H

#include "celda.h"
#include "elemento.h"
#include "personaje.h"

#include <string>
#include <map>

class Celda_aire : public Celda{
  private:
    Elemento* elem;
    std::map<std::string, Personaje*> ocupantes;
  public:
    Celda_aire(Elemento* obstaculo);
    bool agregar_personaje(Personaje* ocupa);
    virtual bool puedo_ubicar();
    virtual ~Celda_aire();
};

#endif //CELDA_AIRE_H
