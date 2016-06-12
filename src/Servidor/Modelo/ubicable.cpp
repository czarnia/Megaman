#include "ubicable.h"

bool Ubicable::colisiona(Ubicable* otro_ubic){
  int alto1 = this->get_alto();
  int ancho1 = this->get_ancho();
  int alto2 = otro_ubic->get_alto();
  int ancho2 = otro_ubic->get_ancho();

  int y1 = this->get_coordenada().arriba(alto1/2).obtener_ordenada();
  int x1 = this->get_coordenada().izquierda(ancho1/2).obtener_abscisa();
  int y2 = otro_ubic->get_coordenada().arriba(alto2/2).obtener_ordenada();
  int x2 = otro_ubic->get_coordenada().izquierda(ancho2/2).obtener_abscisa();

  int x_aux = std::min(x1+ancho1, x2+ancho2) - std::max(x1, x2);
  int y_aux = std::min(y1+alto1, y2+alto2) - std::max(y1,y2);
  size_t x_colision = std::max(0, x_aux);
  size_t y_colision = std::max(0, y_aux);
  return ((x_colision*y_colision) != 0);
}
