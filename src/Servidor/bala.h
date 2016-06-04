#ifndef BALA_H
#define BALA_H

#include "actualizable.h"
#include "elemento.h"
#include "personaje.h"
#include "ubicable.h"
#include "observador_ubicable.h"

class Met;
class Megaman;
class Personaje;
class Elemento;
class Observador_ubicable;

class Bala:
public Actualizable,
public Elemento,
public Ubicable{
	protected:
		int direccion_x;
		int direccion_y;
		size_t tiempo_pasado;
		Coordenada coord;
		int id;
		int tipo;
	public:
		//Dada una direccion en x, una en y (hacia donde se movera) y una coordenada
		//inicial, crea una bala.
		Bala(int dir_x, int dir_y, Coordenada c, int id);
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
		//Devuelve la coordenada actual de la bala.
		virtual Coordenada get_coordenada();
		//Devuelve el id de la bala.
		int get_id();
		//Devuelve el id de la bala.
		int get_tipo();
		//Recibe un observador de ubicables y lo agrega a
		//la lista de ubicables:
		void agregar_observador(Observador_ubicable *observador);
		//Recibe un puntero a observador de ubicables 
		//y lo remueve de la lista de ubicables:
		void quitar_observador(Observador_ubicable *observador);
		//Notifica a sus observadores de un cambio de estado.
		virtual void notificar_observadores();
};

#endif //BALA_H
