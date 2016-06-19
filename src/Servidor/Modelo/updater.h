#ifndef UPDATER_H
#define UPDATER_H

#include "../../Comun/hilo.h"
#include "actualizable.h"

class Updater: public Hilo{
  private:
    Actualizable* up;
    Mapa* m;
    float t;
  public:
    //Dado un Actualizable*, un Mapa* y un tiempo, crea un Updater.
    Updater(Actualizable* act, Mapa* mundo, float tiempo);
    //Ejecuta el Updater, es decir, llama a update de su Actualizable.
    virtual void ejecutar();
    //Destructor del Updater.
    virtual ~Updater();
};

#endif //UPDATER_H
