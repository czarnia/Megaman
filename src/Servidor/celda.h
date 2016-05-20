#ifndef CELDA_H
#define CELDA_H

class Celda{
  public:
    virtual bool puedo_ubicar() = 0;
    virtual ~Celda();
};

#endif //CELDA_H
