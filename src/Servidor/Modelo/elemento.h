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
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
		//estas.
		bool puede_ocupar(Ubicable* ubic);
		//Devuelve todas las coordenadas que ocupa un elemento
		//tomando como referencia la coordenada central del mismo.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía un 
		//elemento si su centro estuviera en c.
		std::vector<Coordenada> coordenadas(Coordenada c);
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
		//Notifica a todos sus observadores de un cambio en su estado.
		virtual void notificar_observadores();
		//Dado un observador_ubicable*, lo agrega a sus observadores.
		virtual void agregar_observador(Observador_ubicable *observador);
		//Dado un observador_ubicable*, lo quita de sus observadores.
		virtual void quitar_observador(Observador_ubicable *observador);
};

#endif //ELEMENTO_H
