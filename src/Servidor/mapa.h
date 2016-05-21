#ifndef MAPA_H
#define MAPA_H

#include <map>
#include "celda.h"
#include "ubicable.h"


class Mapa{
  private:
    std::map<size_t, std::map<size_t, Celda>> celdas;
  public:
    Mapa();
    //Recibe un ubicable y las coordenadas donde se desea posicionar
    //al nuevo_ubicable. Devuelve true si la ubicación fue realizada
    //con éxito.
    bool ocupar(Ubicable &nuevo_ubicable, std::vector<Coordenada*> &coordenadas);
    //Devuelve true si la coordenada especificada esta desocupada.
    bool coordenada_es_ocupable(Coordenada &coordenada);
    //Recibe un vector de coordenadas a desocupar y
    //extrae de la celda el elemento(personaje) que la ocupa.
    //No se extraen los elementos propios del mapa que componen
    //la celda como escaleras, puas, obstaculos, etc.
    void desocupar(std::vector<Coordenada*> &coordenadas);
    //Devuelve una referencia al ubicable contenido en
    //una celda del mapa que se corresponde con la coordenada
    //recibida.
    Ubicable& obtener_ubicable(Coordenada &coordenada);
  private:
    //TODO: void cargar();
};

#endif //MAPA_H
