#ifndef CELDA_TIERRA_H
#define CELDA_TIERRA_H

#include "celda.h"

class Celda_tierra : public Celda{
  public:
    //Devuelve true si se puede ubicar un personaje en la celda.
    virtual bool puedo_ubicar();
    //Destructor de la celda_tierra.
    virtual ~Celda_tierra();
};

#endif //CELDA_TIERRA_H
