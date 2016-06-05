#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "coordenada.h"
#include "ubicable.h"

class Elemento;
class Personaje;

class Elemento: 
public Ubicable{
	protected:
		Coordenada coord;
		int ancho;
		int alto;
		int tipo;
		int id;
	public:
		Elemento(Coordenada c, int tipo, int id = 0);
		//Dado un personaje, interactua con el mismo.
		virtual void interactuar(Personaje *pj) = 0;
		//Devuelve todas las coordenadas que ocupa un elemento.
		virtual std::vector<Coordenada> coordenadas() = 0;
		std::vector<Coordenada> coordenadas(Coordenada c) = 0;
		//Devuelve la coordenada central del elemento.
		virtual Coordenada get_coordenada();
		//Devuelve un entero que representa el tipo de elemento.
		virtual int get_tipo();
		//Devuelve un entero que identifica al elemento dentro
		//de su tipo.
		virtual int get_id();
		//Devuelve el ancho del elemento.
		virtual int get_ancho();
		//Devuelve el alto del elemento.
		virtual int get_alto();
};

#endif //ELEMENTO_H
