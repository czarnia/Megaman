#ifndef MAPA_H
#define MAPA_H

#include "celda.h"
#include "ubicable.h"

class Mapa{
  private:
    std::map<size_t, std::map<size_t, Celda>> celdas;
  public:
    Mapa();
    void ocupar(size_t x, size_t y, Ubicable nuevo_ubicable);
    Ubicable desocupar(size_t x, size_t y);
    Ubicable obtener_ubicable(size_t x, size_t y);
  private:
    //TODO: void cargar();
};

#endif //MAPA_H
