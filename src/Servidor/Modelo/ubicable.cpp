#include "ubicable.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

bool Ubicable::colisiona(Ubicable* otro_ubic, Coordenada nueva){
  int alto1 = this->get_alto();
  int ancho1 = this->get_ancho();
  int alto2 = otro_ubic->get_alto();
  int ancho2 = otro_ubic->get_ancho();

  int y1 = this->get_coordenada().arriba(alto1/2).obtener_ordenada();
  int x1 = this->get_coordenada().izquierda(ancho1/2).obtener_abscisa();
  int y2 = nueva.arriba(alto2/2).obtener_ordenada();
  int x2 = nueva.izquierda(ancho2/2).obtener_abscisa();

  int x_aux = std::min(x1+ancho1, x2+ancho2) - std::max(x1, x2);
  int y_aux = std::min(y1+alto1, y2+alto2) - std::max(y1,y2);
  size_t x_colision = std::max(0, x_aux);
  size_t y_colision = std::max(0, y_aux);
  return ((x_colision*y_colision) != 0);
}

int Ubicable::construir_id_unico(int tipo, int id){
	std::stringstream converter;
	converter << tipo << id;
	std::string id_pj = converter.str();
	int id_unico = atoi(id_pj.c_str());
	return id_unico;
}

int Ubicable::get_id_unico(){
	return construir_id_unico(this->get_tipo(), this->get_id());
}
