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
		Coordenada coord;
	public:
		//Dada una direccion en x, una en y (hacia donde se movera) y una coordenada
		//inicial, crea una bala.
		Bala(int dir_x, int dir_y, Coordenada c): direccion_x(dir_x),
		direccion_y(dir_y), coord(c){}
		//Destructor de la bala.
		virtual ~Bala() {};
		//Dado un personaje y un mapa, interactua con el personaje.
		virtual void interactuar(Personaje* pj);
		//Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Personaje* pj);
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
