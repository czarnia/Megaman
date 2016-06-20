#ifndef UBICABLE_H
#define UBICABLE_H
#include "observable.h"
#include "coordenada.h"
#include "observador_ubicable.h"

class Observador_ubicable;
class Personaje;
class Elemento;
class Bala;
class Bala_normal;
class Bala_minion;
class Bala_bombman;
class Bala_fireman;
class Bala_magnetman;
class Bala_ringman;
class Bala_sparkman;
class Escalera;
class Bloque;
class Puas;
class Premio;

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
		//Dado un premio, dice si el mismo puedo ubicarse en una posicion donde
		//esta el ubicable.
		virtual bool puede_ocupar(Premio* premio) = 0;
		//Agrega un observador a la lista de observadores del ubicable.
		//virtual void agregar_observador(Observador_ubicable *observador) = 0;
		//Remueve un observador de la lista de observadores del ubicable.
		//virtual void quitar_observador(Observador_ubicable *observador) = 0;
		//Devuelve la coordenada central del ubicable.
		virtual Coordenada get_coordenada() = 0;
		//Devuelve un entero que representa el tipo de ubicable.
		virtual int get_tipo() = 0;
		//Devuelve un entero que identifica al ubicable dentro
		//de su tipo.
		virtual int get_id() = 0;
		//Devuelve un id unico que se obtiene concatenando
		//id con tipo del ubicable.
		virtual int get_id_unico();
		//Devuelve el ancho del ubicable.
		virtual int get_ancho() = 0;
		//Devuelve el alto del ubicable.
		virtual int get_alto() = 0;
		//Dado un id y un tipo
		//devuelve un id unico.
		static int construir_id_unico(int tipo, int id);
		//Destructor del ubicable.
		//virtual ~Ubicable() {}
		virtual bool colisiona(Ubicable* otro_ubic, Coordenada nueva);
		//Dada una bala, dice si la misma le hace danio.
		virtual bool recibe_danio(Bala* ataque) = 0;
};

#endif //UBICABLE_H
