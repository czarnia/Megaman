#ifndef PERSONAJE_NPC_H
#define PERSONAJE_NPC_H

class Escaleras;

#include "personaje.h"

class Personaje_npc: public Personaje{
	protected:
		Vida vida;
		bool activo;
	public:
		//Crea a un personaje npc, por definicion, todos se crean desactivados.
		Personaje_npc(Mapa *mapa, Coordenada c, int id):
		Personaje(mapa, c, id){ activo = false;}
		//Dado un porcentaje de vida a perder, se la resta al personaje,
		//en caso de ser -100 (por defecto) una vida completa.
		virtual void perder_vida(int porcentaje = PERDER_MAX);
		//Dado un porcentaje de vida a ganar, se la suma al personaje,
		//en caso de ser 100 (por defecto) una vida completa.
		virtual void ganar_vida(int porcentaje = GANAR_MAX);
		//Devuelve true si el personaje esta vivo.
		virtual bool esta_vivo();
		//Devuelve el porcentaje de vida del personaje.
		virtual int get_porcentaje_vida();
		//Activa a un npc.
		virtual void activar() { activo = true; }
		//Desactuva a un npc.
		virtual void desactivar() { activo = false; }
};

#endif //PERSONAJE_NPC_H
