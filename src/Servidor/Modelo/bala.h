#ifndef BALA_H
#define BALA_H

#include "actualizable.h"
#include "elemento.h"

class Met;
class Megaman;
class Bumby;
class Snipper;
class Jumping_snipper;
class Personaje;

class Bala:
public Actualizable,
public Elemento{
	protected:
		int direccion_x;
		int direccion_y;
		size_t tiempo_pasado;
		bool impacto;
	public:
		//Dada una direccion en x, una en y (hacia donde se movera) y una coordenada
		//inicial y un id, crea una bala.
		Bala(int dir_x, int dir_y, Coordenada c, int tipo, int id);
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
		//Dado un Premio, devuelve true si el premio puede ubicarse
		//en las mismas coordenadas que este elemento.
		virtual bool puede_ocupar(Premio* premio);
		//Devuele true si el elemento actua como piso, false en caso contrario
		virtual bool es_piso();
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//esta.
		virtual bool puede_ocupar(Puas* puas);
		//Hace que pasa el tiempo para la bala.
		virtual void update(float tiempo, Mapa* mapa) = 0;
		//Daña a un Personaje (caso por defecto).
		virtual void daniar(Personaje* pj) = 0;
		//Daña a un Megaman.
		virtual void daniar(Megaman* mega) = 0;
		//Daña a un Met.
		virtual void daniar(Met* met) = 0;
		//Daña a un Bumby.
		virtual void daniar(Bumby* b) = 0;
		//Daña a un Sniper.
		virtual void daniar(Snipper* s) = 0;
		//Daña a un Jumping_sniper.
		//virtual void daniar(Jumping_snipper* js) = 0;
		//Devuelve true si puede dañar a un Met cuando esta tras su escudo, false en
		//caso contrario.
		virtual bool dania_con_escudo(Met* m) = 0;
		//Devuelve true si puede dañar a un Snipper cuando esta tras su escudo, fal-
		//se en caso contrario.
		virtual bool dania_con_escudo(Snipper* s) = 0;
		//Devuelve true si puede dañar a un Jumping_snipper cuando esta tras su es-
		//cudo, false en caso contrario.
		virtual bool dania_con_escudo(Jumping_snipper* js) = 0;
};

#endif //BALA_H
