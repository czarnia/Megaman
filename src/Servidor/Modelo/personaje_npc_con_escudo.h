#ifndef PERSONAJE_NPC_CON_ESCUDO_H
#define PERSONAJE_NPC_CON_ESCUDO_H

#include "personaje_npc.h"

class Personaje_npc_con_escudo: 
public Personaje_npc{
	public:
		Personaje_npc_con_escudo(Mapa *mapa, Coordenada c, int id):
		Personaje_npc(mapa, c, id){}
		//Devuelve true si el personaje no
		//esta bajo la proteccion de su escudo.
		virtual bool esta_bajo_escudo() = 0;
};

#endif //PERSONAJE_NPC_CON_ESCUDO_H

