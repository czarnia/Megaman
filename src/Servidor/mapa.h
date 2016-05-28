#ifndef MAPA_H
#define MAPA_H

#include <map>
#include <vector>
#include "coordenada.h"

class Elemento;

class Mapa{
  private:
    std::vector<Coordenada> bloques;
    size_t tam;
  public:
    //Dado un tamanio, crea un mapa
    //con tantas divisiones como indique el tamanio.
    Mapa(size_t tamanio);
    bool tiene_coordenada(Coordenada coordenada);
    bool puede_ubicarse_en(Coordenada *coord, size_t alto, size_t ancho);
    void puede_moverse_a(Coordenada *origen, Coordenada *destino, size_t alto, size_t ancho);
  private:
    //Carga un mapa, por ahora, una versión por defecto chica.
    void cargar();
    //Recibe un elemento y las coordenadas donde se desea posicionar al mismo.
    void ocupar_elemento(Elemento& elem, std::vector<Coordenada> &coordenadas);
    //Recibe un vector con coordenadas de donde se quieran agregar las celdas;
    void ocupar_tierra(std::vector<Coordenada> &coordenadas);
    void ocupar_personajes(std::vector<Coordenada*> &coordenadas);
    //Inicializa las celdas aereas del mapa:
    void rellenar_aire();
};

#endif //MAPA_H
