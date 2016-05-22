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
    //Crea una celda_aire dado un Elemento*, en caso de no proporcionarse uno,
    //se la crea sin este.
    Celda_aire(Elemento* obstaculo);
    //Agrega (ubica) a un personaje en la celda.
    bool agregar_personaje(Personaje* ocupa);
    //Quira al personaje recibido de la celda.
    bool quitar_personaje(Personaje* ocupa);
    //Devuelve true si se puede ubicar un personaje en la celda.
    virtual bool puedo_ubicar();
    //Destructor de la celda_aire.
    virtual ~Celda_aire();
};

#endif //CELDA_AIRE_H
