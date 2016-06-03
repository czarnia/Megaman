#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "coordenada.h"
#include "ubicable.h"

class Personaje;

class Elemento : public Ubicable{
	protected:
		Coordenada coord;
		size_t ancho;
		size_t alto;
	public:
		Elemento(Coordenada c) : coord(c) {};
		//Dado un personaje, interactua con el mismo.
		virtual void interactuar(Personaje *pj) = 0;
		//Dado un ubicable, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Ubicable* ubic) = 0;
		//Devuelve todas las coordenadas que ocupa un elemento.
		virtual std::vector<Coordenada> coordenadas() = 0;
		std::vector<Coordenada> coordenadas(Coordenada c) = 0;
};

#endif //ELEMENTO_H
