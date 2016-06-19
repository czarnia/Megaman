#ifndef PUERTA_BOSS_H
#define PUERTA_BOSS_H

#include "elemento.h"
#include "observador_personaje_pc.h"

class Observador_personaje_pc;

class Puerta_boss : 
public Elemento,
public Observador_personaje_pc{
	private:
		bool abierta;
		//Cantidad de personajes pc que pasaron por la puerta:
		unsigned int cantidad_personajes;
		//Ids de los personajes pc existentes en el mapa:
		std::vector<int> ids_personajes_pc;
	public:
		//Dada una Coordenada, un tipo y un id, crea una Puerta_boss.
		Puerta_boss(Coordenada c, int id = 0);
		//Dado un personaje, interactua con el mismo.
		virtual void interactuar(Personaje *pj);
		//Devuele true si el elementos actua como piso, false en caso contrario
		virtual bool es_piso();
		//Devuelve false si el personaje quiere pasar a la cueva 
		//del boss y true si quiere salir.
		virtual bool colisiona(Ubicable* otro_ubic, Coordenada nueva);
		//Suma 1 a la cantidad actual de personajes
		//a considerar para cerrar la puerta.
		virtual void sumar_personaje(int id_pj);
		//Resta 1 a la cantidad actual de personajes
		//a considerar para cerrar la puerta.
		virtual void restar_personaje(int id_pj);
	
		//Dado un observable, actualiza su estado.
		virtual void update(Observable *obs);
		//Dado un ubicable, dice si el mismo puedo ubicarse en una posicion donde
		//hay un otro ubicable.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Dado un personaje, dice si el mismo puedo ubicarse en una posicion donde
		//hay un ubicable.
		virtual bool puede_ocupar(Personaje* pj);
		//Dado un elemento, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Elemento* elem);
		//Dada una bala, dice si la misma puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Bala* bala);
		//Dada una escalera, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Escalera* esc);
		//Dada una escalera, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Puas* puas);
		//Dado un premio, dice si el mismo puedo ubicarse en una posicion donde
		//esta el ubicable.
		virtual bool puede_ocupar(Premio* premio);
};

#endif //PUERTA_BOSS_H

