#ifndef CELDA_H
#define CELDA_H

<<<<<<< HEAD
class Celda{
  public:
    virtual bool puedo_ubicar() = 0;
    virtual ~Celda();
=======
#include "personaje.h"
#include "obstaculo.h"
#include "plataforma.h"
#include <map>

class Celda{
  private:
    std::map <std::string, Personaje*> ocupantes;
    Obstaculo* obs;
    Plataforma piso;
  public:
    //Crea una celda, dada una plataforma y un obstaculo, en caso de no pasar
    //alguno, se crea sin los mismos.
    Celda(Plataforma p, Obstaculo* o);
    //Ocupa a la celda con un personaje.
    bool ocupar(Personaje* ocupa);
    //Devuelve si un personaje puede ocupar la celda.
    bool puede_ocupar(Personaje* ocupa);
    //Dado el id de un personaje, lo saca de la celda.
    Personaje* desocupar(std::string id_personaje);
    //Dado el id de un personaje, lo obtiene.
    Personaje* obtener_ocupante(std::string id_personaje);
>>>>>>> 5f1e46989bbb039b57886a78204f9ec008c7c9af
};

#endif //CELDA_H
