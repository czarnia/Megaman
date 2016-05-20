#ifndef CELDA_TIERRA_H
#define CELDA_TIERRA_H

#include "celda.h"

class Celda_tierra : public Celda{
  public:
    virtual bool puedo_ubicar();
    virtual ~Celda_tierra();
};

#endif //CELDA_TIERRA_H
