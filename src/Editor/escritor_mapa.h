#ifndef ESCRITOR_MAPA_H
#define ESCRITOR_MAPA_H

#include <iostream>
#include <fstream>

#include "../Servidor/Modelo/coordenada.h"
#include "../Servidor/Modelo/mapa.h"

class Escritor_mapa{
  private:
    ofstream mapa_arch;
    Mapa mapa_real;
  public:
    //Dado un path para un nuevo archivo donde se guardará un mapa y una longi-
    //tud en x y otra en y para el mismo, se crea un escritor_mapa.
    Escritor_mapa(std::string path, size_t long_x, size_t long_y);
    //Destructor del escritor_mapa.
    ~Escritor_mapa();
    //Dada una coordenada, agrega a un met en la misma.
    void agregar_met(Coordenada coord_central);
    //Dada una coordenada, agrega un bloque en la misma.
    void agregar_bloque(Coordenada coord_central);
    //Dada una coordenada, agrega a unas puas en la misma.
    void agregar_puas(Coordenada coord_central);
    //Dada una coordenada, agrega a unas escaleras en la misma.
    void agregar_escaleras(Coordenada inicio, Coordenada fin);
    //Dada una coordenada, agrega un punto de inicio para los megamans en la
    //misma.
    void agregar_inicio_megamans(Coordenada coord_central);
};

#endif //ESCRITOR_MAPA_H
