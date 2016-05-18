#include "mapa.h"

Mapa::Mapa(){
  //mapa.cargar();
}

void Mapa::ocupar(size_t x, size_t y, Ubicable nuevo_ubicable){
  Celda posicion = celdas[x][y];
  posicion.ocupar(nuevo_ubicable);
}

void Mapa::desocupar(size_t x, size_t y){
  Celda posicion = celdas[x][y];
  celda.desocupar();
}

Ubicable Mapa::obtener_ubicable(size_t x, size_t y){
  Celda posicion = celdas[x][y];
  return posicion.obtener_ubicable();
}
