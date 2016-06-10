#include "elemento.h"

Elemento::Elemento(Coordenada c, int tipo, int id):
coord(c), tipo(tipo), id(id){}

int Elemento::get_tipo(){
	return tipo;
}

int Elemento::get_id(){
	return id;
}

int Elemento::get_ancho(){
	return ancho;
}

int Elemento::get_alto(){
	return alto;
}

Coordenada Elemento::get_coordenada(){
	return coord;
}
