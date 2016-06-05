#ifndef CARGADOR_MAPA_H
#define CARGADOR_MAPA_H

#include <iostream>
#include <fstream>

#include "../Servidor/Modelo/coordenada.h"
#include "../Servidor/Modelo/mapa.h"

class Cargador_mapa{
  private:
    std::ifstream mapa_arch;
    Mapa* mapa_real;
  public:
    //Dado un path para un nuevo archivo donde se guardará un mapa y una longi-
    //tud en x y otra en y para el mismo, se crea un Cargador_mapa.
    Cargador_mapa(char* path);
    //Carga un mapa y lo devuelve.
    Mapa* cargar();
    //Destructor del Cargador_mapa.
    ~Cargador_mapa();
  private:
    //Dada una coordenada, agrega a un met en la misma.
    void agregar_met(Coordenada coord_central);
    //Dada una coordenada, agrega un bloque en la misma.
    void agregar_bloque(Coordenada coord_central);
    //Dada una coordenada, agrega a unas puas en la misma.
    void agregar_puas(Coordenada coord_central);
    //Dada una coordenada, agrega a unas escaleras en la misma.
    void agregar_escalera(Coordenada coord_central);
    //Dada una coordenada, agrega un punto de inicio para los megamans en la
    //misma.
    void agregar_inicio_megamans(Coordenada coord_central);
};

#endif //CARGADOR_MAPA_H
