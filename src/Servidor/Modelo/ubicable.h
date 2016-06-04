#ifndef UBICABLE_H
#define UBICABLE_H
#include "observable.h"
#include "coordenada.h"

class Observador_ubicable;
class Personaje;
class Elemento;
class Bala;
class Escalera;
class Bloque;
class Puas;
class Puas_asesinas;

class Ubicable:
public Observable{
	public:
		//Devuelve la coordenada central de un ubicable.
		//virtual Coordenada devolver_coordenada_central() = 0;
    //Devuelve todas las coordenadas que ocupa un ubicable.
    virtual std::vector<Coordenada> coordenadas() = 0;
    //Devuelve todas las coordenadas que ocuparía un ubicable si su centro estuvie-
    //ra en c.
    virtual std::vector<Coordenada> coordenadas(Coordenada c) = 0;
		//Dado un ubicable, dice si el mismo puedo ubicarse en una posicion donde
		//hay un otro ubicable.
		virtual bool puede_ocupar(Ubicable* ubic) = 0;
		//Dado un personaje, dice si el mismo puedo ubicarse en una posicion donde
		//hay un ubicable.
		virtual bool puede_ocupar(Personaje* pj) = 0;
		//Dado un elemento, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Elemento* elem) = 0;
		//Dada una bala, dice si la misma puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Bala* bala) = 0;
		//Dada una escalera, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Escalera* esc) = 0;
		//Dada una escalera, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Bloque* bloque) = 0;
		//Dadas unas puas, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Puas* puas) = 0;
		//Dadas unas puas_asesinas, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Puas_asesinas* puas) = 0;

		virtual void agregar_observador(Observador_ubicable *observador) = 0;
		virtual void quitar_observador(Observador_ubicable *observador) = 0;
		virtual Coordenada get_coordenada() = 0;
		virtual int get_tipo() = 0;
		virtual int get_id() = 0;

		//virtual int devolver_ancho() = 0;
		//virtual int devolver_alto() = 0;

		//Destructor del ubicable.
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
