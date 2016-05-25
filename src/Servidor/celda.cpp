#include "celda.h"

Celda::Celda(size_t x, size_t y){
	coordenadas = new Coordenada(x,y);
}

Coordenada Celda::celda_derecha(){
	return coordenadas->derecha();
}

Coordenada Celda::celda_izquierda(){
	return coordenadas->izquierda();
}

Coordenada Celda::celda_arriba(){
    return coordenadas->arriba();
}

Coordenada Celda::celda_abajo(){
    return coordenadas->abajo();
}

Coordenada Celda::celda_diagonal_derabajo(){
    return coordenadas->derecha().abajo();
}

Coordenada Celda::celda_diagonal_derarriba(){
    return coordenadas->derecha().arriba();
}

Coordenada Celda::celda_diagonal_izqabajo(){
    return coordenadas->izquierda().abajo();
}

Coordenada Celda::celda_diagonal_izqarriba(){
    return coordenadas->izquierda().arriba();
}

Celda::~Celda(){}

