#ifndef BALA_H
#define BALA_H

#include "actualizable.h"
#include "elemento.h"
#include "personaje.h"
class Met;
class Megaman;
//class Personaje;

class Bala:
public Actualizable,
public Elemento{
	protected:
		int direccion_x;
		int direccion_y;
		size_t tiempo_pasado;
	public:
		//Dada una direccion en x, una en y (hacia donde se movera) y una coordenada
		//inicial, crea una bala.
		Bala(int dir_x, int dir_y, Coordenada c): Elemento(c), direccion_x(dir_x),
		direccion_y(dir_y) {}
		//Destructor de la bala.
		virtual ~Bala() {};
		//Dado un personaje y un mapa, interactua con el personaje.
		virtual void interactuar(Personaje* pj);
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Personaje* pj);
		//Dado un elemento, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Elemento* pj);
		//Dada una bala, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Bala* bala);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Escalera* esc);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Puas* puas);
		//Dadas unas puas_asesinas, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Puas_asesinas* puas);
		//Devuelve todas las coordenadas que ocupa una bala.
		virtual std::vector<Coordenada> coordenadas();
		//Devuelve todas las coordenadas que ocuparía una bala si su centro estuvie-
		//ra en c.
		virtual std::vector<Coordenada> coordenadas(Coordenada c);
		//Hace que pasa el tiempo para la bala.
		virtual void update(size_t tiempo, Mapa* mapa) = 0;
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj) = 0;
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega) = 0;
		//Daña a un Met.
		virtual void daniar(Met* met) = 0;
};

#endif //BALA_H
